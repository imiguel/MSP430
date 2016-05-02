#include <msp430.h> 

/* Title: Buttons with two interrupts
 *
 * Workshop Microcontroladores MSP430
 * ESTiG - Beja
 * Miguel Rosa, 6129
 * 02 Maio 2016
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer


    //configure I/O
    P1OUT = 0x00; //set output buffer
    P1DIR = 0xFF; //all pins as output
    P1DIR &= ~(BIT4 | BIT3); //pin 3 and 4 as input


    //configurar pinos input
    P1REN |= (BIT4 | BIT3); //enable pull-up/pull-down resistor
    P1OUT |= (BIT4 | BIT3); //configure input resistor as pull-up




    while(1){
    }
	
}
