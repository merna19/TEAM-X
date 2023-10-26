/*
 * stdFunc.c
 *
 * Created: 10/26/2023 3:45:58 PM
 *  Author: LENOVO
 */ 
#include "stdFunc.h"

void SET_CLR(S_std* S_reg)
{	
	unsigned char Mask1,Mask2;
	Mask1 = ((S_reg->port) & (~(S_reg->pins)));
	Mask2 = ((S_reg->pins) & (S_reg->dir));
	S_reg->port = Mask1 | Mask2;
}