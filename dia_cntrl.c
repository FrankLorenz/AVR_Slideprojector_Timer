/*
 * dia_cntrl.c
 *
 *  Created on: 23.06.2011
 *      Author: frank
 */

#include <avr/io.h>
#include <util/delay.h>
#include "dia_cntrl.h"
#include "defines.h"
#include "nbr_display.h"


static uint8_t seconds_elapsed;
static uint8_t seconds_delay;
static uint8_t enabled;

static void trigger_forward ( );




void dia_cntrl_init ( )
{
	seconds_elapsed = 0;
	seconds_delay = 6;
	enabled = 0;
}


void dia_cntrl_tick ( )
{
	if ( enabled ) {
		seconds_elapsed++;
		if ( seconds_elapsed >= seconds_delay ) {
			seconds_elapsed = 0;
			trigger_forward ( );
		}
	}
}



void dia_cntrl_on_off ( uint8_t on_off )
{
	if ( on_off )
		enabled = 1;
	else
		enabled = 0;
}



uint8_t dia_cntrl_get_active ( )
{
	return enabled;
}



void dia_cntrl_set_seconds ( uint8_t seconds )
{
	if ( !enabled ) {
		nbr_display_set_nbr ( 0 );
		return;
	}

	if ( seconds > 0 ) {
		seconds_delay = seconds;
		nbr_display_set_nbr ( seconds );
	}
	return;
}



static void trigger_forward ( )
{
	PORTC |= (1<<PC5);
	_delay_ms ( 100 );
	PORTC &= ~(1<<PC5);
	return;
}
