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


    //configure input pins
    P1REN |= (BIT4 | BIT3); //enable pull-up/pull-down resistor
    P1OUT |= (BIT4 | BIT3); //configure input resistor as pull-up


    //configure interrupts
    P1IE |= (BIT4 | BIT3); //enable interrupts of pins 3 and 4
    P1IES |= BIT3;	//interrupt: 1 -> 0
    P1IES &= ~BIT4;	//interrupt: 0 -> 1
    P1IFG &= ~(BIT4 | BIT3); //clear any interrupt flag

    _enable_interrupts(); //


    while(1){
    }
	
}


#pragma vector = PORT1_VECTOR;
__interrupt void PORT1_ISR(){
	if( P1IFG & BIT3 == 0){
		P1OUT |= BIT6;
		P1IFG &= ~BIT3;
	}

	if( P1IFG & BIT4 == 0){
		P1OUT &= ~BIT6;
		P1IFG &= ~BIT4;
	}
}
