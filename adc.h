/*
 * adc.h
 *
 *  Created on: 23.06.2011
 *      Author: frank
 */

#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

void adc_init ( );

uint16_t adc_get_value ( );

#endif /* ADC_H_ */
