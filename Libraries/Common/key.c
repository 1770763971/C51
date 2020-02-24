/**************************************************************************************
*		              矩阵按键实验												  *
实现现象：下载程序后数码管显示0，按下矩阵按键上的按键显示对应的数字
			S1-S4：0-3
			S5-S8：4-7
			S9-S12：8-B
			S13-S16：C-F。
注意事项：如果不想让点阵模块显示，可以将74HC595模块上的JP595短接片拔掉。																				  
***************************************************************************************/
#include "common.h"
#include "variable.h"
#include "delay.h"
#include "key.h"

extern u8 KeyValue;

extern u8 code smgduan[17];

/*******************************************************************************
* 函 数 名         : KeyDown
* 函数功能		   : 检测有按键按下并读取键值
* 输    入         : 无
* 输    出         : 无
可以用定时器中断检测按键，得到按键值
*******************************************************************************/
void KeyDown(void)
{
	char a=0;
	GPIO_KEY=0x0f;
	if(GPIO_KEY!=0x0f)//读取按键是否按下
	{
		delay(1000);//延时10ms进行消抖
		if(GPIO_KEY!=0x0f)//再次检测键盘是否按下
		{	
			//测试列
			GPIO_KEY=0X0F;
			switch(GPIO_KEY)
			{
				case(0X07):	KeyValue=0;break;
				case(0X0b):	KeyValue=1;break;
				case(0X0d): KeyValue=2;break;
				case(0X0e):	KeyValue=3;break;
			}
			//测试行
			GPIO_KEY=0XF0;
			switch(GPIO_KEY)
			{
				case(0X70):	KeyValue=KeyValue;break;
				case(0Xb0):	KeyValue=KeyValue+4;break;
				case(0Xd0): KeyValue=KeyValue+8;break;
				case(0Xe0):	KeyValue=KeyValue+12;break;
			}
			while((a<50)&&(GPIO_KEY!=0xf0))	 //检测按键松手检测
			{
				delay(1000);
				a++;
			}
		}
	}
}


/*******************************************************************************
* 函 数 名       : main
* 函数功能		 : 主函数
* 输    入       : 无
* 输    出    	 : 无
* 说明 复制按键实验，直接调用该函数能用数码管显示键值
*******************************************************************************/
void ke()
{	
	LSA=0; //给一个数码管提供位选
	LSB=0;
	LSC=0;
	while(1)
	{	
		KeyDown();		   //按键判断函数
				GPIO_DIG=smgduan[KeyValue];	  //
	}		
}
