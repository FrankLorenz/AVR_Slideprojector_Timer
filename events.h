/*
 * events.h
 *
 *  Created on: 23.06.2011
 *      Author: frank
 */

#ifndef EVENTS_H_
#define EVENTS_H_

#include <avr/io.h>
#include "defines.h"


void events_init ( );

void set_event_flag ( uint16_t flag );

void eval_event_flags ( );

#endif /* EVENTS_H_ */
