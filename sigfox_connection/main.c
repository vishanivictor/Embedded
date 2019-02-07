/*
 * main.c
 *
 *  Created on: 17 Sep 2015
 *      Author: benjie
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

#include "dbg_putchar.h"
#include "usart.h"
#include "adc.h"
#include "millis.h"

#define ADC_CHANNEL 5
#define INTERRUPT_PIN 2
#define TIME_DELAY 20

void snocCmd(char cmdStr[]);

int main(void) {

	//enable pull-up on INT-0 pin(PD2)
	DDRD &= ~(1 << INTERRUPT_PIN);
	PORTD |= (1 << INTERRUPT_PIN);

	//configure for falling edge of IRQ
	EICRA |= (1 << ISC01);

	//enable INT0
	EIMSK |= (1 << INT0);

	//enable global INTs - 1 in I-bit of SREG
	sei();

	usartInit();
	dbg_tx_init();
	millisInit();
	adcInit(ADC_CHANNEL);

	//adding a delay before sending AT commands
	_delay_ms(1000);

	snocCmd("AT\n");
	snocCmd("AT\n");
	snocCmd("AT\n");

	while (1) {
		sleep_mode(); //CPU stops executing

	}

}

void snocCmd(char cmdStr[]) {
	char rxStr[20];
	uint8_t rxIndex = 0;
	uint8_t newLineReceived = 0;

	dbg_putStr(cmdStr);
	usartSendString(cmdStr);
	rxIndex = 0;

	while (!newLineReceived) {

		while (!usartCharReceived()) {

		}

		rxStr[rxIndex] = usartReadChar();
		if (rxStr[rxIndex] == '\n') {
			newLineReceived = 1;
			rxStr[rxIndex] = '\0';
		} else {
			rxIndex++;
		}
	}
	usartSendString(rxStr);
}


ISR(INT0_vect) {

	static uint32_t currentTime, lastISRRunTime = 0;
	currentTime = millis();

	if (currentTime - lastISRRunTime >= TIME_DELAY) {

		//clear EIFR flag in case of bounce
		if (EIFR & (1 << INTF0)) {
			EIFR |= (1 << INTF0);
		}

		if (!(PIND & (1 << 2))) { //PD2 (INT0) is low
			char myTempStr[17], outword[33], finalCommand[20]; //17:16+1, 33:16*2+1
			double currentTemp;
			uint16_t adcValue;
			adcValue = adcRead();
			currentTemp = ((5.0 / 1024) * adcValue) / 0.01; //((refVolt/steps)*code)/10mV = degree temp
			sprintf(myTempStr, "%.2lf", currentTemp);
			int len = strlen(myTempStr);
			if (myTempStr[len - 1] == '\n')
				myTempStr[--len] = '\0';

			for (int i = 0; i < len; i++) {
				sprintf(outword + i * 2, "%02X", myTempStr[i]);
			}

			sprintf(finalCommand, "AT$SF=%s\n", outword);
			snocCmd(finalCommand);
		}
		lastISRRunTime  = currentTime;
	}
}
