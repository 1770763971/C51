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

/*------------------д���LCD------------------------------*/ 
void write_com(unsigned char cmdcode) 
{ 
chk_busy(); 
RS=0; 
RW=0; 
E=1; 
Lcd_Bus=cmdcode; 
delay(5);////////////////////������д���ʱ������ʵ�����ʱ 
E=0; 
delay(5); 
} 
/*----------д���ݵ�LCD--------*/ 
void write_data(unsigned char Dispdata) 
{ 
chk_busy(); 
RS=1; 
RW=0; 
E=1; 
Lcd_Bus=Dispdata; 
delay(5);///////////////////������д���ʱ������ʵ�����ʱ 
E=0; 
delay(5); 
} 
/*----------��ʼ��LCD��-------------------*/ 
void lcd_init(void)
{  delay(2000); 
   write_com(0x30); 
   delay(10);             //ѡ�����ָ� 
   write_com(0x30);       //ѡ��8bit������ 
   delay(5); 
   write_com(0x0c);       //����ʾ(���αꡢ������) 
   delay(10); 
   write_com(0x01);       //�����ʾ�������趨��ַָ��Ϊ00H 
   delay(500); 
   write_com(0x06);       //ָ�������ϵĶ�ȡ��д��ʱ���趨�α���ƶ�����ָ����ʾ����λ 
   delay(0); 
} 
/*-------�Զ���һ���ַ�����(һ�����Ǻ����---------*/ 
void CGRAM() 
{ int i; 
     write_com(0x30);   
     write_com(0x40); 
     for(i=0;i<16;i++) 
     {write_data(zk[i*2]); 
      write_data(zk[i*2+1]); 
      } 
}       
/*------------------��ʾ�ַ���--------------*/ 
void hzkdis(unsigned char code *s) 
{  while(*s>0) 
   {  write_data(*s); 
      s++; 
      delay(50); 
   } 
} 
/*------------------������ʾ-----------------*/ 
void ceshi() 
{write_com(0x01);//�����ʾ�������趨��ַָ��Ϊ00H 
delay(5); 

write_com(0x80);//��һ�У�����ǵ�ַ�ǣ�80H����LCD�ĵ�һ�еĵ�һ��λ����ʾ�� 
hzkdis("��ӭʹ��"); 

write_com(0x90);//�ڶ��У�����ǵ�ַ�ǣ�90H����LCD�ĵڶ��еĵ�һ��λ����ʾ�� 
hzkdis("�����ǿؿ�����"); 

write_com(0x88);//�����У�����ǵ�ַ�ǣ�88H����LCD�ĵڶ��еĵ�һ��λ����ʾ�� 
hzkdis("TEL15980845601"); 

write_com(0x98);//�����У�����ǵ�ַ�ǣ�98H����LCD�ĵڶ��еĵ�һ��λ����ʾ�� 
hzkdis("���Գ���"); 


} 
/*------------------��ʾͼƬ------------------------*/ 
void Disp_Img(unsigned char code *img) 
{  unsigned int j=0; 
   unsigned char x,y,i; 
       for(i=0;i<9;i+=8) 
       for(y=0;y<32;y++)
         for(x=0;x<8;x++) 
         {  write_com(0x36);//��������---8BIT���ƽ��棬����ָ� 
            write_com(y+0x80);        //�е�ַ 
            write_com(x+0x80+i);     //�е�ַ 
            write_com(0x30); 
            write_data(img[j++]); 
            write_data(img[j++]); 
         }   
           
} 
/*------------------������GDRAM�ռ�---------------*/ 
void clrgdram() 
{ unsigned char x,y; 
        for(y=0;y<64;y++) 
         for(x=0;x<16;x++) 
         {  write_com(0x34); 
            write_com(y+0x80);        //�е�ַ 
            write_com(x+0x80);     //�е�ַ 
            write_com(0x30); 
            write_data(0x00); 
            write_data(0x00); 
                               } 
   } 
/*------------------����д������:ȫ������������---------*/ 
void lcdfill(unsigned char disdata) 
{ unsigned char x,y; 
        for(y=0;y<32;y++) 
         for(x=0;x<16;x++) 
         {  write_com(0x36); 
            write_com(y+0x80);        //�е�ַ 
            write_com(x+0x80);     //�е�ַ 
            write_com(0x30); 
            write_data(disdata); 
            write_data(disdata); 
            } 
   write_com(0x34);                             
   write_com(0x36); 
   } 
/*------------------��ʾ��-----------------------------*/ 
void Disp_H_Line() 
{  unsigned char x,y; 
   unsigned char k=0x00;   
       for(y=0;y<32;y++) 
         { k=~k; 
           for(x=0;x<16;x++) 
         {  write_com(0x36); 
            write_com(y+0x80);      //�е�ַ 
            write_com(x+0x80);     //�е�ַ 
            write_com(0x30); 
            write_data(k); 
            write_data(k); 
           }; 
         } 
     write_com(0x34);                           
   write_com(0x36); 
} 
/*------------------��ʾ�߿�-------------------------------*/ 
void Frame() 
{unsigned char x,y; 
          lcdfill(0x00); 
        for(x=0;x<9;x+=8) 
          for(y=0;y<32;y++) 
           { write_com(0x36); 
            write_com(y+0x80);      //�е�ַ 
            write_com(x+0x80);        //�е�ַ 
            write_com(0x30); 
            write_data(0x80); 
            write_data(0x00); 
           
            write_com(0x36); 
            write_com(y+0x80);      //�е�ַ 
            write_com(x+0x87);        //�е�ַ 
            write_com(0x30); 
            write_data(0x00); 
            write_data(0x01); 
             
            } 
      for(y=0;y<2;y++) 
         for(x=0;x<8;x++) 
           {write_com(0x36); 
            write_com(y*31+0x80);      //�е�ַ 
            write_com(x+0x80+8*y);        //�е�ַ 
            write_com(0x30); 
            write_data(0xff); 
            write_data(0xff); 
           } 
         write_com(0x34); 
         write_com(0x36); 
                    } 

/*------------------�ڵ�7�е�λ�ü�����������-------*/ 
void shuxian() 
{ unsigned char x,y; 
     
    for(x=0;x<9;x+=8) 
       for(y=0;y<32;y++) 
          { write_com(0x36); 
            write_com(y+0x80);    //�е�ַ 
            write_com(x+0x86);     //�е�ַ 
            write_com(0x30); 
            write_data(0x00); 
            write_data(0x14); 
          }; 
}     
           
/*------------------��������--------------*/   
void clrscreen() 
{ 
   write_com(0x01); 
   delay(10); 
   } 
   
/*------------------��ʫ����ҹ˼��---------------*/ 
void gushi_display() 
{  write_com(0x30); 
   clrscreen();   
   write_com(0x80+FIRST_ADDR); 
   hzkdis("������ɽ����"); 
   write_com(0x90+FIRST_ADDR); 
   hzkdis("�ƺ��뺣����"); 
   write_com(0x88+FIRST_ADDR); 
   hzkdis("����ǧ��Ŀ��"); 
   write_com(0x98+FIRST_ADDR); 
   hzkdis("����һ��¥��"); 
   write_com(0xb3+FIRST_ADDR); 
   hzkdis("����ȸ¥"); 
   write_com(0xaa+FIRST_ADDR); 
   hzkdis("( �� )��֮��"); 
} 
