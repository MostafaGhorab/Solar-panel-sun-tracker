/*
 * utils.h

 *
 *  Created on: Aug 11, 2018
 *      Author: user
 */

#ifndef UTILS_H_
#define UTILS_H_
#define SET_BIT(Var,BitNo)    Var |=  (1 << (BitNo))
#define CLR_BIT(Var,BitNo)    Var&=~(1<<(BitNo))
#define TOG_BIT(Var,BitNo)    Var ^=  (1 << (BitNo))
#define set_nibble_H(reg)        reg|= 0xF0
#define set_nibble_L(reg)        reg|= 0x0F
#define reset_nibble_H(reg)     reg&= 0x0F
#define reset_nibble_L(reg)     reg&=  0xF0
#define set_nibvalue_L(reg,val)  reg&=  0xF0;\
											reg|=val
#define set_nibvalue_H(reg,val)  reg&= 0x0F;\
                                            reg|=(val<<(4))
#define get_bit(reg,bitno)  (reg&(1<<bitno))>>bitno


#endif /* UTILS_H_ */
