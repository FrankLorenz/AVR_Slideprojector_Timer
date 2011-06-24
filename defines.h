/*
 * defines.h
 *
 *  Created on: 13.06.2011
 *      Author: frank
 */

#ifndef DEFINES_H_
#define DEFINES_H_


#endif /* DEFINES_H_ */


// timer defines

#define TMR_COMPARE_MATCH	(uint16_t) (F_CPU*0.01)	// 10 milliseconds

#define DIA_FWD	PC5

// event flags
#define	TIMER1_EVT	 (uint16_t) 0x0001		// timer 1 compare match
#define TICK_EVT	 (uint16_t) 0x0002		// triggered once a second
#define KEYPRESS_EVT (uint16_t) 0x0004		// key pressed by user

// ADC -> second calculation constants
#define ADC_SEC_DISTANCE	54
#define ADC_SEC_MAXSECONDS  19
