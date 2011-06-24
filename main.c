#include <avr/io.h>
#include <avr/interrupt.h>

#include "defines.h"
#include "events.h"
#include "timer.h"
#include "adc.h"
#include "dia_cntrl.h"


static void init_uc ( );
static void init_ports ( );
static void init_ext_irq ( );





int main ( )
{
	init_uc ( );
	sei ( );

	while ( 1 ) {
		eval_event_flags ( );
	}
	return 0;
}



static void init_uc ( )
{
	// config ports
	init_ports ( );

	// conifg timer
	timer_init ( );

	// config the ADC
	adc_init ( );

	// configure external interrupt request (keypress)
	init_ext_irq ( );

	events_init ( );

	dia_cntrl_init ( );

	return;
}



// configures the general I/O ports
static void init_ports ( )
{
	// 7 segment outputs on Port C
	PORTB = (1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB6) | (1<<PB7);
	DDRB =  (1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB6) | (1<<PB7);

	// 7 segment outputs on port D and input tact switch pull up (PD2)
	PORTD = (1<<PD0) | (1<<PD1) | (1<<PD2) | (1<<PD3);
	DDRD  = (1<<PD0) | (1<<PD1) | (1<<PD3);

	// the red "10" LED and the output driver ("forward one slide")
	DDRC = (1<<PC4) | (1<<PC5);

	return;
}



static void init_ext_irq ( )
{
	MCUCR |= (1<<ISC01);		// falling edge for INT0
	GICR  |= (1<<INT0);			// enable INT0
}




ISR ( SIG_OUTPUT_COMPARE1A ) {

	set_event_flag ( TIMER1_EVT );

	return;
}


ISR ( SIG_INTERRUPT0 ) {
	set_event_flag ( KEYPRESS_EVT );
}

