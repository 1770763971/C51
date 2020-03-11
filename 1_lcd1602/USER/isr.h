#ifndef __ISR_H__
#define __ISR_H__


void Int0_IRQ(void);
void Timer0_IRQ(void);
void Int1_IRQ(void);
void Timer1_IRQ(void);
void Usart(void);

void Int0Init(void);
void Timer0Init(void);
void Int1Init(void);
void Timer1Init(void);
void UsartInit(void);

#endif

