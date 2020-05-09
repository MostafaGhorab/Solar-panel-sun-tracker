/*
 * ADC.c
 *
 *  Created on: Sep 8, 2018
 *      Author: user
 */
#include "utils.h"
#include "AVR_DIOReg.h"
#include "DIO_Prog.h"
#include "ADC.h"
#include "std_types.h"
#define F_CPU 12000000
#include "util\delay.h"
void ADC_VidInit(void)
{
	//ENABLE THE ADC
	SET_BIT(ADCSRA,7);
	//SELECT AVCC AS A REFERENCE
	CLR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6)	;
	//SET PRESCALAR TO 2
	CLR_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);
	//LEFT ADJUSTMENT
	SET_BIT(ADMUX,ADLAR);
	//enabling ADC INTERRUPT
	/*SET_BIT(SREG,7);
	SET_BIT(ADCSRA,3);*/
}
u8 ADC_u8GetADCReading(u8 u8ChannelNB)
{
	u8 temp;
	//Channel selection
	ADMUX = (ADMUX & 0xE0) | (u8ChannelNB & 0x1F);
	ADCSRA |= (1<<ADSC);
	while(!(get_bit(ADCSRA,ADIF)))
	{
	}
	_delay_us(1);
	temp=ADCH;
	ADCSRA |= (1<<ADIF);
	return temp;
}
