#include "common.h"

uchar code zk[] = { 
0x08,0x20,0x1c,0x10,0x1c,0x1c,0xff,0x9e,0x7f,0x1e,0x1c,0x1f,0x3e,0x1f,0x3e,0x1f, 
0x77,0x1f,0x41,0x3f,0x00,0x7e,0x00,0xfe,0x83,0xfc,0x7f,0xf8,0x3f,0xf0,0x0f,0xc0, 
}; 




uchar code IC_DAT[]={
"   guanyang    "  
"    原厂直销    "
"  单片机开发板  "
"    MCU     "
};


//uchar code IC_DAT2[]={
//"  床前明月光，  "			//0x80
//"  疑是地上霜，  "			//0x90
//"  举头望明月。  "			//0x88
//"  低头思故乡。  "			//0x98
//};




unsigned char code pic2[]=
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x07,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xC0,0x01,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x07,0x80,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x03,0xC0,0x00,0x00,0x01,0xC0,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x00,0x00,0x1C,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x00,0x1E,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x03,0xC0,0x00,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x00,0x01,0xE6,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x00,0x00,0x07,0x82,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x00,0x1E,0x02,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x01,0xE0,0x00,0x00,0x00,0x00,0x78,0x03,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x01,0xE0,0x00,0x00,0x00,0x01,0xE0,0x03,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x01,0x78,0x00,0x00,0x00,0x07,0x80,0x01,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x03,0x1E,0x00,0x00,0x00,0x1E,0x00,0x07,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x03,0x07,0x80,0x00,0x00,0x78,0x00,0x1F,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x02,0x01,0xE0,0x00,0x01,0xE0,0x00,0x3F,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x06,0x00,0x78,0x1F,0x07,0x80,0x01,0xF1,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x0E,0x00,0x1E,0x3F,0x9E,0x00,0x03,0xF9,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x0E,0x00,0x07,0xB3,0x78,0x00,0x0F,0xF9,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x0F,0x80,0x01,0xFF,0xE0,0x00,0x79,0x98,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x0F,0xE0,0x00,0x7F,0x80,0x00,0xE0,0xD8,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x0F,0xF8,0x00,0x0C,0x00,0x07,0xE0,0xF8,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x0E,0x7E,0x00,0x0C,0x00,0x1F,0xF0,0xF8,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x0E,0x1F,0x80,0x0C,0x00,0x7E,0x70,0xDC,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x0F,0x07,0xE0,0x0C,0x01,0xE3,0x70,0x5C,0xC0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x0F,0x81,0xF8,0x0C,0x07,0x83,0x70,0x5F,0xC0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x0D,0xE0,0x7E,0x0C,0x1F,0xC1,0xF0,0x5F,0xC0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x0F,0x78,0x3F,0x8C,0x7F,0xC1,0xB8,0x47,0xC0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x0F,0x1E,0x0F,0xED,0xEC,0xE1,0xB8,0xC7,0xC0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x1F,0x07,0x83,0xFF,0xC6,0xE1,0xB9,0xC7,0xC0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x1F,0x07,0xE0,0xFF,0xE7,0xE1,0xBF,0x07,0xC0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x1F,0x07,0xF8,0x3F,0xE7,0xE1,0xBF,0x07,0xC0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x1F,0x07,0x9E,0x0C,0xE6,0xE1,0x8F,0x07,0xC0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x1F,0x07,0x87,0x8C,0xE6,0xE3,0x8F,0x83,0xC0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x1F,0x0F,0x81,0xED,0xE6,0xE7,0x0F,0x83,0xC0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x1F,0x07,0x00,0x7F,0xE6,0xFE,0x0F,0x83,0x40,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x1F,0x00,0x00,0x1E,0x76,0xFE,0x0F,0x83,0x40,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x1E,0x00,0x00,0x00,0x72,0x1E,0x0F,0x83,0x40,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x1E,0x00,0x00,0x00,0x7E,0x1A,0x0F,0x83,0x40,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x1E,0x00,0x00,0x00,0x7C,0x1A,0x0F,0x83,0xC0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x78,0x1A,0x0F,0x83,0xC0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x1A,0x07,0x83,0xC0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x1E,0x07,0x80,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x1F,0x07,0x80,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x1F,0x07,0x80,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x1F,0x07,0x80,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x1F,0x07,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x34,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x34,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x34,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};




