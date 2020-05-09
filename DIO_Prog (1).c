/*
 * DIO_Prog.c
 *
 *  Created on: Aug 17, 2018
 *      Author: user
 */
/*
 * DIO.c

 *
 *  Created on: Aug 17, 2018
 *      Author: user
 */
#include "std_types.h"
#include "AVR_DIOReg.h"
#include "DIO_Prog.h"
void DIO_SetPortDirection(u8 Port,u8 Direction)
{
	switch (Port)
	{
	case 0:
		DDRA=Direction;
		break;
	case 1:
		DDRB=Direction;
		break;
	case 2 :
		DDRC=Direction;
		break;
	case 3 :
			DDRD=Direction;
			break;
	}

}
void DIO_SetPortValue(u8 Port,u8 Val)
{
	switch (Port)
		{
		case 0:
			PORTA=Val;
			break;
		case 1:
			PORTB=Val;
			break;
		case 2 :
			PORTC=Val;
			break;
		case 3 :
				PORTD=Val;
				break;
		}
}

u8 DIO_u8GetPortValue(u8 Port)
{
	switch (Port)
			{
			case 0:
               return PINA;    //da el maktob feeh el vlue elli gowa el port
               break;
			case 1:
				 return PINB;
				break;
			case 2 :
				 return PINC;
				 break;
			case 3 :
				 return PIND;
				 break;
			}
}

void DIO_SetPinDirection(u8 Port,u8 Pin,u8 direc)
{
	switch (Port)
	{
	case 0:
		if(direc == 1)
		{
			DDRA |= (1<<Pin);
		}
		else
		{
		   DDRA &=~(1<<Pin);
		}
		break;
	case 1:
		if(direc==1)
				{
					DDRB |= (1<<Pin);
				}
				else
				{
				   DDRB &=~(1<<Pin);
				}
				break;
	case 2:
		if(direc==1)
				{
					DDRC |= (1<<Pin);
				}
				else
				{
				   DDRC &=~(1<<Pin);
				}
				break;
	case 3:
				if(direc==1)
						{
							DDRD |= (1<<Pin);
						}
						else
						{
						   DDRD &=~(1<<Pin);
						}
						break;
	}
	}

void DIO_SetPinVal(u8 Port,u8 Pin,u8 Val)
{
	switch (Port)
	{
	case 0:
		if(Val==1)
		{
			PORTA |= (1<<Pin);
		}
		else
		{
		   PORTA &=~(1<<Pin);
		}
		break;
	case 1:
		if(Val==1)
				{
					PORTB |= (1<<Pin);
				}
				else
				{
				   PORTB &=~(1<<Pin);
				}
				break;
	case 2:
		if(Val==1)
				{
					PORTC |= (1<<Pin);
				}
				else
				{
				   PORTC &=~(1<<Pin);
				}
				break;
	case 3:
				if(Val==1)
						{
							PORTD |= (1<<Pin);
						}
						else
						{
						   PORTD &=~(1<<Pin);
						}
						break;
	}
}

u8 DIO_u8GetPinVal(u8 Port,u8 Pin)
{
	switch (Port)
	{
	case 0:
 //3shan PINA di heya el feeha el value el mktoba
		return ((PINA&(1<<Pin))>>Pin);
		break;
	case 1:
		return ((PINB&(1<<Pin))>>Pin);
		break;
	case 2:
		return ((PINC&(1<<Pin))>>Pin);
		break;
	case 3:
		return ((PIND&(1<<Pin))>>Pin);
		break;
	}
}
