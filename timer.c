/*
 * timer.c
 *
 *  Created on: 13.06.2011
 *      Author: frank
 */

#include "defines.h"
#include "timer.h"
#include "events.h"

#include <avr/io.h>

static uint8_t tick_cnt;


void timer_init ( )
{
	// Timer 1 (16 Bit):
	// mode 4 (CTC, Top == OCR1A), clkIO/1,
	// Output Compare Match A IRQ enabled (IRQ every 10 ms at 1 MHz clk_IO)
	OCR1A = TMR_COMPARE_MATCH;	// 10000 (base10)
	TCCR1A = 0x00;
	TCCR1B = (1<<WGM12) | (1<<CS10);
	TIMSK = (1<<OCIE1A);
	return;

	tick_cnt = 0;
	return;
}

void timer_tick ( )
{
	tick_cnt++;

	if ( tick_cnt == 100 ) {
		tick_cnt = 0;
		set_event_flag ( TICK_EVT );

	}
	return;
}
