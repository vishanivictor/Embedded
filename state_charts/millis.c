/*
 * millis.c
 *
 *  Created on: 13-Nov-2018
 *      Author: vishani
 */

# include <avr/interrupt.h>
# include "millis.h"

// In this case the static keyword means that while the elapsedMillis variable
// is a global variable it is only visible in this file (millis.c) i.e.
// It is accessable by all funcions in this file only.
static uint32_t elapsedMillis;

/*
 *ISR for timer compare register
 */
ISR(TIMER0_COMPA_vect) {
	//static variable in isr 'lastISRRunTime'. if diff is less than 20ms , do nothing
	elapsedMillis++;
}

/*
 * This function should set up timer 0 to expire at some sub-muliple of 1mS.
 * Use mode 2 - CTC
 * Enable the comparison interrupt (OCIE0A)
 * Load the OCR0A with the correct value
 * Initialise elapsedMillis to zero.
 * Set correct prescale and start timer.
 */
void millisInit(void) {
	elapsedMillis=0;
	TCCR0A |= (1 << WGM01); // Configure timer 0 for CTC mode
	TIMSK0 |= (1 << OCIE0A); // Enable CTC interrupt
	sei();// Enable global interrupts
	OCR0A = 249; // Set CTC compare value to 1000Hz at 16 MHz AVR clock , with a prescaler of 64
	TCCR0B |= ((1 << CS01) | (1 << CS00)); // Start timer at Fcpu /64

}

/* This function should return the number of milliseconds passed since
 * the millisInit() function was called.
 * The count of elapsedMillis is incremented by an ISR.
 */
uint32_t millis(void) {
	/* Question: What happens if the ISR runs in the middle of accessing your
	 * uint32_t elapsedMillis count variable?
	 * Do you need to do anything to ensure this function works correctly in
	 * that case?
	 */
	 uint32_t localmillis;
	 cli();
	 localmillis = elapsedMillis;
	 sei();
	 return localmillis;
}

