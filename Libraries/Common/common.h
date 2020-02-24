/*********************************************************************************
 * @File:     common.h
 * @Author:   Mo
 * @Date 	 : 2020.02.21
 * @Describe: null 
**********************************************************************************/  

#ifndef __COMMON_H__
#define __COMMON_H__

#include <reg52.h>
#include <math.h>
#include <intrins.h>
#include <string.h>
#include <assert.h>
//类型定义
#define uchar unsigned char
#define uint  unsigned int
#define ulong  unsigned long
	
//数据类型声明
typedef unsigned char       uint8;   //  8 bits 
typedef unsigned short int  uint16;  // 16 bits 
typedef unsigned long int   uint32;  // 32 bits 


typedef unsigned char       u8;   //  8 bits 
typedef unsigned short int  u16;  // 16 bits 
typedef unsigned long int   u32;  // 32 bits 
 
typedef char                int8;    //  8 bits 
typedef short int           int16;   // 16 bits 
typedef long  int           int32;   // 32 bits 

typedef volatile int8       vint8;   //  8 bits 
typedef volatile int16      vint16;  // 16 bits 
typedef volatile int32      vint32;  // 32 bits 

typedef volatile uint8      vuint8;  //  8 bits 
typedef volatile uint16     vuint16; // 16 bits 
typedef volatile uint32     vuint32; // 32 bits 

sbit RS  = P2^6;
sbit RW  = P2^5;
sbit E   = P2^7;
sbit PSB = P3^2;

sbit LSA = P2^2;
sbit LSB = P2^3;
sbit LSC = P2^4;




#define GPIO_DIG P0
#define GPIO_KEY P1


void delay(u16 i);
void keypros();

#endif

