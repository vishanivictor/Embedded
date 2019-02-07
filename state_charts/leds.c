	/*
	 * leds.c
	 *
	 *  Created on: 20-Nov-2018
	 *      Author: vishani
	 */

	#include <avr/io.h>
	#include "leds.h"

	void ledsInit(void) {
		DDRB |= (1 << 5);

	}
	void ledOn(void) {
		PORTB |= (1 << 5);
	}
	void ledOff(void) {
		PORTB &= ~(1 << 5);
	}
