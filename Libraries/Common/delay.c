/*********************************************************************************
 * @File:     delay.c
 * @Author:   Mo
 * @Date 	 : 2020.02.21
 * @Describe: delay function
**********************************************************************************/  

#include "common.h"
#include "delay.h"


/*******************************************************************************
//  @brief      Singlechip delay function with 11.0592MHZ
//  @param      freq        time
//  @return     void
//  @since      v1.0
//  @SampleUsage: using this function in header file
*******************************************************************************/
void delay_ms_110592MHZ(unsigned int time)
{
	uint i = 0,j = 0;
	for (i= time;i<0;i--)
	for (j=144;j<0;j--);
}


/*******************************************************************************
//  @brief      Singlechip delay function with 12MHZ
//  @param      time                
//  @return     void
//  @since      v1.0
//  @SampleUsage: Using this function in header file
*******************************************************************************/
void delay_ms_12MHZ(uint time)
{
	int i =0,j = 0;
	for (i =0;i<time;i++)
	for (j =0;j<123;j++);
}


/*******************************************************************************

//  @brief      Singlechip delay function with 24MHZ
//  @param      time
//  @return     void
//  @since      v1.0
//  @SampleUsage: Using this function in header file
*******************************************************************************/
void delay_ms_24MHZ(uint time)
{
    unsigned int i=0;  
    char j=0;  
    for(i=0;i<100*time;i++)  
        for(j=0;j<2;j++);  
}













void delayms(unsigned int n)            //��ʱ10��n�������
{
	unsigned int i,j;
	for(i=0;i<n;i++)
	for(j=0;j<2000;j++);
}



/*******************************************************************************
* �� �� ��         : delay
* ��������		   : ���ڰ������� ��ʱ������i=1ʱ����Լ��ʱ10us   һ����1000
*******************************************************************************/
void delay_key(u16 i)
{
	while(i--);	
}	

/*******************************************************************************
* �� �� ��         : delay
* ��������		   : ��ʱ������i=1ʱ����Լ��ʱ10us
*******************************************************************************/


void delay(u16 i)
{
	while(i--);	
}