unsigned char code BMP1[]={ 
/*--  一幅图像 KISS- 正向取模，字节正序*/ 
/*--  宽度x高度=128x64  --*/ 

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0xFF,0xFF,0xFF,0x9F,0x00,0x00,0x0F,0x0E,0x00,0x00,0x00,0x00,0x19,0xFF,0xFF,0xFF, 
0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xBF,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xFD,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0xFF,0xFF,0xF3,0xE0,0x00,0x00,0x1F,0xFD,0x80,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF, 
0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xFA,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xF4,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0xFF,0xFF,0xF0,0x00,0x00,0x00,0x03,0xF8,0x01,0xFF,0xFF,0xE0,0x00,0x07,0xFF,0xFF, 
0x00,0x00,0x00,0x0F,0xFF,0xFC,0x00,0xF0,0x3F,0xFF,0xFF,0xFE,0x00,0x30,0x00,0x00, 
0x00,0x00,0x00,0x7F,0xFF,0xFF,0x80,0x41,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x00,0x00, 
0xFF,0xFF,0x01,0xFF,0xFF,0xFF,0xF0,0x02,0x7F,0xFF,0xFF,0xFF,0xE0,0x03,0xFF,0xFF, 
0x00,0x00,0x03,0xFF,0xFF,0xFF,0xF8,0x04,0x3F,0xFF,0xFF,0xFF,0xF0,0x00,0x00,0x00, 
0x00,0x00,0x1F,0xFF,0xFF,0xFF,0xFC,0x08,0x73,0xFF,0xFF,0xFF,0xF8,0x00,0x00,0x00, 
0xFF,0xE4,0x3F,0x7F,0xFF,0xFF,0xFF,0x30,0x2F,0xFF,0xFF,0xFF,0xFE,0x00,0x7F,0xFF, 
0x00,0x00,0xFE,0x9F,0xFF,0xFF,0xFF,0xB0,0x1D,0xFF,0xFF,0xFF,0x3F,0x00,0x00,0x00, 
0x00,0x00,0xFF,0x7F,0xFF,0xFF,0xFF,0xC2,0x23,0x3F,0xFF,0xFE,0x1F,0x80,0x00,0x00,
/*****************************************************************************/ 
0xFF,0xE1,0xFF,0xFF,0xFF,0xFF,0xFC,0xC5,0x92,0xFF,0xB7,0xB8,0xC9,0x80,0x7F,0xFF, 
0x00,0x03,0xFF,0xFF,0xFF,0xFF,0xFC,0x4F,0xEF,0x3F,0xC8,0x1A,0x20,0xC0,0x00,0x00, 
0x00,0x03,0xFF,0xFF,0xFF,0xFF,0xF8,0x7F,0xFF,0xFF,0x75,0x86,0xF6,0xC0,0x00,0x00, 
0xFF,0x03,0xEF,0x9F,0xFB,0xFF,0xF8,0x7F,0xFF,0xFF,0xFB,0xDF,0xFE,0xC0,0x7F,0xFF, 
0x00,0x07,0xDE,0x7F,0xC7,0xFF,0xF0,0x7E,0x7F,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x00, 
0x00,0x07,0x1C,0xF7,0x9F,0xDF,0xF0,0x7E,0x7F,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x00, 
0xFC,0x07,0x00,0x8C,0x1F,0xBF,0xE7,0x3C,0x3F,0xFF,0xFF,0xFF,0xFF,0xC0,0x7F,0xFF, 
0x00,0x07,0x00,0x08,0x1C,0x3F,0x88,0x3C,0x7F,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x00, 
0x00,0x06,0x0C,0x08,0x98,0x7F,0x80,0x0D,0x9F,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x00, 
0xFC,0x06,0x1C,0xE3,0x99,0xFF,0x00,0x0C,0x0F,0xFF,0xFF,0xFF,0xFF,0xC0,0x5F,0xFF, 
0x00,0x06,0xF1,0xE3,0x83,0xFE,0x00,0x08,0x03,0xDF,0xFF,0xFF,0xFF,0xC0,0x00,0x00, 
0x00,0x06,0xF1,0xF7,0xC7,0xFE,0x00,0x08,0x01,0xCF,0xFF,0xFF,0xFF,0xC0,0x00,0x00, 
0xFC,0x06,0xF3,0xF7,0xC7,0xFC,0x03,0x08,0x00,0x01,0xFF,0xFF,0xFF,0xC0,0xBF,0xFF, 
0x00,0x07,0xF3,0xFF,0xE7,0xF0,0x03,0x09,0x80,0x00,0xFF,0xFF,0xFF,0xC0,0x00,0x00, 
0x00,0x07,0xFF,0xFF,0xFF,0xE0,0x03,0x09,0x80,0x00,0x3F,0xFF,0xFF,0x80,0x00,0x00, 
0xFC,0x07,0xFF,0xFF,0xFF,0xC0,0x03,0x09,0x80,0x00,0x0F,0xFF,0xFF,0x83,0xFF,0xFF,
/*****************************************************************************/ 
0x00,0x07,0xFF,0xE0,0xFE,0x00,0x03,0x09,0x80,0x00,0x07,0xFF,0xFF,0x80,0x00,0x00, 
0x00,0x07,0xFF,0x80,0x7C,0x00,0x07,0xB1,0x80,0x00,0x07,0x83,0xFF,0x00,0x00,0x00, 
0xFF,0x07,0xFF,0x0C,0x00,0x00,0x7F,0xB3,0xC0,0x00,0x06,0x01,0xFE,0x03,0xFF,0xFF, 
0x00,0x07,0xFF,0x03,0x00,0x00,0x1F,0x43,0xFC,0x00,0x06,0x38,0xFE,0x00,0x00,0x00, 
0x00,0x07,0xFF,0x03,0x00,0x00,0x00,0x81,0xF0,0x00,0x04,0x40,0xF8,0x00,0x00,0x00, 
0xFC,0x87,0xFF,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x04,0x40,0xF0,0x07,0xFF,0xFF, 
0x00,0x07,0xFF,0x80,0x00,0x2C,0x00,0x80,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x00, 
0x00,0x07,0xFF,0x80,0x00,0x52,0x00,0x40,0x00,0x00,0x00,0x01,0xE0,0x00,0x00,0x00, 
0xFF,0x83,0xFF,0xF0,0x80,0x2C,0x00,0x40,0x00,0x00,0x00,0x01,0xC0,0x7F,0xFF,0xFF, 
0x00,0x03,0xFF,0xFF,0x80,0x00,0x00,0x30,0x00,0x00,0x01,0x86,0x00,0x00,0x00,0x00, 
0x00,0x03,0xFF,0xFF,0x80,0x00,0x00,0x38,0x00,0x00,0x01,0xF8,0x00,0x00,0x00,0x00, 
0xFF,0xA3,0xFF,0xFF,0x80,0x00,0x00,0x44,0x00,0x00,0x01,0xFF,0x00,0x7F,0xFF,0xFF, 
0x00,0x03,0xFF,0xFF,0x80,0x00,0x03,0x82,0x00,0x00,0x01,0xC0,0xC0,0x00,0x00,0x00, 
0x00,0x03,0xFF,0xFF,0x80,0x00,0x1C,0x01,0xC0,0x00,0x00,0x78,0xC0,0x00,0x00,0x00, 
0xFF,0x81,0xFF,0xFF,0xC0,0x3F,0xE0,0x00,0x3C,0x00,0x07,0x80,0x20,0x7F,0xFF,0xFF, 
0x00,0x01,0xFF,0xFF,0xE0,0x40,0x00,0x00,0x03,0xFE,0x78,0x00,0x20,0x00,0x00,0x00,
/*****************************************************************************/
0x00,0x01,0xFF,0xFF,0xF8,0x40,0x00,0x00,0x00,0x21,0x80,0x00,0x10,0x00,0x00,0x00, 
0xFF,0xC1,0xFF,0xFF,0xFC,0x40,0x00,0x00,0x00,0x2E,0x00,0x00,0x10,0x4F,0xFF,0xFF, 
0x00,0x01,0xFF,0xFF,0xFE,0x20,0x00,0x00,0x00,0x30,0x00,0x00,0x30,0x00,0x00,0x00, 
0x00,0x00,0xFF,0xFF,0xFF,0xA0,0x00,0x00,0x00,0xC0,0x00,0x01,0xF8,0x00,0x00,0x00, 
0xFF,0xE0,0xFF,0xFF,0xFB,0xE0,0x00,0x00,0x00,0xC0,0x00,0x03,0xFE,0x07,0xFF,0xFF, 
0x00,0x00,0xFF,0xFF,0xFD,0xE0,0x00,0x00,0x00,0xC0,0x00,0x1F,0xFF,0x00,0x00,0x00, 
0x00,0x00,0xFF,0xFF,0xFE,0x70,0x00,0x00,0x01,0xE0,0x00,0x3F,0xFF,0x80,0x00,0x00, 
0xFF,0xC0,0xFF,0xFF,0xFF,0xB0,0x00,0x00,0x01,0xE0,0x00,0x7F,0xFF,0xC0,0x3F,0xFF, 
0x00,0x00,0xFF,0xFF,0xFF,0xDC,0x00,0x00,0x03,0xF7,0x81,0xFF,0xFF,0xF0,0x00,0x00, 
0x00,0x01,0xFF,0x80,0x7F,0xDC,0x00,0x00,0x0F,0xFF,0xC3,0xFF,0xFF,0xF8,0x00,0x00, 
0xFF,0x01,0xFF,0x00,0x1F,0xEE,0x00,0x00,0x13,0xFF,0xF7,0xFF,0xFF,0xFC,0x07,0xFF, 
0x00,0x01,0xFE,0x00,0x07,0xEF,0x00,0x00,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00, 
0x00,0x01,0xFC,0x00,0x03,0xF3,0x00,0x00,0x13,0xFF,0xBF,0xFF,0xFF,0xFF,0x80,0x00, 
0xFF,0x01,0xFC,0x00,0x01,0xF3,0x80,0x00,0x1F,0xFF,0xBF,0xFF,0xFF,0xFF,0x83,0xFF, 
0x00,0x01,0xF0,0x00,0x01,0xFD,0x80,0x00,0x0F,0xFF,0x7F,0xFF,0xFF,0xFF,0xC0,0x00, 
0x00,0x03,0xF0,0x00,0x00,0x72,0xE0,0x00,0x03,0xFE,0xFF,0xFF,0xFF,0xFF,0xC0,0x00 

};   



