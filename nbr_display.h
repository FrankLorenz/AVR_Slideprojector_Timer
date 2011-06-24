/*
 * nbr_display.h
 *
 *  Created on: 22.06.2011
 *      Author: frank
 */

#ifndef NBR_DISPLAY_H_
#define NBR_DISPLAY_H_

#include <avr/io.h>

void nbr_display_init ( );

void nbr_display_set_nbr ( uint8_t number );

void nbr_display_set_dot ( uint8_t on_off );

#endif /* NBR_DISPLAY_H_ */
