/*********************************************************************************
/*      RS(CS)    ��  P3.5;	 											      */
/*      RW(SID)   ��  P3.6;										              */
/*      E(SCLK)   ��  P3.4;											          */
/*      PSB       ��  P3.7; ����ģʽ	
**********************************************************************************/  	
#include "common.h"
#include "delay.h"
#include "model.h"
#include "lcd12864.h"
#include "show.h"

extern uchar code IC_DAT[];
extern uchar code IC_DAT2[];
extern unsigned char code zk[];
extern unsigned char code pic2[];
extern unsigned char code BMP1[];
extern unsigned char code BMP[];
extern unsigned char code zk[];
extern unsigned char code nBitmapDot[];

void show_picture(void)
{  unsigned char i; 
//	du=0;
//	we=0;
   while(1) 
   { 
    PSB=0;
 delay(300);
 PSB=1;        
     RW=0; 
                    //��ʼ��LCD�� 
      CGRAM();                         
      ceshi();                      //��ʾ�������� 
     delay(2000); 
     
      clrgdram(); 
     clrscreen();                  //���� 
     Disp_Img(BMP);               //����һ��ͼ�� 
      delay(30000); 

     Disp_Img(BMP1);               //����һ��ͼ�� 
      delay(20000); 
                   
     lcdfill(0xff);               //��ʾȫ�� 
      delay(2000);             
     
     Disp_H_Line();                //��ʾ���� 
       delay(2000); 

       lcdfill(0xaa);               //��ʾ���� 
      delay(2000); 
     
      Frame();                     //��ʾ�߿� 
      delay(2000); 
       
     gushi_display();             //��ʾ��ʫ 
      clrgdram(); 
           
     write_com(0x87);          //�����Զ����CGRAM�Ĵ��� 
     write_data(0x00); 
     write_data(0x00); 
     delay(400); 
       
      shuxian();              //������������ 
      delay(8000); 
      write_com(0x30); 
       delay(2000); 
             
      gushi_display(); 
      delay(6000); 
      for(i=0;i<8;i++)        //�ַ�ѭ������ 
     {write_com(0x18);   
        delay(2000);} 
           
       gushi_display(); 
      delay(6000);   
     write_com(0x36);         
      write_com(0x04);          //��һ�з�����ʾ 
      delay(6000); 
      write_com(0x04);          //��һ�лָ����� 
      delay(6000); 
       write_com(0x05);          //�ڶ��з�����ʾ 
      delay(6000); 
      write_com(0x05);          //�ڶ��лָ����� 
      delay(6000); 
           
      write_com(0x03);         //��ֱ������Ļ������ 
      write_com(0x60); 
      delay(6000);
  }
}


void show_picture_1(void)
{
	    PSB=0;
	 delay(300);
 PSB=1;        
     RW=0; 
	     gushi_display();             //����һ��ͼ�� 
      delay(30000); 
}

