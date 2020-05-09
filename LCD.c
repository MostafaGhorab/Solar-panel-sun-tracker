/*
 * LCD.c
 *
 *  Created on: Aug 17, 2018
 *      Author: user
 */
#include "DIO_Prog.h"
#include "LCD.h"
#include "util\delay.h"
#include "std_types.h"
void LCD_WriteCommand(u8 command)
{
	DIO_SetPinVal(LCD_ConPort,RS,0);
	DIO_SetPinVal(LCD_ConPort,RW,0);
	DIO_SetPortValue(LCD_Port,command);
	DIO_SetPinVal(LCD_ConPort,E,1);
	_delay_ms(1);
	DIO_SetPinVal(LCD_ConPort,E,0);
}

void LCD_int(void)   //read the datasheet
{
	_delay_ms(50);
	LCD_WriteCommand(0b00110011); //2 line command
	_delay_ms(1);
	LCD_WriteCommand(0b00001100);
	_delay_ms(1);
	LCD_WriteCommand(0b00000001);
	_delay_ms(2);
	LCD_WriteCommand(0b00000110);
}
void LCD_WriteData(u8 data)
{
	DIO_SetPinVal(LCD_ConPort,RS,1);
	DIO_SetPinVal(LCD_ConPort,RW,0);
	DIO_SetPortValue(LCD_Port,data);
	DIO_SetPinVal(LCD_ConPort,E,1);
	_delay_ms(1);
	DIO_SetPinVal(LCD_ConPort,E,0);
}
void LCD_WriteStringNum(u16 variable)
{
	//AS THE MAX NUMBER THAT CAN BE WRITTEN AS U16 IS 65536 SO THE MAX ARRAY ELEMENTS IS 5
	u8 ASCIIArr[6];
	u16 temp;
	u8 j=0;
	u8 rem;
	temp=variable;
	if(temp==0)
	{
		LCD_WriteData('0');
	}
	else
	{
	while(temp>0)
	{
		rem=(temp%10);
		ASCIIArr[j]=rem+'0';
		temp=temp/10;
		j++;
	}
	/*for(i=(j-1);i>=0;i--)
	{
		LCD_WriteData(ASCIIArr[i]);
		_delay_ms(1);
	}*/
	while(j>0)
	{
		LCD_WriteData(ASCIIArr[j-1]);
		_delay_ms(1);
		j--;
	}
	}

}
void LCD_WriteString(u8 arr[50])
{
	u8 i=0;
while(arr[i]!='\0')
{
	LCD_WriteData(arr[i]);
	i++;
}
}
