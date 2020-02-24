/*********************************************************************************
 * File:     Main.c
 * Author:   Mo
 * Date 	 : 2020.02.21
 * Describe: Main function in it 
 * 
**********************************************************************************/  	

#include "Main.h"

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

void main(void)
{
	Int0Init();  //	Set external intertupt 0
	while(1)
	{
		led = ~led;
	}
	
}

