/*
 * adc.c
 *
 *  Created on: 23.06.2011
 *      Author: frank
 */

#include <avr/io.h>

#include "defines.h"

#include "adc.h"


void adc_init ( )
{
	// voltage reference: AVcc, select ADC0 input
	ADMUX = (1<<REFS0);
	// enable ADC in free running mode with prescaler == XTAL/32
	ADCSRA = (1<<ADEN) | (1<<ADSC) | (1<<ADFR) | (1<<ADPS2) | (1<<ADPS0);
	return;
}

uint16_t adc_get_value ( )
{
	return ADC;
}
