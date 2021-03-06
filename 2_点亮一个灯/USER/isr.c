//中断函数，中断初始化在底下

#include <Main.h>
#include "isr.h"

sbit k3=P3^2;  //定义按键K3
sbit led=P2^0;	 //定义P20口是led

/*******************************************************************************
* 函 数 名         : Int0()	interrupt 0
* 函数功能		   : 外部中断0的中断函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/

void Int0_IRQ(void)	interrupt 0		//外部中断0的中断函数

{
	delay(1000);	 //延时消抖
	if(k3==0)
	{
		led=~led;
	}
}



/*******************************************************************************
* 函 数 名         : void Timer0() interrupt 1
* 函数功能		   : 定时器0中断函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/

void Timer0_IRQ(void) interrupt 1
{
	
}


/*******************************************************************************
* 函 数 名         : Int1()	interrupt 2
* 函数功能		   : 外部中断1的中断函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/

void Int1_IRQ(void)	interrupt 2		//外部中断1的中断函数
{

}


/*******************************************************************************
* 函 数 名         : void Timer1() interrupt 3
* 函数功能		   : 定时器1中断函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Timer1_IRQ(void) interrupt 3
{

}
/*******************************************************************************
* 函数名         : Usart() interrupt 4
* 函数功能		  : 串口通信中断函数
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/
#define Self_Define_ISP_Download_Command 0x3D		 // 与不断电下载有关,与本程序无关，直接复制到自己的程序中
sfr IAP_CONTR=0xE7;									 // 与不断电下载有关，与本程序无关，直接复制到自己的程序中
void Usart() interrupt 4
{
	unsigned char k=0;
	unsigned int a,b;
	if(RI==1)
	{
		RI=0;
		k=SBUF;
		if(k==Self_Define_ISP_Download_Command)
		{
			for(a=1000;a>0;a--)
				for(b=100;b>0;b--); 
			IAP_CONTR = 0x60;
		}
	}
	else
	{
		TI=0;
	}
}







/*******************************************************************************
* 函 数 名         : Int1Init()
* 函数功能		   : 设置外部中断0
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Int0Init(void)
{
	//设置INT0
	IT0=1;//跳变沿出发方式（下降沿）
	EX0=1;//打开INT0的中断允许。	
	EA=1;//打开总中断	
}


/*******************************************************************************
* 函 数 名         : Timer0Init
* 函数功能		   : 定时器0初始化
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Timer0Init(void)
{
	TMOD|=0X01;//选择为定时器0模式，工作方式1，仅用TR0打开启动。
	TH0=0XFC;	//给定时器赋初值，定时1ms
	TL0=0X18;	
	ET0=1;//打开定时器0中断允许
	EA=1;//打开总中断
	TR0=1;//打开定时器			
}


/*******************************************************************************
* 函 数 名         : Int1Init()
* 函数功能		   : 设置外部中断1
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Int1Init(void)
{
	//设置INT1
	IT1=1;//跳变沿出发方式（下降沿）
	EX1=1;//打开INT1的中断允许。	
	EA=1;//打开总中断	
}



/*******************************************************************************
* 函 数 名         : Timer1Init
* 函数功能		   : 定时器1初始化
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Timer1Init(void)
{
	TMOD|=0X10;//选择为定时器1模式，工作方式1，仅用TR1打开启动。

	TH1=0XFC;	//给定时器赋初值，定时1ms
	TL1=0X18;	
	ET1=1;//打开定时器1中断允许
	EA=1;//打开总中断
	TR1=1;//打开定时器			
}


/*******************************************************************************
* 函数名         :UsartInit()
* 函数功能		   :设置串口
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/
void UsartInit()
{
     TMOD = 0x20;
     SM0=0;
     SM1=1;
	 REN=1;
     TH1 = 0xFd;
     TL1 = 0xFd;
     TR1 = 1;
	 EA=1;
	 ES=1;
}

