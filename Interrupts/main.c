/*
 * main.c
 *
 *  Created on: 28 Oct 2018
 *      Author: vvictor
 */

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

#include "lcd.h"
#include "keypad.h"

int main(void) {

	char keyPressed, oldKeyPressed = 0;

	lcdInit(); //Initializing the input and output pins of lcd
	keypadSetupPins(); //Initializing the input and output pins of keypad

	lcdWriteCommand(DISPLAY_ON | BLINK | UNDERLINE); //turning the display on
	lcdWriteCommand(CLEAR_DISPLAY); //clearing any garbage value

	//enable pin change interrupt on PORTC.Set bit1 of PCICR register
	PCICR |= (1 << PCIE1);

	//enable the pins on PORTC on which the interrupts are to be triggered
	PCMSK1 |= ((1 << PCINT8) | (1 << PCINT9) | (1 << PCINT10) | (1 << PCINT11));

	//globally enable interrupt
	sei();

	while (1) {

		sleep_mode();

		//globally disable interrupts before checking for key press
		cli();
		//changing the column values will trigger unwanted interrupts
		keyPressed = keypadGetKeyPressed();
		//reset the interrupt flags so that ISR is not triggered once interrupts are globally enabled
		PCIFR |= (1 << PCIF1);
		//re-enable interrupts
		sei();

		if ((keyPressed != 0) & (keyPressed != oldKeyPressed)) {
			if (keyPressed == '*') {
				//pressing * key acts as backspace
				lcdWriteCommand(CURSOR_SHIFT_LEFT);
				lcdWriteChar(' ');
				lcdWriteCommand(CURSOR_SHIFT_LEFT);
			} else if (keyPressed == '#') {
				//pressing # clears the display
				lcdWriteCommand(CLEAR_DISPLAY);
			} else {
				lcdWriteChar(keyPressed);
			}
		}
		oldKeyPressed = keyPressed; //storing the key pressed in latest iteration
		_delay_ms(20); //delay that accounts the debounce of switch

	}

}

ISR(PCINT1_vect) {

}

