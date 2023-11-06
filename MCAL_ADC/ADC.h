/*
 * ADC.h
 *
 *  Created on: Nov 5, 2023
 *      Author: Marii
 */

#ifndef ADC_ADC_H_
#define ADC_ADC_H_

#include "ADC_CFG.h"
#include "ADC_Private.h"
#include "ADC_Registers.h"
#include "ADC_TYPES.h"


E_ERROR_TYPE MCAL_ADC_INIT();

u16 MCAL_ADC_READ(ADC_Channel_Type channel);

#endif /* ADC_ADC_H_ */
