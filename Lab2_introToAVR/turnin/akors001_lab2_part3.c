/*	Author: akors001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;
	DDRC = 0xFF;
	PORTC = 0x00;

	unsigned char tmpA = 0x00;
	unsigned char cntavail = 0x00;
	
	while (1)
	{
		PORTC = 0x00;
		cntavail = 0x00;
		tmpA = PINA & 0x01;
		if (tmpA == 0x01)
		{
			cntavail = cntavail + 1;
		}
		tmpA = PINA & 0x02;
		if (tmpA == 0x02) {
			cntavail = cntavail + 1;
		}
		tmpA = PINA & 0X04;
		if (tmpA == 0x04) {
			cntavail = cntavail + 1;
		}
		tmpA = PINA & 0x08;
		if (tmpA == 0x08) {
			cntavail = cntavail + 1;
		}
		if (cntavail == 0x04) {
			PORTC = PORTC | 0x80; //set 7th bit to 1.
		}
		PORTC = PORTC & 0xF0; //set PC3..0 to 0.
		PORTC = PORTC |  cntavail; //set PC3..0 to cntavail			

	}
	return 0;
}
