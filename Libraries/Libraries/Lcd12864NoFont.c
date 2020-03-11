#include <reg51.h>
#include "delay.h"
#include "Lcd12864NoFont.h"
#include "PictureForLcd12864NoFont.h"
 


void Write(uchar dat,bit type)
{
   lcmen=0;
   lcmrw=0;
   lcmrs=type;
   P1=dat;
   Delay(5);
   lcmen=1;
   lcmen=1;
   Delay(1);
   lcmen=0;
}
void Cls()
{
  uchar i,j;
  All();
  for(i=0;i<8;i++)
  {
  	Write(0xB8|i,CMD);
	Write(0x40,CMD);
	for(j=0;j<64;j++)
  	Write(0x00,DATA);
   }
}
/*全屏显示图片*/
void LCDDisplay(uchar line,uchar row, uchar table[7][128])
{
   uchar i,j;
 for(i=0;i<8;i++)
 { 
      if(row<0x80)
      { 
        Left();
        }
   Write(line+i,CMD);
   Write(row,CMD);
   for(j=0;j<64;j++)
    {    
     Write(table[i][j],DATA);
     row+=1;
     }
   if(row>=0x80)
    {
      Right();
      row=row-64;
      }
    Write(line+i,CMD);
    Write(row,CMD);
    for(j=64;j<128;j++)
     {
       Write(table[i][j],DATA);
       row+=1;
       }
      if(row>=0x80)
        {
         row=row-0x40;
         }
    }
}		  
void Init()
{
  Cls();
  Write(0x3F,CMD);
  Write(0xC0,CMD);
  Write(0xB8,CMD);
  Write(0x40,CMD);
}


/****************************************************************************
函数功能:LCD延时程序
入口参数:t
出口参数:
****************************************************************************/
void LCDdelay(unsigned int t)
{
	unsigned int i,j;
	for(i=0;i<t;i++);
	for(j=0;j<10;j++);
}
/****************************************************************************
状态检查，LCD是否忙

*****************************************************************************/
void CheckState()		
{
   unsigned char dat,DATA_1;//状态信息（判断是否忙）
   LCDDi=0; // 数据\指令选择，D/I（RS）="L" ，表示 DB7∽DB0 为显示指令数据 
   LCDRW=1; //R/W="H" ，E="H"数据被读到DB7∽DB0 
   do
   {
      DATA_1=0x00;
      LCDEnable=1;	//EN下降源
	  LCDdelay(2);//延时
	  dat=DATA_1;
      LCDEnable=0;
      dat=0x80 & dat; //仅当第7位为0时才可操作(判别busy信号)
    }
    while(!(dat==0x00));
}
/*****************************************************************************
函数功能:写命令到LCD程序，RS(DI)=L,RW=L,EN=H，即来一个脉冲写一次
入口参数:cmdcode
出口参数:
*****************************************************************************/
void write_com(unsigned char cmdcode)
{
    CheckState();//检测LCD是否忙
	LCDDi=0;
	LCDRW=0;
	P1=cmdcode;		
	LCDdelay(2);
	LCDEnable=1;
	LCDdelay(2);
	LCDEnable=0;
}
/*****************************************************************************
函数功能:LCD初始化程序
入口参数:
出口参数:
*****************************************************************************/
void init_lcd()
{
	LCDdelay(100);	
	LCDMcs=1;//刚开始关闭两屏
	LCDScs=1;
	LCDdelay(100);
	write_com(LCDLCDDisp_Off);	 //写初始化命令
	write_com(Page_Add+0);
	write_com(Start_Line+0);
	write_com(LCDCol_Add+0);
	write_com(LCDLCDDisp_On);
}
/*****************************************************************************
函数功能:写数据到LCD程序，RS(DI)=H,RW=L,EN=H，即来一个脉冲写一次
入口参数:LCDDispdata
出口参数:
*****************************************************************************/
void write_data(unsigned char LCDDispdata)
{
    CheckState();//检测LCD是否忙
	LCDDi=1;
	LCDRW=0;
	P1=LCDDispdata;
	LCDdelay(2);
	LCDEnable=1;
	LCDdelay(2);
	LCDEnable=0;
}
/*****************************************************************************
函数功能:清除LCD内存程序
入口参数:pag,col,hzk
出口参数:
*****************************************************************************/
void Clr_Scr()
{
	unsigned char j,k;
	LCDMcs=0; //左、右屏均开显示
	LCDScs=0;
 	write_com(Page_Add+0);
 	write_com(LCDCol_Add+0);
 	for(k=0;k<8;k++)//控制页数0-7，共8页
 	{
		write_com(Page_Add+k); //每页每页进行写
  		for(j=0;j<64;j++)  //每页最多可写32个中文文字或64个ASCII字符
		{
      		write_com(LCDCol_Add+j);
			write_data(0x00);//控制列数0-63，共64列，写点内容，列地址自动加1
		}
	}
}
/*****************************************************************************
函数功能:左屏位置显示
入口参数:page,column,hzk
出口参数:
*****************************************************************************/
void Bmp_Left_Disp(unsigned char page,unsigned char column, unsigned char code *Bmp)
{
	unsigned char j=0,i=0;
	for(j=0;j<8;j++)
	{
		write_com(Page_Add+page+j);
		write_com(LCDCol_Add+column);
		for(i=0;i<64;i++) 
			write_data(Bmp[128*j+i]);
	}
}
/*****************************************************************************
函数功能:右屏位置显示
入口参数:page,column,hzk
出口参数:
*****************************************************************************/
void Bmp_Right_Disp(unsigned char page,unsigned char column, unsigned char code *Bmp)
{
	unsigned char j=0,i=0;
	for(j=0;j<8;j++)
	{
		write_com(Page_Add+page+j);
		write_com(LCDCol_Add+column);
		for(i=64;i<128;i++) 
			write_data(Bmp[128*j+i]);
	}
}

