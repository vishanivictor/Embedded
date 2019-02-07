/*
 * adc.c
 *
 *  Created on: 14-Dec-2018
 *      Author: vishani
 */

#include <avr/interrupt.h>
#include <util/atomic.h>

#include "adc.h"

void adcInit(uint8_t channel) {
	//Make ADC5 an input pin
	DDRC &= ~(1 << channel);

	//Connect channel 5 to ADC (AD5 pin)
	ADMUX |= ((1 << MUX2) | (1 << MUX0));

	//use AVcc as ref voltage
	ADMUX |= (1 << REFS0);

	//8 bit result
	//ADMUX |= (1 << ADLAR);

	//128 prescale = 125kHz ADC clock
	ADCSRA |= ((1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2));

	//switch on ADC
	ADCSRA |= (1 << ADEN);
}

uint16_t adcRead(void) {
	uint16_t adcResult;
	//start conversion
	ADCSRA |= (1 << ADSC);

	//wait for ADC to complete
	//wait until ADSC bit goes low
	while (ADCSRA & (1 << ADSC)) {

	}

	//ADC is complete - grab result...
	adcResult = ADC;
	return adcResult;
}
