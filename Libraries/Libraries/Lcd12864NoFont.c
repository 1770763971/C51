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
/*ȫ����ʾͼƬ*/
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
��������:LCD��ʱ����
��ڲ���:t
���ڲ���:
****************************************************************************/
void LCDdelay(unsigned int t)
{
	unsigned int i,j;
	for(i=0;i<t;i++);
	for(j=0;j<10;j++);
}
/****************************************************************************
״̬��飬LCD�Ƿ�æ

*****************************************************************************/
void CheckState()		
{
   unsigned char dat,DATA_1;//״̬��Ϣ���ж��Ƿ�æ��
   LCDDi=0; // ����\ָ��ѡ��D/I��RS��="L" ����ʾ DB7��DB0 Ϊ��ʾָ������ 
   LCDRW=1; //R/W="H" ��E="H"���ݱ�����DB7��DB0 
   do
   {
      DATA_1=0x00;
      LCDEnable=1;	//EN�½�Դ
	  LCDdelay(2);//��ʱ
	  dat=DATA_1;
      LCDEnable=0;
      dat=0x80 & dat; //������7λΪ0ʱ�ſɲ���(�б�busy�ź�)
    }
    while(!(dat==0x00));
}
/*****************************************************************************
��������:д���LCD����RS(DI)=L,RW=L,EN=H������һ������дһ��
��ڲ���:cmdcode
���ڲ���:
*****************************************************************************/
void write_com(unsigned char cmdcode)
{
    CheckState();//���LCD�Ƿ�æ
	LCDDi=0;
	LCDRW=0;
	P1=cmdcode;		
	LCDdelay(2);
	LCDEnable=1;
	LCDdelay(2);
	LCDEnable=0;
}
/*****************************************************************************
��������:LCD��ʼ������
��ڲ���:
���ڲ���:
*****************************************************************************/
void init_lcd()
{
	LCDdelay(100);	
	LCDMcs=1;//�տ�ʼ�ر�����
	LCDScs=1;
	LCDdelay(100);
	write_com(LCDLCDDisp_Off);	 //д��ʼ������
	write_com(Page_Add+0);
	write_com(Start_Line+0);
	write_com(LCDCol_Add+0);
	write_com(LCDLCDDisp_On);
}
/*****************************************************************************
��������:д���ݵ�LCD����RS(DI)=H,RW=L,EN=H������һ������дһ��
��ڲ���:LCDDispdata
���ڲ���:
*****************************************************************************/
void write_data(unsigned char LCDDispdata)
{
    CheckState();//���LCD�Ƿ�æ
	LCDDi=1;
	LCDRW=0;
	P1=LCDDispdata;
	LCDdelay(2);
	LCDEnable=1;
	LCDdelay(2);
	LCDEnable=0;
}
/*****************************************************************************
��������:���LCD�ڴ����
��ڲ���:pag,col,hzk
���ڲ���:
*****************************************************************************/
void Clr_Scr()
{
	unsigned char j,k;
	LCDMcs=0; //������������ʾ
	LCDScs=0;
 	write_com(Page_Add+0);
 	write_com(LCDCol_Add+0);
 	for(k=0;k<8;k++)//����ҳ��0-7����8ҳ
 	{
		write_com(Page_Add+k); //ÿҳÿҳ����д
  		for(j=0;j<64;j++)  //ÿҳ����д32���������ֻ�64��ASCII�ַ�
		{
      		write_com(LCDCol_Add+j);
			write_data(0x00);//��������0-63����64�У�д�����ݣ��е�ַ�Զ���1
		}
	}
}
/*****************************************************************************
��������:����λ����ʾ
��ڲ���:page,column,hzk
���ڲ���:
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
��������:����λ����ʾ
��ڲ���:page,column,hzk
���ڲ���:
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
��������:ָ��λ����ʾ����16*16����
��ڲ���:page,column,hzk
���ڲ���:
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
��������:һ��һ����ʾ
��ڲ���:page,column,hzk
���ڲ���:
*****************************************************************************/
void Disp(uchar page,uchar column, uchar code *word)
{
uchar i;
//����
LCDMcs=0; 
LCDScs=1;
//�ϰ���
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
//�°���
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
//����
LCDMcs=1; 
LCDScs=0;
//�ϰ���
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
//�°���
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




