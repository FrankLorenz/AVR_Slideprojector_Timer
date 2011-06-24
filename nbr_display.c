/*
 * nbr_display.c
 *
 *  Created on: 22.06.2011
 *      Author: frank
 */


#include "nbr_display.h"


// combination
#define NUM_ERROR

void nbr_display_init ( )
{

}



void nbr_display_set_nbr ( uint8_t number )
{
	uint8_t pb = PORTB;
	uint8_t pd = PORTD;

	if ( number > 19 )
	{
		pb |=  ( (1<<PB1) | (1<<PB2) );
		pb &= ~( (1<<PB0) | (1<<PB6) );
		pd &= ~( (1<<PD0) | (1<<PD1) | (1<<PD3) );
	}
	else {
		if ( number >= 10 ) {
			number -= 10;
			PORTC |= (1<<PC4);
		}
		else {
			PORTC &= ~(1<<PC4);
		}
		if ( number == 1 ) {
			pb |=  ( (1<<PB0) | (1<<PB6) );
			pb &= ~( (1<<PB1) | (1<<PB2) );
			pd |=  ( (1<<PD0) | (1<<PD1) | (1<<PD3) );
		}
		else if ( number == 2 ) {
			pb |=  ( (1<<PB2) );
			pb &= ~( (1<<PB0) | (1<<PB1) | (1<<PB6) );
			pd &= ~( (1<<PD0) | (1<<PD1) );
			pd |=  ( (1<<PD3) );
		}
		else if ( number == 3 ) {
			pb &= ~( (1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB6) );
			pd &= ~( (1<<PD0) );
			pd |=  ( (1<<PD1) | (1<<PD3) );
		}
		else if ( number == 4 ) {
			pb |=  ( (1<<PB0) );
			pb &= ~( (1<<PB1) | (1<<PB2) | (1<<PB6) );
			pd &= ~( (1<<PD3) );
			pd |=  ( (1<<PD0) | (1<<PD1) );
		}
		else if ( number == 5 ) {
			pb |=  ( (1<<PB1) );
			pb &= ~( (1<<PB0) | (1<<PB2) | (1<<PB6) );
			pd &= ~( (1<<PD0) | (1<<PD3) );
			pd |=  ( (1<<PD1) );
		}
		else if ( number == 6 ) {
			pb |=  ( (1<<PB1) );
			pb &= ~( (1<<PB0) | (1<<PB2) | (1<<PB6) );
			pd &= ~( (1<<PD0) | (1<<PD1) | (1<<PD3) );
		}
		else if ( number == 7 ) {
			pb |=  ( (1<<PB6) );
			pb &= ~( (1<<PB0) | (1<<PB1) | (1<<PB2) );
			pd |=  ( (1<<PD0) | (1<<PD1) | (1<<PD3) );
		}
		else if ( number == 8 ) {
			pb &= ~( (1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB6) );
			pd &= ~( (1<<PD0) | (1<<PD1) | (1<<PD3) );
		}
		else if ( number == 9 ) {
			pb &= ~( (1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB6) );
			pd &= ~( (1<<PD0) | (1<<PD3) );
			pd |=  ( (1<<PD1) );
		}
		else if ( number == 0 ) {
			pb |=  ( (1<<PB6) );
			pb &= ~( (1<<PB0) | (1<<PB1) | (1<<PB2) );
			pd &= ~( (1<<PD0) | (1<<PD1) | (1<<PD3) );
		}
	}
	PORTB = pb;
	PORTD = pd;
}



void nbr_display_set_dot ( uint8_t on_off )
{
	if ( on_off )
		PORTB |= (1<<PB7);
	else
		PORTB &= ~(1<<PB7);
}
