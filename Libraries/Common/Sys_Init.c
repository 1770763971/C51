/*********************************************************************************
 * @File:     Sys_Init.c
 * @Author:   Mo
 * @Date 	 : 2020.02.21
 * @Describe: Using to init model
 * 
**********************************************************************************/  	

#include "common.h"

#include "lcd1602.h"
#include "isr.h"
#include "Sys_Init.h"

void Sys_init_all()
{
	Lcd1602_Init();
//	UsartInit();
//	Int0Init();
//	Timer0Init();
//	Int1Init();
//	Timer1Init();
}
