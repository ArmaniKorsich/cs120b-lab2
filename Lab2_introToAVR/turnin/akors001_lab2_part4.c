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
	DDRA = 0x00;// PINA = 0x00;
	DDRB = 0x00;// PINB = 0x00;
	DDRC = 0x00;// PINC = 0x00;
	DDRD = 0xFF; PORTD = 0x00;

	unsigned char weightSum = 0x00; //should be short to prevent overflow of 3 8-bit number, but it causes other complications.
	signed short weightDif = 0x00;
	unsigned char tmpD;
	
	while (1)
	{

		weightSum = 0x00;
		weightDif = 0x00;
		tmpD = 0x00;
		PORTD = 0x00;

		weightSum = PINA + PINB + PINC;
		weightSum = weightSum & 0xFC;

//		if (weightSum >= 128) {
//			weightSum = weightSum >> 2;
//		} else if (weightSum >= 64) {
//			weightSum = weightSum >> 1;
//		}
//		weightSum = weightSum << 2;
		tmpD = weightSum;


		if (weightSum > 0x8c) {
			tmpD = tmpD + 0x01; //SET PD0 to 1.
	        }
//		 else {
//			tmpD = tmpD & 0xFE; //SET PD0 to 0.
//		}
	
		weightDif = PINA - PINC;
		if (weightDif < -0x50 || weightDif > 0x50) {
			tmpD = tmpD + 0x02; //SET PD1 to 1.
		} 
//		else {
//			tmpD  = tmpD & 0xFD; //SET PD1 to 0.
//		}

//		if (weightsum >= 128) {
//			weightsum = weightsum >> 2;
//		} else if (weightsum >= 64) {
//			weightsum = weightsum >> 1;
//		}
//		weightsum = weightsum << 2;
//		tmpD = tmpD & 0x03; //clear 6 msb.
//		tmpD = tmpD + weightSum;
	
		PORTD = tmpD;

	}	
	return 0;
}
