/*********************************************************************************
 * @File:     Main.c
 * @Author:   Mo
 * @Date 	 : 2020.02.21
 * @Describe: Main function in it 
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

void main(void)
{
    u8 i;
	Sys_init_all(); //All initialization function
//	Int0Init();  //	Set external intertupt 0

    while (1)
    {
        LcdWriteCom(0x40);    //开始写入你要显示的自定义字符、汉字代码
        for (i = 0;i < 64;i++)
        {
            LcdWriteData(table[i]);
            delay(5);
        }
        LcdWriteCom(0x80);    //从第一行第一列开始显示
        for (i = 0;i < 8;i++)     //显示自定义字符
        {
            LcdWriteData(table1[i]);
            delay(5);
        }
        LcdWriteCom(0xc0);   //显示QQ：598852247
        for (i = 0;i < 12;i++)
        {
            LcdWriteData(table2[i]);
            delay(5);
        }
    }

}

