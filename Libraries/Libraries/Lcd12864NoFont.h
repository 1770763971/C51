#ifndef _Lcd12864NoFont_H_
#define _Lcd12864NoFont_H_

#define uchar unsigned char
#define uint unsigned int
    
#define Left()   {lcmcs1=0;lcmcs2=1;} //通用
#define Right()	 {lcmcs1=1;lcmcs2=0;} //通用
#define All()    {lcmcs1=0;lcmcs2=0;}
#define CMD	 0
#define DATA 1

sbit LCDMcs=P2^4 ;  
sbit LCDScs=P2^3 ;  
sbit LCDDi=P2^2 ;     
sbit LCDRW=P2^1 ;    
sbit LCDEnable=P2^0;   

sbit lcmrs=P2^2;
sbit lcmrw=P2^1;
sbit lcmen=P2^0;
sbit lcmcs1=P2^4;
sbit lcmcs2=P2^3;
   
#define LCDLCDDisp_Off   0x3e
#define LCDLCDDisp_On    0x3f
#define Page_Add         0xb8
#define LCDCol_Add       0x40
#define Start_Line       0xC0
#define data_ora P0 



void Write(uchar dat, bit type);
void Cls();
void LCDDisplay(uchar line, uchar row, uchar table[7][128]);
void Init();
void LCDdelay(unsigned int t);
void CheckState();
void write_com(unsigned char cmdcode);
void init_lcd();
void write_data(unsigned char LCDDispdata);
void Clr_Scr();
void Bmp_Left_Disp(unsigned char page, unsigned char column, unsigned char code* Bmp);
void Bmp_Right_Disp(unsigned char page, unsigned char column, unsigned char code* Bmp);
void hz_LCDDisp16(unsigned char page, unsigned char column, unsigned char code* hzk);
void Disp(uchar page, uchar column, uchar code* word);


#endif