/*****************************************************************************
函数功能:指定位置显示汉字16*16程序
入口参数:page,column,hzk
出口参数:
*****************************************************************************/
void hz_LCDDisp16(unsigned char page,unsigned char column, unsigned char code *hzk)
{
	unsigned char j=0,i=0;
	for(j=0;j<2;j++)
	{
		write_com(Page_Add+page+j);
		write_com(LCDCol_Add+column);
		for(i=0;i<16;i++) 
			write_data(hzk[16*j+i]);
	}
}

/*****************************************************************************
函数功能:一行一行显示
入口参数:page,column,hzk
出口参数:
*****************************************************************************/
void Disp(uchar page,uchar column, uchar code *word)
{
uchar i;
//左屏
LCDMcs=0; 
LCDScs=1;
//上半字
write_com(0xb8|page);
write_com(0x40|column);
for(i=0;i<16;i++)
write_data(word[i]);
for(i=32;i<48;i++)
write_data(word[i]);
for(i=64;i<80;i++)
write_data(word[i]);
for(i=96;i<112;i++)
write_data(word[i]);
//下半字
write_com(0xb8|page+1);
write_com(0x40|column);
for(i=16;i<32;i++)
write_data(word[i]);
for(i=48;i<64;i++)
write_data(word[i]);
for(i=80;i<96;i++)
write_data(word[i]);
for(i=112;i<128;i++)
write_data(word[i]);
//右屏
LCDMcs=1; 
LCDScs=0;
//上半字
write_com(0xb8|page);
write_com(0x40);
for(i=128;i<144;i++)
write_data(word[i]);
for(i=160;i<176;i++)
write_data(word[i]);
for(i=192;i<208;i++)
write_data(word[i]);
for(i=224;i<240;i++)
write_data(word[i]);
//下半字
write_com(0xb8|page+1);
write_com(0x40);
for(i=144;i<160;i++)
write_data(word[i]);
for(i=176;i<192;i++)
write_data(word[i]);
for(i=208;i<224;i++)
write_data(word[i]);
for(i=240;i<250;i++)
write_data(word[i]);
}




