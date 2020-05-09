/*
 * Timer.h
 *
 *  Created on: Sep 27, 2018
 *      Author: user
 */
#include "std_types.h"
#ifndef TIMER_H_
#define TIMER_H_
void VidNormTimer(void);
//void__vector_11(void)__attribute__((signal,used));
#define TCCR0 *((u8*)0x53)
#define TCNT0 *((u8*)0x52)
#define SREG *((u8*)0x5F)
#define TIMSK *((u8*)0x59)
#define TCCR1B *((u8*)0x4E)
//#define TCNT1H *((u8*)0x4D)
//we will cast the TCNT1L as a u16 in order to perform actions on it at a time
#define TCNT1L *((u16*)0x4C)
#endif /* TIMER_H_ */