unsigned char code BMP[]={ 
//一幅图像 - 正向取模，字节正序 
/*--  宽度x高度=128x64  --*/ 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x20,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x40,0x08,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x40,0x08,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x40,0x38,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x60,0x00,0x06,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x01,0x80,0x00,0x38,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x03,0xC0,0x00,0x03,0xC0,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x1C,0x38,0x00,0x1C,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x04,0x00,0xE0,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x02,0x03,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xF0,0x01,0x00,0x00,0x80,0x00,0x00,0x00,
/*****************************************************************************/ 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x01,0x00,0x00,0x80,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE1,0x00,0x00,0x80,0x00,0x00,0x00, 
0x00,0x00,0x0F,0x80,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x40,0x00,0x00,0x00, 
0x00,0x00,0x18,0xC0,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x40,0x00,0x00,0x00, 
0x00,0x00,0x10,0x40,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x41,0xC0,0x00,0x00, 
0x00,0x00,0x30,0x60,0x3F,0xC0,0x00,0x00,0x00,0x02,0x00,0x00,0x40,0x3E,0x00,0x00, 
0x00,0x00,0x20,0x23,0xC0,0x60,0x00,0x00,0x00,0x61,0x00,0x00,0x80,0x01,0xC0,0x00, 
0x00,0x00,0x40,0x3C,0x00,0x18,0x00,0xC0,0x07,0xC1,0x00,0x00,0x80,0x00,0x00,0x00, 
0x00,0x00,0x40,0x18,0x00,0x04,0x01,0xA0,0x1C,0x01,0x00,0x00,0x80,0x00,0x00,0x00, 
0x00,0x00,0x40,0x08,0x00,0x06,0x02,0x1C,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00, 
0x00,0x00,0xC0,0x08,0x00,0x01,0x8C,0x03,0x80,0x00,0x40,0x02,0x00,0x00,0x00,0x00, 
0x00,0x00,0x80,0x0C,0x00,0x00,0x58,0x00,0x60,0x06,0x20,0x04,0x20,0x00,0x00,0x00, 
0x00,0x01,0x00,0x04,0x00,0x00,0x20,0x00,0x10,0x1C,0x1C,0x38,0x18,0x00,0x00,0x00, 
0x00,0x01,0x00,0x06,0x00,0x00,0x30,0x00,0x08,0x30,0x03,0xC0,0x07,0x00,0x00,0x00, 
0x00,0x01,0x00,0x02,0x00,0x00,0x18,0x00,0x04,0x60,0x00,0x00,0x01,0x80,0x00,0x00, 
0x00,0x02,0x00,0x00,0x00,0x00,0x0C,0x00,0x03,0x00,0x00,0x00,0x00,0x40,0x00,0x00,
/*****************************************************************************/
0x00,0x02,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x80,0x02,0x08,0x00,0x30,0x00,0x00, 
0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x02,0x08,0x00,0x18,0x00,0x00, 
0x00,0x0C,0x00,0x00,0x7F,0xFC,0x00,0x00,0x00,0x20,0x02,0x04,0x00,0x00,0x00,0x00, 
0x00,0x0C,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x18,0x02,0x04,0x00,0x00,0x00,0x00, 
0x00,0x18,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x07,0xF2,0x02,0x00,0x00,0x00,0x00, 
0x00,0x30,0x00,0x00,0x0F,0xFC,0x00,0x00,0x00,0x00,0x02,0x02,0x00,0x00,0x00,0x00, 
0x00,0x60,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00, 
0x00,0x40,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00, 
0x01,0x80,0x00,0x00,0x0F,0xFF,0xFF,0xFF,0xFF,0xE0,0x00,0x00,0x80,0x00,0x00,0x00, 
0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x19,0x8C,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00, 
0x00,0x00,0x00,0x00,0x00,0x00,0x30,0xCC,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,

/*
 "太",     "阳",    "出",      "来",    "喜",     "洋",     "洋",     "喽",*/
 0x01,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x22,0x10,0x22,0x10,0x00,0x48,
 0x01,0x00,0x7D,0xFC,0x01,0x00,0x01,0x00,0x7F,0xFC,0x11,0x10,0x11,0x10,0x02,0x4C,
 0x01,0x00,0x45,0x04,0x21,0x04,0x3F,0xFC,0x01,0x00,0x11,0x20,0x11,0x20,0xF1,0x50,
 0x01,0x00,0x49,0x04,0x21,0x04,0x01,0x00,0x3F,0xF8,0x07,0xFC,0x07,0xFC,0x97,0xFE,
 0x7F,0xFE,0x49,0x04,0x21,0x04,0x09,0x30,0x00,0x00,0x80,0x40,0x80,0x40,0x90,0xE0,
 0x01,0x00,0x51,0x04,0x21,0x04,0x05,0x20,0x1F,0xF0,0x50,0x40,0x50,0x40,0x91,0x50,
 0x01,0x00,0x49,0xFC,0x3F,0xFC,0x03,0x40,0x10,0x10,0x57,0xFC,0x57,0xFC,0x92,0x4E,
 0x01,0x00,0x45,0x04,0x21,0x04,0x7F,0xFE,0x1F,0xF0,0x10,0x40,0x10,0x40,0x9D,0x44,
 0x02,0x80,0x45,0x04,0x01,0x00,0x01,0x80,0x04,0x40,0x20,0x40,0x20,0x40,0x91,0x00,
 0x02,0x40,0x45,0x04,0x21,0x04,0x03,0x40,0xFF,0xFE,0x2F,0xFE,0x2F,0xFE,0xF7,0xFC,
 0x04,0x20,0x69,0x04,0x21,0x04,0x05,0x20,0x00,0x00,0xE0,0x40,0xE0,0x40,0x92,0x10,
 0x05,0x10,0x51,0x04,0x21,0x04,0x09,0x18,0x1F,0xF0,0x20,0x40,0x20,0x40,0x83,0x20,
 0x08,0x98,0x41,0xFC,0x21,0x04,0x31,0x0E,0x10,0x10,0x20,0x40,0x20,0x40,0x00,0xE0,
 0x10,0xCC,0x41,0x04,0x3F,0xFC,0xC1,0x04,0x10,0x10,0x20,0x40,0x20,0x40,0x01,0x18,
 0x20,0x86,0x40,0x00,0x01,0x00,0x01,0x00,0x1F,0xF0,0x20,0x40,0x20,0x40,0x02,0x0C,
 0x40,0x04,0x40,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x20,0x40,0x20,0x40,0x04,0x08
 }; 



