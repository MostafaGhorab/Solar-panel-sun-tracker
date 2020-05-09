/*
 * ADC.h
 *
 *  Created on: Sep 8, 2018
 *      Author: user
 */
#include "std_types.h"
#ifndef ADC_H_
#define ADC_H_
#define ADIF 4
#define ADSC 6
#define ADIE 3
#define ADLAR 5
#define ADCSRA *((u8*)0x26)
#define ADMUX *((u8*)0x27)
#define ADCH *((u8*)0x25)
#define ADCL *((u8*)0x24)
#define SREG *((u8*)0x5F)
#define MCUCR *((u8*)0x55)
void ADC_VidInit(void);
u8 ADC_u8GetADCReading(u8 u8ChannelNB);
void VidGetASCII(u32 NB);
#endif /* ADC_H_ */
