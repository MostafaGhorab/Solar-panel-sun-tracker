/*
 * Timer.c

 *
 *  Created on: Sep 22, 2018
 *      Author: user
 */
#include "std_types.h"
#include "Timer.h"
#include"utils.h"
void VidNormTimer(void)
{
	//Normal mood selection
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
	//value to start counting on = 219
	SET_BIT(TCNT0,7);
	SET_BIT(TCNT0,6);
	CLR_BIT(TCNT0,5);
	SET_BIT(TCNT0,4);
	SET_BIT(TCNT0,3);
	CLR_BIT(TCNT0,2);
	SET_BIT(TCNT0,1);
	SET_BIT(TCNT0,0);
	//Setting prescaler to 8
	CLR_BIT(TCCR0,2);
	SET_BIT(TCCR0,1); //010
	CLR_BIT(TCCR0,0);
	//Enabling the global interrupt
	SET_BIT(SREG,7);
	//Enabling the timer interrupt
	SET_BIT(TIMSK,0);

}
