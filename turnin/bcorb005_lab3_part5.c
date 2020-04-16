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
	//DDRA = 0x00;
	//PORTA = 0xFF;
	DDRB = 0xFE;
	PORTB = 0x01;
	//DDRC = 0xFF;
	//PORTC = 0x00;
	DDRD = 0x00;
	PORTD = 0xFF;
	unsigned char tmpBi, tmpBo, tmpD;
	unsigned short s;
    /* Insert your solution below */
    while (1) {
	tmpBi = PINB;
	tmpD = PIND;
	tmpBo = 0x00;
	s = (tmpD * 2) + tmpBi;
	if(s >= 70)
		tmpBo = tmpBo | 0x02;
	if((s > 5) && (s < 70))
		tmpBo = tmpBo | 0x04;
	PORTB = tmpBo;
    }
    return 1;
}
