/*
 * stdFunc.h
 *
 * Created: 10/26/2023 3:46:19 PM
 *  Author: MERNA
 */ 


#ifndef STDFUNC_H_
#define STDFUNC_H_

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct bit
{
	u8 b0:1;
	u8 b1:1;
	u8 b2:1;
	u8 b3:1;
	u8 b4:1;
	u8 b5:1;
	u8 b6:1;
	u8 b7:1;
}bit;

typedef union reg
{
	
	u8 REGISTER;
	bit BIT;
}reg;


typedef struct S_std
{
	unsigned char pins;
	unsigned char port;
	unsigned char dir;//SET=0xFF	CLR=0x00	
}S_std;

typedef u8 ERROR_CHECK;
 
void SET_CLR(S_std* S_reg);




#endif /* STDFUNC_H_ */