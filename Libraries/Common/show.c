/*********************************************************************************
/*      RS(CS)    接  P3.5;	 											      */
/*      RW(SID)   接  P3.6;										              */
/*      E(SCLK)   接  P3.4;											          */
/*      PSB       接  P3.7; 串行模式	
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
                    //初始化LCD屏 
      CGRAM();                         
      ceshi();                      //显示测试字样 
     delay(2000); 
     
      clrgdram(); 
     clrscreen();                  //清屏 
     Disp_Img(BMP);               //调入一幅图画 
      delay(30000); 

     Disp_Img(BMP1);               //调入一幅图画 
      delay(20000); 
                   
     lcdfill(0xff);               //显示全开 
      delay(2000);             
     
     Disp_H_Line();                //显示横条 
       delay(2000); 

       lcdfill(0xaa);               //显示竖条 
      delay(2000); 
     
      Frame();                     //显示边框 
      delay(2000); 
       
     gushi_display();             //显示唐诗 
      clrgdram(); 
           
     write_com(0x87);          //调用自定义的CGRAM的代码 
     write_data(0x00); 
     write_data(0x00); 
     delay(400); 
       
      shuxian();              //加入两条竖线 
      delay(8000); 
      write_com(0x30); 
       delay(2000); 
             
      gushi_display(); 
      delay(6000); 
      for(i=0;i<8;i++)        //字符循环左移 
     {write_com(0x18);   
        delay(2000);} 
           
       gushi_display(); 
      delay(6000);   
     write_com(0x36);         
      write_com(0x04);          //第一行反白显示 
      delay(6000); 
      write_com(0x04);          //第一行恢复正常 
      delay(6000); 
       write_com(0x05);          //第二行反白显示 
      delay(6000); 
      write_com(0x05);          //第二行恢复正常 
      delay(6000); 
           
      write_com(0x03);         //垂直滚动屏幕的内容 
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
	     gushi_display();             //调入一幅图画 
      delay(30000); 
}

