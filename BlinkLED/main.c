#include <msp430.h> 

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
    P1OUT = BIT0;
    P1DIR = BIT0 | BIT6;

	while(1){
		//P1OUT = P1OUT ^ BIT0;
		//P1OUT ^= BIT0;
		P1OUT ^= (BIT6 | BIT0);

		int i = 5000;
		for(; i > 0; i--);
	}

	return 0;
}
