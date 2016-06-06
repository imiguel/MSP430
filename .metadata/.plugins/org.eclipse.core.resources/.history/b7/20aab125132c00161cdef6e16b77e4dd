#include <msp430.h> 

#define LED_GREEN	BIT6
#define LED_RED		BIT0
#define BUTTON		BIT3

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    //passo 1 - configurar os pinos
    P1OUT = LED_GREEN; // P1.6 - estabelece valor de aida 1
    P1DIR = LED_GREEN; // P1.6 - configurado como saida digital


    //passo 2 - configurar o comparador (Comparator_A+)
    CACTL1 = CARSEL | CAREF_3 | CAON;
    CACTL2 = P2CA4 | P2CA0; //selecciona CA2 (pino P1.2) como entrada do comparador

    _enable_interrupts();

    while(1){
    	_low_power_mode_1();_
    }

}

#pragma vector = COMPARATORA_VECTOR;
__interrupt void ComparatorA_ISR(){

	P1OUT ^= LED_GREEN; //acende led verde

}
