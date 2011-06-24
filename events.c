/*
 * events.c
 *
 *  Created on: 23.06.2011
 *      Author: frank
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "events.h"
#include "timer.h"
#include "adc.h"
#include "nbr_display.h"
#include "dia_cntrl.h"



static uint16_t event_flags;
static uint8_t nbr;

static void set_seconds_from_adc ( uint16_t adc_val );



void events_init ( )
{
	event_flags = 0;

	nbr = 0;
}



void set_event_flag ( uint16_t flag )
{
	cli ( );
	event_flags |= flag;
	sei ( );
	return;
}



void eval_event_flags ( )
{
	uint16_t evt_tmp;
	uint16_t adc_val;


	cli();
	evt_tmp = event_flags;
	event_flags = 0;
	sei ( );

	if ( evt_tmp & TIMER1_EVT ) {
		timer_tick ( );
		// read ADC
		adc_val = adc_get_value ( );
		set_seconds_from_adc ( adc_val );

	}

	if ( evt_tmp & TICK_EVT ) {
		dia_cntrl_tick ( );
		nbr_display_set_dot ( nbr % 2 );
		nbr++;
	}

	if ( evt_tmp & KEYPRESS_EVT ) {
		if ( dia_cntrl_get_active () )
			dia_cntrl_on_off ( 0 );
		else
			dia_cntrl_on_off ( 1 );
	}
}



static void set_seconds_from_adc ( uint16_t adc_val )
{
	uint8_t cnt = 0;
	uint16_t upper_limit = ADC_SEC_DISTANCE-1;
	uint8_t seconds;

	for ( cnt=0; cnt<ADC_SEC_MAXSECONDS; cnt++ ) {
		if ( adc_val < upper_limit ) {
		    seconds = cnt+1;
			break;
		}
		upper_limit += ADC_SEC_DISTANCE;
	}

	dia_cntrl_set_seconds ( seconds );
}
