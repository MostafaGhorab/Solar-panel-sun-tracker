/*
 * LCD.h
 *
 *  Created on: Aug 17, 2018
 *      Author: user
 */
#include "std_types.h"
#include "DIO_Prog.h"
#ifndef LCD_H_
#define LCD_H_
//PORTC IS THE DATA PORT
#define LCD_Port 2 //C
#define LCD_ConPort 3  //D
#define RS 5 //PINnums
#define RW 6
#define E 7
void LCD_WriteData(u8 data);
void LCD_int(void);
void LCD_WriteCommand(u8 command);
void LCD_WriteStringNum(u16 variable);
void LCD_WriteString(u8 arr[50]);

#endif /* LCD_H_ */
