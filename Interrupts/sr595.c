/*
 * sr595.c
 *
 *  Created on: 05-Nov-2018
 *      Author: vishani
 */

#include "sr595.h"

void sr595Init(void) {
	DDRD |= ((1 << DATA_PIN) | (1 << CLOCK_PIN) | (1 << LATCH_PIN));
}

void sr595Send(uint8_t byteToSend) {

	//clearing everything in data pin
	OUTPUT_PORT &= ~(1 << DATA_PIN);

	// latch pin is set to low so that the shift register listens to its 8 parallel inputs
	OUTPUT_PORT &= ~(1 << LATCH_PIN);

	for (int i = 0; i < 8; i++) {
		//prepare shift register for bit shifting
		OUTPUT_PORT &= ~(1 << CLOCK_PIN);

		//checking the value passed to byteToSend and the bitmask
		if (byteToSend & (1 << i)) {
			OUTPUT_PORT |= (1 << DATA_PIN);
		} else {
			OUTPUT_PORT &= ~(1 << DATA_PIN);
		}

		//register shifts bits when cloak pin is set
		OUTPUT_PORT |= (1 << CLOCK_PIN);

		//setting data pin to low to prevent bleed through
		OUTPUT_PORT &= ~(1 << DATA_PIN);

	}
	// latch pin is set to high so that the shift register no longer listens to input
	OUTPUT_PORT |= (1 << LATCH_PIN);
}
