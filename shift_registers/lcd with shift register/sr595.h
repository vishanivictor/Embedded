/*
 * sr595.h
 *
 *  Created on: 05-Nov-2018
 *      Author: vishani
 */

#ifndef SR595_H_
#define SR595_H_

#include <avr/io.h>
#include <util/delay.h>

#define DATA_PIN 4
#define LATCH_PIN 5
#define CLOCK_PIN 6
#define OUTPUT_PORT PORTD

void sr595Init(void); //Set up pin directions

void sr595Send(uint8_t byteToSend); //Send the passed byte via the shift register

#endif /* SR595_H_ */
