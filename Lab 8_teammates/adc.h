/*
 * ADC.h
 *
 *  Created on: Mar 22, 2023
 *      Author: lgossman
 */

#ifndef ADC_H_
#define ADC_H_

#include <inc/tm4c123gh6pm.h>

void ADC0_InitSWTriggerSeq3_Ch9(void);

uint32_t ADC0_InSeq3(void);

#endif /* ADC_H_ */
