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

/*------------------Ğ´ÃüÁîµ½LCD------------------------------*/ 
void write_com(unsigned char cmdcode) 
{ 
chk_busy(); 
RS=0; 
RW=0; 
E=1; 
Lcd_Bus=cmdcode; 
delay(5);////////////////////ÔÚÊı¾İĞ´ÈëµÄÊ±ºò¼ÓÈëÊÊµ±µÄÑÓÊ± 
E=0; 
delay(5); 
} 
/*----------Ğ´Êı¾İµ½LCD--------*/ 
void write_data(unsigned char Dispdata) 
{ 
chk_busy(); 
RS=1; 
RW=0; 
E=1; 
Lcd_Bus=Dispdata; 
delay(5);///////////////////ÔÚÊı¾İĞ´ÈëµÄÊ±ºò¼ÓÈëÊÊµ±µÄÑÓÊ± 
E=0; 
delay(5); 
} 
/*----------³õÊ¼»¯LCDÆÁ-------------------*/ 
void lcd_init(void)
{  delay(2000); 
   write_com(0x30); 
   delay(10);             //Ñ¡Ôñ»ù±¾Ö¸Áî¼¯ 
   write_com(0x30);       //Ñ¡Ôñ8bitÊı¾İÁ÷ 
   delay(5); 
   write_com(0x0c);       //¿ªÏÔÊ¾(ÎŞÓÎ±ê¡¢²»·´°×) 
   delay(10); 
   write_com(0x01);       //Çå³ıÏÔÊ¾£¬²¢ÇÒÉè¶¨µØÖ·Ö¸ÕëÎª00H 
   delay(500); 
   write_com(0x06);       //Ö¸¶¨ÔÚ×ÊÁÏµÄ¶ÁÈ¡¼°Ğ´ÈëÊ±£¬Éè¶¨ÓÎ±êµÄÒÆ¶¯·½Ïò¼°Ö¸¶¨ÏÔÊ¾µÄÒÆÎ» 
   delay(0); 
} 
/*-------×Ô¶¨ÒåÒ»¸ö×Ö·û´úÂë(Ò»¸öĞÇĞÇºÍÔÂÁ---------*/ 
void CGRAM() 
{ int i; 
     write_com(0x30);   
     write_com(0x40); 
     for(i=0;i<16;i++) 
     {write_data(zk[i*2]); 
      write_data(zk[i*2+1]); 
      } 
}       
/*------------------ÏÔÊ¾×Ö·û´®--------------*/ 
void hzkdis(unsigned char code *s) 
{  while(*s>0) 
   {  write_data(*s); 
      s++; 
      delay(50); 
   } 
} 
/*------------------Ê×ÆÁÏÔÊ¾-----------------*/ 
void ceshi() 
{write_com(0x01);//Çå³ıÏÔÊ¾£¬²¢ÇÒÉè¶¨µØÖ·Ö¸ÕëÎª00H 
delay(5); 

write_com(0x80);//µÚÒ»ĞĞ£¨Èç¹ûÊÇµØÖ·ÊÇ£º80H£¬¼´LCDµÄµÚÒ»ĞĞµÄµÚÒ»¸öÎ»ÖÃÏÔÊ¾£© 
hzkdis("»¶Ó­Ê¹ÓÃ"); 

write_com(0x90);//µÚ¶şĞĞ£¨Èç¹ûÊÇµØÖ·ÊÇ£º90H£¬¼´LCDµÄµÚ¶şĞĞµÄµÚÒ»¸öÎ»ÖÃÏÔÊ¾£© 
hzkdis("ÏÃÃÅÖÇ¿Ø¿ª·¢°å"); 

write_com(0x88);//µÚÈıĞĞ£¨Èç¹ûÊÇµØÖ·ÊÇ£º88H£¬¼´LCDµÄµÚ¶şĞĞµÄµÚÒ»¸öÎ»ÖÃÏÔÊ¾£© 
hzkdis("TEL15980845601"); 

write_com(0x98);//µÚËÄĞĞ£¨Èç¹ûÊÇµØÖ·ÊÇ£º98H£¬¼´LCDµÄµÚ¶şĞĞµÄµÚÒ»¸öÎ»ÖÃÏÔÊ¾£© 
hzkdis("²âÊÔ³ÌĞò"); 


} 
/*------------------ÏÔÊ¾Í¼Æ¬------------------------*/ 
void Disp_Img(unsigned char code *img) 
{  unsigned int j=0; 
   unsigned char x,y,i; 
       for(i=0;i<9;i+=8) 
       for(y=0;y<32;y++)
         for(x=0;x<8;x++) 
         {  write_com(0x36);//¹¦ÄÜÉèÖÃ---8BIT¿ØÖÆ½çÃæ£¬À©³äÖ¸Áî¼¯ 
            write_com(y+0x80);        //ĞĞµØÖ· 
            write_com(x+0x80+i);     //ÁĞµØÖ· 
            write_com(0x30); 
            write_data(img[j++]); 
            write_data(img[j++]); 
         }   
           
} 
/*------------------ÇåÕû¸öGDRAM¿Õ¼ä---------------*/ 
void clrgdram() 
{ unsigned char x,y; 
        for(y=0;y<64;y++) 
         for(x=0;x<16;x++) 
         {  write_com(0x34); 
            write_com(y+0x80);        //ĞĞµØÖ· 
            write_com(x+0x80);     //ÁĞµØÖ· 
            write_com(0x30); 
            write_data(0x00); 
            write_data(0x00); 
                               } 
   } 
