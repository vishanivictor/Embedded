/*
 * keypad.c
 *
 *  Created on: 02-Nov-2018
 *      Author: vishani
 */
/*
 * Set up the keypad pin directions, pull up resistors
 * and drive the column pins low.
 */

#include "keypad.h"

/*
 * setting up the keypad pins in arduino
 */
void keypadSetupPins(void) {

	//setting column pins as output pins
	COL_DIR |= ((1 << COL_1_PIN) | (1 << COL_2_PIN) | (1 << COL_3_PIN));

	//setting row pins as input pins
	ROW_DIR &= ~((1 << ROW_1_PIN) | (1 << ROW_2_PIN) | (1 << ROW_3_PIN)
			| (1 << ROW_4_PIN));

	//enable pull-up resistors on row pins
	ROW_PORT |= ((1 << ROW_1_PIN) | (1 << ROW_2_PIN) | (1 << ROW_3_PIN)
			| (1 << ROW_4_PIN));

    //initializing column ports with 0's
	COL_PORT &= ~((1<<COL_1_PIN)|(1<<COL_2_PIN)|(1<<COL_3_PIN));

}

/*
 * Scan the keypad to determine which key is pressed.
 * Returns 0 if no key pressed and returns ascii code if key pressed.
 * Sets all the cols to low when done.
 */
char keypadGetKeyPressed(void) {

	char retVal = 0;

	//sending 011 on columns
	COL_PORT &= ~(1 << COL_1_PIN); //send  0 on column 1
	COL_PORT |= ((1 << COL_2_PIN) | (1 << COL_3_PIN)); //send 1's on column 2 and 3

	//adding delay so that values get propagated to the hardware
	_delay_us(1);

	//testing column 1 row 1
	if (!(ROW_INPUT & (1 << ROW_1_PIN))) {
		//there is a 0 on row pin indicating key 1 is pressed
		retVal = '1';
	}

	//testing column 1 row 2
	if (!(ROW_INPUT & (1 << ROW_2_PIN))) {
		//there is a 0 on row pin indicating key 4 is pressed
		retVal = '4';
	}

	//testing column 1 row 3
	if (!(ROW_INPUT & (1 << ROW_3_PIN))) {
		//there is a 0 on row pin indicating key 7 is pressed
		retVal = '7';
	}

	//testing column 1 row 4
	if (!(ROW_INPUT & (1 << ROW_4_PIN))) {
		//there is a 0 on row pin indicating key * is pressed
		retVal = '*';
	}

	COL_PORT &= ~((1 << COL_2_PIN) | (1 << COL_3_PIN));//setting the column ports back to zero

	//sending 101 on columns
	COL_PORT &= ~(1 << COL_2_PIN); //send  0 on column 2
	COL_PORT |= ((1 << COL_1_PIN) | (1 << COL_3_PIN)); //send 1's on column 1 and 3

	//adding delay so that values get propagated to the hardware
	_delay_us(1);

	//testing column 2 row 1
	if (!(ROW_INPUT & (1 << ROW_1_PIN))) {
		//there is a 0 on row pin indicating key 2 is pressed
		retVal = '2';
	}

	//testing column 2 row 2
	if (!(ROW_INPUT & (1 << ROW_2_PIN))) {
		//there is a 0 on row pin indicating key 5 is pressed
		retVal = '5';
	}

	//testing column 2 row 3
	if (!(ROW_INPUT & (1 << ROW_3_PIN))) {
		//there is a 0 on row pin indicating key 8 is pressed
		retVal = '8';
	}

	//testing column 2 row 4
	if (!(ROW_INPUT & (1 << ROW_4_PIN))) {
		//there is a 0 on row pin indicating key 0 is pressed
		retVal = '0';
	}

	COL_PORT &= ~((1 << COL_1_PIN) | (1 << COL_3_PIN));//setting the column ports back to zero

	//sending 110 on columns
	COL_PORT &= ~(1 << COL_3_PIN); //send  0 on column 3
	COL_PORT |= ((1 << COL_1_PIN) | (1 << COL_2_PIN)); //send 1's on column 2 and 3

	//adding delay so that values get propagated to the hardware
	_delay_us(1);

	//testing column 3 row 1
	if (!(ROW_INPUT & (1 << ROW_1_PIN))) {
		//there is a 0 on row pin indicating key 3 is pressed
		retVal = '3';
	}

	//testing column 3 row 2
	if (!(ROW_INPUT & (1 << ROW_2_PIN))) {
		//there is a 0 on row pin indicating key 6 is pressed
		retVal = '6';
	}

	//testing column 3 row 3
	if (!(ROW_INPUT & (1 << ROW_3_PIN))) {
		//there is a 0 on row pin indicating key 9 is pressed
		retVal = '9';
	}

	//testing column 3 row 4
	if (!(ROW_INPUT & (1 << ROW_4_PIN))) {
		//there is a 0 on row pin indicating key # is pressed
		retVal = '#';
	}

	COL_PORT &= ~((1 << COL_1_PIN) | (1 << COL_2_PIN)); //setting the column ports back to zero

	return retVal;

}

