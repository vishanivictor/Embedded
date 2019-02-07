/*
 * main.c
 *
 *  Created on: 28 Oct 2018
 *      Author: vvictor
 */

#include <avr/io.h>
#include <util/delay.h>

#include "sr595.h"

int main(void) {

	uint8_t byteToSend = 0xFF; // hex code be displayed in LED
	sr595Init();      // Initialize shift register pins
	sr595Send(byteToSend);

	while (1) {}
}

