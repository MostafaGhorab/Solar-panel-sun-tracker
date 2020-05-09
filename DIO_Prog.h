/*
 * DIO_Prog.h
 *
 *  Created on: Aug 17, 2018
 *      Author: user
 */
#include "std_types.h"
#ifndef DIO_PROG_H_
#define DIO_PROG_H_

u8 DIO_u8GetPortValue(u8 Port);
void DIO_SetPortValue(u8 Port,u8 Val);
void DIO_SetPortDirection(u8 Port,u8 Direction);
void DIO_SetPinDirection(u8 Port,u8 Pin,u8 direc);
void DIO_SetPinVal(u8 Port,u8 Pin,u8 Val);
u8 DIO_u8GetPinVal(u8 Port,u8 Pin);
#endif /* DIO_PROG_H_ */
