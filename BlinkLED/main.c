#include <msp430.h> 

/*
 * Workshop Microcontroladores MSP430
 * ESTiG - Beja
 * Miguel Rosa, 6129
 * 11 Abril 2016
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	P1OUT = BIT3 | BIT0;
	P1DIR = BIT0 | BIT6;
	P1REN |= BIT3;

	while(1){
		//P1OUT = P1OUT ^ BIT0;
		//P1OUT ^= BIT0;
		if ( (P1IN & BIT3) == 0 ){ //botao carregado
			P1OUT ^= (BIT6 | BIT0);

			int i = 15000;
			for(; i > 0; i--);
		}
	}

	return 0;
}
