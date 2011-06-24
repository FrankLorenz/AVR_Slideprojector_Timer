/*
 * dia_cntrl.h
 *
 *  Created on: 23.06.2011
 *      Author: frank
 */

#ifndef DIA_CNTRL_H_
#define DIA_CNTRL_H_


void dia_cntrl_init ( );

void dia_cntrl_tick ( );

void dia_cntrl_on_off ( uint8_t on_off );

uint8_t dia_cntrl_get_active ( );

void dia_cntrl_set_seconds ( uint8_t seconds );


#endif /* DIA_CNTRL_H_ */
