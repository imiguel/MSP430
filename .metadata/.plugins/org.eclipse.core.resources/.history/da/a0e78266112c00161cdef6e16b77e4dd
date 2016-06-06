#include <msp430.h> 

#define LED_GREEN	BIT6
#define LED_RED		BIT0
#define BUTTON		BIT3

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    //passo 1
    P1OUT = LED_GREEN;
    P1DIR = LED_GREEN;


    //passo 2
    CACTL1 = CARSEL | CAREF_3 | CAON;
    CACTL2 = P2CA4 | P2CA0;

    while(1){
    	if(CACTL2 & CAOUT){
    		P1OUT |= LED_GREEN; //acende led verde
    	}else{
    		P1OUT &= ~LED_GREEN;
    	}
    }
	
	return 0;
}