/*------------------ÕûÆÁĞ´ÈëÊı¾İ:È«ÁÁ£¬»òÕßÊúÌõ---------*/ 
void lcdfill(unsigned char disdata) 
{ unsigned char x,y; 
        for(y=0;y<32;y++) 
         for(x=0;x<16;x++) 
         {  write_com(0x36); 
            write_com(y+0x80);        //ĞĞµØÖ· 
            write_com(x+0x80);     //ÁĞµØÖ· 
            write_com(0x30); 
            write_data(disdata); 
            write_data(disdata); 
            } 
   write_com(0x34);                             
   write_com(0x36); 
   } 
/*------------------ÏÔÊ¾ºá-----------------------------*/ 
void Disp_H_Line() 
{  unsigned char x,y; 
   unsigned char k=0x00;   
       for(y=0;y<32;y++) 
         { k=~k; 
           for(x=0;x<16;x++) 
         {  write_com(0x36); 
            write_com(y+0x80);      //ĞĞµØÖ· 
            write_com(x+0x80);     //ÁĞµØÖ· 
            write_com(0x30); 
            write_data(k); 
            write_data(k); 
           }; 
         } 
     write_com(0x34);                           
   write_com(0x36); 
} 
/*------------------ÏÔÊ¾±ß¿ò-------------------------------*/ 
void Frame() 
{unsigned char x,y; 
          lcdfill(0x00); 
        for(x=0;x<9;x+=8) 
          for(y=0;y<32;y++) 
           { write_com(0x36); 
            write_com(y+0x80);      //ĞĞµØÖ· 
            write_com(x+0x80);        //ÁĞµØÖ· 
            write_com(0x30); 
            write_data(0x80); 
            write_data(0x00); 
           
            write_com(0x36); 
            write_com(y+0x80);      //ĞĞµØÖ· 
            write_com(x+0x87);        //ÁĞµØÖ· 
            write_com(0x30); 
            write_data(0x00); 
            write_data(0x01); 
             
            } 
      for(y=0;y<2;y++) 
         for(x=0;x<8;x++) 
           {write_com(0x36); 
            write_com(y*31+0x80);      //ĞĞµØÖ· 
            write_com(x+0x80+8*y);        //ÁĞµØÖ· 
            write_com(0x30); 
            write_data(0xff); 
            write_data(0xff); 
           } 
         write_com(0x34); 
         write_com(0x36); 
                    } 

/*------------------ÔÚµÚ7ÁĞµÄÎ»ÖÃ¼ÓÈëÁ½ÌõÊúÏß-------*/ 
void shuxian() 
{ unsigned char x,y; 
     
    for(x=0;x<9;x+=8) 
       for(y=0;y<32;y++) 
          { write_com(0x36); 
            write_com(y+0x80);    //ĞĞµØÖ· 
            write_com(x+0x86);     //ÁĞµØÖ· 
            write_com(0x30); 
            write_data(0x00); 
            write_data(0x14); 
          }; 
}     
           
/*------------------ÇåÆÁÃüÁî--------------*/   
void clrscreen() 
{ 
   write_com(0x01); 
   delay(10); 
   } 
   
/*------------------ÌÆÊ«¡¶¾²Ò¹Ë¼¡·---------------*/ 
void gushi_display() 
{  write_com(0x30); 
   clrscreen();   
   write_com(0x80+FIRST_ADDR); 
   hzkdis("°×ÈÕÒÀÉ½¾¡£¬"); 
   write_com(0x90+FIRST_ADDR); 
   hzkdis("»ÆºÓÈëº£Á÷¡£"); 
   write_com(0x88+FIRST_ADDR); 
   hzkdis("ÓûÇîÇ§ÀïÄ¿£¬"); 
   write_com(0x98+FIRST_ADDR); 
   hzkdis("¸üÉÏÒ»²ãÂ¥¡£"); 
   write_com(0xb3+FIRST_ADDR); 
   hzkdis("µÇğÙÈ¸Â¥"); 
   write_com(0xaa+FIRST_ADDR); 
   hzkdis("( ÌÆ )ÍõÖ®»À"); 
} 
