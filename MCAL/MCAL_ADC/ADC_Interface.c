/*
 * ADC_Interface.c
 *
 *  Created on: Nov 5, 2023
 *      Author: Marii
 */

#include "ADC.h"
#include "ADC_CFG.h"

E_ERROR_TYPE MCAL_ADC_INIT(){
	E_ERROR_TYPE u8LocalError = E_OKAY;
	if(ADC_STATUS_ERROR!=E_OKAY){

	}
		else{
	ADMUX=0;
	switch(vref){
	case ADC_AREF:
		CLEAR_BIT(ADMUX, REFS1);
		CLEAR_BIT(ADMUX, REFS0);
		break;
	case ADC_VCC:
			CLEAR_BIT(ADMUX, REFS1);
			SET_BIT(ADMUX, REFS0);
			break;
	case ADC_V256:
			SET_BIT(ADMUX, REFS1);
			SET_BIT(ADMUX, REFS0);
			break;}

	ADCSRA&=0XF8;
	scaler&=0X07;
	ADCSRA=ADCSRA|scaler;
	SET_BIT(ADCSRA,ADEN);
	CLEAR_BIT(ADMUX, ADLAR);
}
	return u8LocalError;
}

u16 MCAL_ADC_READ(ADC_Channel_Type channel){

	ADMUX&=0XE0;
	ADMUX|=channel;
	SET_BIT(ADCSRA,ADSC);
	while(GET_BIT(ADCSRA,ADSC));

	return ADC;
}
