/*
 * main.c
 *
 *  Created on: Feb 18, 2019
 *      Author: user
 */
#include"std_types.h"
#define F_CPU 12000000
#include "util\delay.h"
#include "LCD.h"
#include"DIO_Prog.h"
#include"ADC.h"
#include"utils.h"
#include <avr/interrupt.h>
#include"Timer.h"
u8 ADC0;
u8 ADC1;
u8 ADC2;
u8 ADC3;
u8 Result0;
u8 Result1;
u8 Result2;
u8 Result3;
u8 angle_srv1=180;
u8 angle_srv2=90;
u8 COUNT1=0;  //COUNTS THE NUMBER OF OVERFLOWS
u8 flag=0; //for the pwm generating
u16 ONTIME1;
u16 ONTIME2;
u8 COUNT2=0;
u8 flag2=0;
void Servo_Angle1( u8 angle);
void Servo_Angle2( u8 angle);
void main()
{
	//ADC CHANNELS PINS CONFIG
	DIO_SetPinDirection(0,0,0);
	DIO_SetPinDirection(0,1,0);
	DIO_SetPinDirection(0,2,0);
	DIO_SetPinDirection(0,3,0);
	// O/P PINS FOR THE SERVO
	DIO_SetPinDirection(3,0,1);
	DIO_SetPinDirection(3,1,1);
	//INITIALIZE THE SERVO WITH 90 DEGREES
	ADC_VidInit();
	//LCD_int();
	VidNormTimer();

	while(1)
	{
		ADC0=ADC_u8GetADCReading(0);
		ADC1=ADC_u8GetADCReading(1);
		ADC2=ADC_u8GetADCReading(2);
		ADC3=ADC_u8GetADCReading(3);
		Result0=(ADC0+ADC3)-(ADC1+ADC2);
		Result1=(ADC1+ADC2)-(ADC0+ADC3);
		Result2=(ADC0+ADC1)-(ADC2+ADC3);
		Result3=(ADC2+ADC3)-(ADC0+ADC1);
		_delay_ms(50);

//===============================LEFT/RIGHT CONTROL============================================
		if((Result0>=20)&&((ADC0+ADC3)>(ADC1+ADC2)))
		{
			if(angle_srv1!=0)
			{
				angle_srv1=angle_srv1-1; //IF THE LEFT HAS MORE LIGHT THAN THE RIGHT GO LEFT
			}
		}
		else if((Result1>=20)&&((ADC1+ADC2)>(ADC0+ADC3)))
		{
			if (angle_srv1<180)
			{
				angle_srv1=angle_srv1+1; //IF THE RIGHT HAS MORE LIGHT THAN THE LEFT GO RIGHT
			}
		}
		else{}
//============================UP/DOWN CONTROL===================================================
		if((Result2>=20)&&((ADC0+ADC1)>(ADC2+ADC3)))
		{
			if(angle_srv2<=180)
			{
				angle_srv2=angle_srv2+1; //GO UP
			}
		}
		else if((Result3>=20)&&((ADC2+ADC3)>(ADC0+ADC1)))
		{
			if (angle_srv2!=0)
			{
				angle_srv2=angle_srv2-1;  //GO DOWN
			}
		}
		else{}
		Servo_Angle1(angle_srv1);
		Servo_Angle2(angle_srv2);
		//_delay_ms(10);
	}
}
//}

//RANGE OF SERVO ONTIME FROM 4 TO 13 ,SMALL NUMBERS MOVE IT CW,LARGE ACW
ISR(TIMER0_OVF_vect)
{
	COUNT1++;
	COUNT2++;
	//=================================SERVO1=======================================
	if(COUNT1<=ONTIME1)
	{
		flag=1;
	}
	else // MEANS THAT I'VE BEEN ON FOR 'ONTIME' MILLISECONDS
	{
		flag=0;
		if(COUNT1==117)    //117  is no of overflows needed for 20 ms
		{
			COUNT1=0;
		}
	}
	if(flag==1)
	{
		DIO_SetPinVal(3,0,1);
	}
	else if(flag==0)
	{
		DIO_SetPinVal(3,0,0);
	}
	//============================SERVO2=================================
	if(COUNT2<=ONTIME2)
	{
		flag2=1;
	}
	else // MEANS THAT I'VE BEEN ON FOR 'ONTIME' MILLISECONDS
	{
		flag2=0;
		if(COUNT2==117)    //117  is no of overflows needed for 20 ms
		{
			COUNT2=0;
		}
	}
	if(flag2==1)
	{
		DIO_SetPinVal(3,1,1);
	}
	else if(flag2==0)
	{
		DIO_SetPinVal(3,1,0);
	}
}


void Servo_Angle1( u8 angle)
{
	f32 addedtime; //is the time to 1ms to conrol servo duty cycle
	addedtime=(float)angle/180;
	addedtime=(addedtime+1);
	ONTIME1=((int)(addedtime/0.15)); //0.15 is the overflow time of my timer0
}
void Servo_Angle2( u8 angle)
{
	f32 addedtime; //is the time to 1ms to conrol servo duty cycle
	addedtime=(float)angle/180;
	addedtime=(addedtime+1);
	ONTIME2=((int)(addedtime/0.15)); //0.15 is the overflow time of my timer0
}
