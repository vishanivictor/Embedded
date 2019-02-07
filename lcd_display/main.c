/*
 * main.c
 *
 *  Created on: 28 Oct 2018
 *      Author: vvictor
 */

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "lcd.h"

int main(void) {

	lcdInit();//Initializing the input and output pins
	lcdWriteCommand(DISPLAY_ON);//turning the display on
	lcdWriteCommand(CLEAR_DISPLAY);//clearing any garbage value
	lcdWriteCommand(TWO_LINE_MODE);//setting the display to 2 line mode

	lcdWriteString(DISPLAY_STRING);
	lcdWriteCommand(SET_ADDRESS | 0x40);//enabling the second line in LCD
	lcdWriteString(DISPLAY_STRING);

	//getting the number of times the display string should be looped
	uint8_t loopCount = LCD_DISPLAY_LENGTH - strlen(DISPLAY_STRING);

	while (1) {

		uint8_t i = 0; //Initialize a variable i

		//loop till the word is shifted to the right end of the lcd display
		while (i < loopCount) {
			lcdWriteCommand(DISPLAY_SHIFT_RIGHT);
			i++;
			_delay_ms(250);
		}

		//loop to shift the word back to the left end of the display
		while (i > 0) {
			lcdWriteCommand(DISPLAY_SHIFT_LEFT);
			i--;
			_delay_ms(250);
		}
	}
}

