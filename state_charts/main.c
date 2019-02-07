/*
 * main.c
 *
 *  Created on: 17 Sep 2015
 *      Author: benjie
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/sleep.h>
#include <stdbool.h>
#include <stdio.h>

#include "millis.h"
#include "keypad.h"
#include "usart.h"
#include "adc.h"

#include "sc_timer/sc_timer_service.h"
#include "src-gen/State_chart.h"

#define KEY_SCAN_INTERVAL 20
#define LDR_THRESHOLD 100
#define ADC_CHANNEL 5

static State_chart sc;

int main(void) {

	millisInit();
	keypadSetupPins();
	usartInit();
	adcInit(ADC_CHANNEL);

	sc_timer_setup();  //setup the statechart timers
	state_chart_init(&sc); //initialize statechart
	state_chart_enter(&sc); //enter the statechart

	char array[5];
	static char keypressed, oldkeypressed = 0;			//initializing variables
	uint16_t adcOut;
	bool keyModeActive = false;

	DDRB |= (1 << 5);
	uint32_t nextScanTime = millis() + KEY_SCAN_INTERVAL;

	while (1) {

		sleep_mode()
		;

		if (millis() >= nextScanTime) {

			keypressed = keypadGetKeyPressed();

			if ((keypressed != 0) && (keypressed != oldkeypressed)) {
				if (keypressed == '1') {
					keyModeActive = false;
					state_chartIface_raise_key_on(&sc);
				}

				else if (keypressed == '2') {
					keyModeActive = false;
					state_chartIface_raise_key_off(&sc);
				}

				else if (keypressed == '3') {
					keyModeActive = !keyModeActive;
					state_chartIface_raise_key_mode(&sc);
				}
			}

			oldkeypressed = keypressed;
			nextScanTime = millis() + KEY_SCAN_INTERVAL;

		}

		if (keyModeActive) {
			usartSendString(" LDR Threshold is ");
			sprintf(array, "%i", LDR_THRESHOLD);
			usartSendString(array);
			usartSendChar('\n');
			adcOut = adcRead();
			usartSendString(" Value from ADC ");
			sprintf(array, "%i", adcOut);
			usartSendString(array);
			if (adcOut < LDR_THRESHOLD) {
				state_chartIface_raise_dark(&sc);

			} else {
				state_chartIface_raise_bright(&sc);

			}
		}
		sc_timer_increment(KEY_SCAN_INTERVAL);
		state_chart_runCycle(&sc);
	}

}

//Functions from State_chartRequired.h
void state_chartIface_setLight(const State_chart* handle,
		const sc_boolean lightOn) {
	if (lightOn)
		PORTB |= (1 << 5);
	else
		PORTB &= ~(1 << 5);
}

