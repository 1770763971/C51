#include "common.h"
#include "variable.h"
#include "delay.h"
#include "show.h"
#include "lcd12864.h"

extern uchar code IC_DAT[];
extern uchar code IC_DAT2[];
extern unsigned char code zk[];
extern unsigned char code pic2[];
extern unsigned char code BMP1[];
extern unsigned char code BMP[];
extern unsigned char code zk[];

void chk_busy() 
{  RS=0; 
   RW=1; 
   E=1; 
   Lcd_Bus=0xff; 
   while((Lcd_Bus&0x80)==0x80); 
   E=0; 
} 

/*------------------写命令到LCD------------------------------*/ 
void write_com(unsigned char cmdcode) 
{ 
chk_busy(); 
RS=0; 
RW=0; 
E=1; 
Lcd_Bus=cmdcode; 
delay(5);////////////////////在数据写入的时候加入适当的延时 
E=0; 
delay(5); 
} 
/*----------写数据到LCD--------*/ 
void write_data(unsigned char Dispdata) 
{ 
chk_busy(); 
RS=1; 
RW=0; 
E=1; 
Lcd_Bus=Dispdata; 
delay(5);///////////////////在数据写入的时候加入适当的延时 
E=0; 
delay(5); 
} 
/*----------初始化LCD屏-------------------*/ 
void lcd_init(void)
{  delay(2000); 
   write_com(0x30); 
   delay(10);             //选择基本指令集 
   write_com(0x30);       //选择8bit数据流 
   delay(5); 
   write_com(0x0c);       //开显示(无游标、不反白) 
   delay(10); 
   write_com(0x01);       //清除显示，并且设定地址指针为00H 
   delay(500); 
   write_com(0x06);       //指定在资料的读取及写入时，设定游标的移动方向及指定显示的移位 
   delay(0); 
} 
/*-------自定义一个字符代码(一个星星和月�---------*/ 
void CGRAM() 
{ int i; 
     write_com(0x30);   
     write_com(0x40); 
     for(i=0;i<16;i++) 
     {write_data(zk[i*2]); 
      write_data(zk[i*2+1]); 
      } 
}       
/*------------------显示字符串--------------*/ 
void hzkdis(unsigned char code *s) 
{  while(*s>0) 
   {  write_data(*s); 
      s++; 
      delay(50); 
   } 
} 
/*------------------首屏显示-----------------*/ 
void ceshi() 
{write_com(0x01);//清除显示，并且设定地址指针为00H 
delay(5); 

write_com(0x80);//第一行（如果是地址是：80H，即LCD的第一行的第一个位置显示） 
hzkdis("欢迎使用"); 

write_com(0x90);//第二行（如果是地址是：90H，即LCD的第二行的第一个位置显示） 
hzkdis("厦门智控开发板"); 

write_com(0x88);//第三行（如果是地址是：88H，即LCD的第二行的第一个位置显示） 
hzkdis("TEL15980845601"); 

write_com(0x98);//第四行（如果是地址是：98H，即LCD的第二行的第一个位置显示） 
hzkdis("测试程序"); 


} 
/*------------------显示图片------------------------*/ 
void Disp_Img(unsigned char code *img) 
{  unsigned int j=0; 
   unsigned char x,y,i; 
       for(i=0;i<9;i+=8) 
       for(y=0;y<32;y++)
         for(x=0;x<8;x++) 
         {  write_com(0x36);//功能设置---8BIT控制界面，扩充指令集 
            write_com(y+0x80);        //行地址 
            write_com(x+0x80+i);     //列地址 
            write_com(0x30); 
            write_data(img[j++]); 
            write_data(img[j++]); 
         }   
           
} 
/*------------------清整个GDRAM空间---------------*/ 
void clrgdram() 
{ unsigned char x,y; 
        for(y=0;y<64;y++) 
         for(x=0;x<16;x++) 
         {  write_com(0x34); 
            write_com(y+0x80);        //行地址 
            write_com(x+0x80);     //列地址 
            write_com(0x30); 
            write_data(0x00); 
            write_data(0x00); 
                               } 
   } 
/*------------------整屏写入数据:全亮，或者竖条---------*/ 
void lcdfill(unsigned char disdata) 
{ unsigned char x,y; 
        for(y=0;y<32;y++) 
         for(x=0;x<16;x++) 
         {  write_com(0x36); 
            write_com(y+0x80);        //行地址 
            write_com(x+0x80);     //列地址 
            write_com(0x30); 
            write_data(disdata); 
            write_data(disdata); 
            } 
   write_com(0x34);                             
   write_com(0x36); 
   } 
/*------------------显示横-----------------------------*/ 
void Disp_H_Line() 
{  unsigned char x,y; 
   unsigned char k=0x00;   
       for(y=0;y<32;y++) 
         { k=~k; 
           for(x=0;x<16;x++) 
         {  write_com(0x36); 
            write_com(y+0x80);      //行地址 
            write_com(x+0x80);     //列地址 
            write_com(0x30); 
            write_data(k); 
            write_data(k); 
           }; 
         } 
     write_com(0x34);                           
   write_com(0x36); 
} 
/*------------------显示边框-------------------------------*/ 
void Frame() 
{unsigned char x,y; 
          lcdfill(0x00); 
        for(x=0;x<9;x+=8) 
          for(y=0;y<32;y++) 
           { write_com(0x36); 
            write_com(y+0x80);      //行地址 
            write_com(x+0x80);        //列地址 
            write_com(0x30); 
            write_data(0x80); 
            write_data(0x00); 
           
            write_com(0x36); 
            write_com(y+0x80);      //行地址 
            write_com(x+0x87);        //列地址 
            write_com(0x30); 
            write_data(0x00); 
            write_data(0x01); 
             
            } 
      for(y=0;y<2;y++) 
         for(x=0;x<8;x++) 
           {write_com(0x36); 
            write_com(y*31+0x80);      //行地址 
            write_com(x+0x80+8*y);        //列地址 
            write_com(0x30); 
            write_data(0xff); 
            write_data(0xff); 
           } 
         write_com(0x34); 
         write_com(0x36); 
                    } 

/*------------------在第7列的位置加入两条竖线-------*/ 
void shuxian() 
{ unsigned char x,y; 
     
    for(x=0;x<9;x+=8) 
       for(y=0;y<32;y++) 
          { write_com(0x36); 
            write_com(y+0x80);    //行地址 
            write_com(x+0x86);     //列地址 
            write_com(0x30); 
            write_data(0x00); 
            write_data(0x14); 
          }; 
}     
           
/*------------------清屏命令--------------*/   
void clrscreen() 
{ 
   write_com(0x01); 
   delay(10); 
   } 
   
/*------------------唐诗《静夜思》---------------*/ 
void gushi_display() 
{  write_com(0x30); 
   clrscreen();   
   write_com(0x80+FIRST_ADDR); 
   hzkdis("白日依山尽，"); 
   write_com(0x90+FIRST_ADDR); 
   hzkdis("黄河入海流。"); 
   write_com(0x88+FIRST_ADDR); 
   hzkdis("欲穷千里目，"); 
   write_com(0x98+FIRST_ADDR); 
   hzkdis("更上一层楼。"); 
   write_com(0xb3+FIRST_ADDR); 
   hzkdis("登鹳雀楼"); 
   write_com(0xaa+FIRST_ADDR); 
   hzkdis("( 唐 )王之焕"); 
} 
