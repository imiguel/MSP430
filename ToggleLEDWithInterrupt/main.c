#include <msp430.h> 

#define LED_GREEN	BIT6
#define LED_RED		BIT0
#define BUTTON		BIT3

/*
 * Workshop Microcontroladores MSP430
 * ESTiG - Beja
 * Miguel Rosa, 6129
 * 18 Abril 2016
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	P1OUT = LED_GREEN;  // P1.6 - estabelece valor de saida a 1
	P1DIR = LED_GREEN;  // P1.6 - configurado como saida digital
	P1DIR &= ~BUTTON;   // P1.3 - configurado como entrada digital
	P1REN |= BUTTON;    // activa resistencia de entrada de P1.3
	P1OUT |= BUTTON;    // resistencia entrada de P1.3 como pullup

	P1IE = BUTTON; 	  //habilita interrupt do botao
	P1IES |= BUTTON;  //interrupcao na transicao 1
	P1IFG &= ~BUTTON; //certifica que indicador de int esta limpa

	_enable_interrupts(); //habilitar interrupcoes nao mascaraveis

	while(1){

	}

}


#pragma vector = PORT1_VECTOR

__interrupt void PORT1_ISR(){
	P1OUT ^= LED_GREEN;	//alterna LED
	P1IFG &= ~BUTTON;	//limpa o indicador de interrupt do botao em P1.3
}
