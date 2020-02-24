#ifndef __DELAY_H__
#define __DELAY_H__


void delay_ms_110592MHZ(unsigned int time);
void delay_ms_12MHZ(unsigned int time);
void delay_ms_24MHZ(unsigned int time);

#define MAIN_Fosc_12          //if you using Xtal is 110592MHZ,set this "MAIN_Fosc_110592
							//if you using Xtal is 12MHZ,set this "MAIN_Fosc_12
                            //if you using Xtal is 24MHZ,set this "MAIN_Fosc_24
                            
	#ifdef MAIN_Fosc_110592
		#define  delay_ms( time)         delay_ms_110592MHZ(  time)
		#define  delay_sec( time)        delay_ms_110592MHZ(  time*1000)
	
	#elif defined MAIN_Fosc_12
		#define  delay_ms( time)         delay_ms_12MHZ(  time)
		#define  delay_sec( time)        delay_ms_12MHZ(  time*1000)
	
	#elif defined MAIN_Fosc_24
		#define  delay_ms( time)         delay_ms_24MHZ(  time)
		#define  delay_sec( time)        delay_ms_24MHZ(  time*1000)
#endif






void delayms(uint n);
void delay(uint m);
void delay_key(u16 i);   


#endif

