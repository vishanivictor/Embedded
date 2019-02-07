/*
 * main.c
 *
 *  Created on: 21 Oct 2018
 *      Author: vvictor
 */

#include <avr/io.h>
#include <util/delay.h>
//defining the output values
#define NUM_0 0x3F
#define NUM_1 0x06
#define NUM_2 0x5B
#define NUM_3 0x4F
#define NUM_4 0x66
#define NUM_5 0x6D
#define NUM_6 0x7D
#define NUM_7 0x07
#define NUM_8 0x7F
#define NUM_9 0x6F
#define CHAR_A 0x77

//defining the total number of expected outputs
#define TOTAL_OUTPUTS 11

int main(void) {

	uint8_t currentValue, oldValue = 1, counter = 0; //variable declaration
	DDRD = 0xFF; //PORT D is set as output port
	DDRB &= ~(1 << 4); //PB4 as input pin – button
	PORTB |= (1 << 4); //switch on pullup resistor for PB4
	PORTD = NUM_0; //setting default value to 0

	while (1) {

		currentValue = PINB & (1 << 4); //setting value of PB4 to currentValue

		if (currentValue == 0 && oldValue != 0) //check if button is pressed
		   {
			counter++; // incrementing the count of button press

			switch (counter) {
			case 1:
				PORTD = CHAR_A;
				break;
			case 2:
				PORTD = NUM_9;
				break;
			case 3:
				PORTD = NUM_8;
				break;
			case 4:
				PORTD = NUM_7;
				break;
			case 5:
				PORTD = NUM_6;
				break;
			case 6:
				PORTD = NUM_5;
				break;
			case 7:
				PORTD = NUM_4;
				break;
			case 8:
				PORTD = NUM_3;
				break;
			case 9:
				PORTD = NUM_2;
				break;
			case 10:
				PORTD = NUM_1;
				break;
			case 11:
				PORTD = NUM_0;
				break;
			default:
				PORTD = NUM_0;
				break;
			}

			//resetting the counter value once the maximum count is reached
			if (counter == TOTAL_OUTPUTS) {
				counter = 0;
			}

		}
		_delay_ms(20); //debounce the button press
		oldValue = currentValue;
	}
}

