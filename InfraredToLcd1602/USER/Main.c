/*********************************************************************************
 * @File:     Main.c
 * @Author:   Mo
 * @Date 	 : 2020.02.21
 * @Describe: Main function in it 
 * 
**********************************************************************************/  	

#include "Main.h"

sbit IRIN=P3^2;

 u8 IrValue[6];
unsigned char code CDIS1[13]={" Red Control "};
unsigned char code CDIS2[13]={" IR-CODE:--H "};
//unsigned char IrValue[6];
unsigned char Time;

extern u8 KeyValue;	//Using to do save the key value. 

extern uchar code IC_DAT[];
extern uchar code IC_DAT2[];
extern unsigned char code zk[];
extern unsigned char code pic2[];
extern unsigned char code BMP1[];
extern unsigned char code BMP[];
extern unsigned char code zk[];

sbit k1=P3^1;	 //定义P31口是k1
sbit led=P2^0;	 //定义P20口是led

/*******************************************************************************
*@brief         Main function
*@param         null
*@return        0
*@since         v1.0
*@SampleUsage:  mian
*******************************************************************************/
u8 Disp[]=" Pechin Science ";

uchar code table[] = {
0x00,0x00,0x00,0x1F,0x00,0x00,0x00,0x00,//一
0x00,0x00,0x0E,0x00,0x1F,0x00,0x00,0x00,//二
0x00,0x1F,0x00,0x0E,0x00,0x1F,0x00,0x00,//三
0x02,0x04,0x0F,0x12,0x0F,0x0A,0x1F,0x02,//年
0x0F,0x09,0x0F,0x09,0x0F,0x09,0x09,0x11,//月
0x1F,0x11,0x11,0x1F,0x11,0x11,0x1F,0x00,//日
0x00,0x00,0x00,0x0A,0x15,0x0A,0x04,0x00,//心型
0x00,0x04,0x15,0x0E,0x1F,0x0E,0x11,0x00//坦克
};
uchar code table1[] = { 0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07 };  //自定义字符数据地址
uchar code table2[] = "QQ:598852247";


void Sys_init_all()
{
	Lcd1602_Init();
//	UsartInit();
//	Int0Init();
//	Timer0Init();
//	Int1Init();
//	Timer1Init();
}

void main()
{
	unsigned char i;
	IrInit();	
	Lcd1602_Init();
	LcdWriteCom(0x80);
	for(i=0;i<13;i++)
	{
		LcdWriteData(CDIS1[i]);	
	}
	LcdWriteCom(0x80+0x40);
	for(i=0;i<13;i++)
	{
		LcdWriteData(CDIS2[i]);	
	}
	while(1)
	{
		IrValue[4]=IrValue[2]>>4;	 	 	//高位
		IrValue[5]=IrValue[2]&0x0f;		//低位	
		if(IrValue[4]>9)
		{
			LcdWriteCom(0xc0+0x09);			//设置显示位置
			LcdWriteData(0x37+IrValue[4]);	//将数值转换为该显示的ASCII码
		}
		else
		{
			LcdWriteCom(0xc0+0x09);
			LcdWriteData(IrValue[4]+0x30);	//将数值转换为该显示的ASCII码
		}	
		if(IrValue[5]>9)
		{
			LcdWriteCom(0xc0+0x0a);
			LcdWriteData(IrValue[5]+0x37);		//将数值转换为该显示的ASCII码
		}
		else
		{
			LcdWriteCom(0xc0+0x0a);
			LcdWriteData(IrValue[5]+0x30);		//将数值转换为该显示的ASCII码
		}	
	}
}	