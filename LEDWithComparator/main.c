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

    while(1){
    	if(CACTL2 & CAOUT){ //testa se a saida do CA+ � 1 (ocorreu a transicao 0 -> 1)
    		P1OUT |= LED_GREEN; //acende led verde
    	}else{
    		P1OUT &= ~LED_GREEN; //apaga o led verde
    	}
    }
}
