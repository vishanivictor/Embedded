/*
 * lcd.c
 * Created on: 28 Oct 2018
 * Author: vvictor
 */

#include "lcd.h"

/*
 * This method initialises the LCD
 */
void lcdInit(void) {
	LCD_DATA_DIR = 0xFF; //Port D is input pin
	LCD_CONTROL_DIR |= (1 << E_PIN); //Enable E pin
	LCD_CONTROL_DIR |= (1 << RS_PIN); //RS pin

	_delay_ms(20); //Boot delay

}

/*
 * This method writes a command to LCD
 */
void lcdWriteCommand(uint8_t command) {
	//RS pin should be made low for command mode
	LCD_CONTROL_PORT &= ~(1 << RS_PIN);
	_delay_us(1);

	LCD_DATA_PORT = command; //display ON
	_delay_us(1);

	//making the E pin high and then to low for changes to be reflected
	LCD_CONTROL_PORT |= (1 << E_PIN);
	_delay_us(1);
	LCD_CONTROL_PORT &= ~(1 << E_PIN);
	_delay_ms(2);
}

/*
 * This method writes a character to LCD
 */
void lcdWriteChar(char ch) {
	//RS pin should be made high for command mode
	LCD_CONTROL_PORT |= (1 << RS_PIN);
	_delay_us(1);

	LCD_DATA_PORT = ch;

	LCD_CONTROL_PORT |= (1 << E_PIN);
	_delay_us(1);
	LCD_CONTROL_PORT &= ~(1 << E_PIN);

	_delay_ms(2);
}

/*
 * This method writes a string to LCD
 */
void lcdWriteString(char str[]) {
	uint8_t i = 0;
	while (str[i] != '\0') {
		lcdWriteChar(str[i]);
		i++;
	}
}

