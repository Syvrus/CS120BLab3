/*	Author: bcorb005
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
	PORTA = 0xFF;
	//DDRB = 0x00;
	//PORTB = 0xFF;
	DDRC = 0xFF;
	PORTC = 0x00;
	unsigned char gas, tmpA, tmpC;
    /* Insert your solution below */
    while (1) {
	tmpA = PINA;
	gas = tmpA & 0x0F;
	//tmpB = PINB;
	tmpC = 0x00;
	switch(gas){
		case 0:
			tmpC = tmpC | 0x40;
			break;
		case 1:
		case 2:
			tmpC = tmpC | 0x60;
			break;
		case 3:
		case 4:
			tmpC = tmpC | 0x70;
			break;
		case 5:
		case 6:
			tmpC = tmpC | 0x38;
			break;
		case 7:
		case 8:
		case 9:
			tmpC = tmpC | 0x3C;
			break;
		case 10:
		case 11:
		case 12:
			tmpC = tmpC | 0x3E;
			break;
		case 13:
		case 14:
		case 15:
			tmpC = tmpC | 0x3F;
			break;
		default:
			tmpC = 0x00;
			break;
	}
	if(((tmpA & 0x10) >> 4 == 1) && ((tmpA & 0x20) >> 5 == 1) && ((tmpA & 0x40) >> 6 == 0))
		tmpC = tmpC | 0x80;
	PORTC = tmpC;
    }
    return 1;
}
