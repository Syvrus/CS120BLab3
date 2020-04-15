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
	DDRB = 0x00;
	PORTB = 0xFF;
	DDRC = 0xFF;
	PORTC = 0x00;
	unsigned char cnt, tmpA, tmpB, tmpC;
    /* Insert your solution below */
    while (1) {
	tmpA = PINA;
	tmpB = PINB;
	cnt = 0;
	if(tmpA & 0x01 == 1)
		cnt++;
	if(tmpA & 0x02 == 1)
		cnt++;
	if(tmpA & 0x04 == 1)
		cnt++;
	if(tmpA & 0x08 == 1)
		cnt++;
	if(tmpA & 0x10 == 1)
		cnt++;
	if(tmpA & 0x20 == 1)
		cnt++;
	if(tmpA & 0x40 == 1)
		cnt++;
	if(tmpA & 0x80 == 1)
		cnt++;
	if(tmpB & 0x01 == 1)
		cnt++;
	if(tmpB & 0x02 == 1)
		cnt++;
	if(tmpB & 0x04 == 1)
		cnt++;
	if(tmpB & 0x08 == 1)
		cnt++;
	if(tmpB & 0x10 == 1)
		cnt++;
	if(tmpB & 0x20 == 1)
		cnt++;
	if(tmpB & 0x40 == 1)
		cnt++;
	if(tmpB & 0x80 == 1)
		cnt++;
	tmpC = cnt;
	PORTC = tmpC;
    }
    return 1;
}
