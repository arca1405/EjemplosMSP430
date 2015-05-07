#include <msp430g2553.h>

#define LED_Verde 0x40					// BIT6

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD; 			// Stop watchdog timer

	P1DIR |= LED_Verde; 					// Set P1.6 to output direction
	P1OUT &= ~LED_Verde; 				// Set green LED off

	//P1REN |= 0x08;						// Enable Port P1.3 (push button) pull-up resistor
	P1SEL &= ~0x08;					     // Select Port 1 P1.3 (push button)
    P1DIR &= ~0x08;					// Port 1 P1.3 (push button) as input, 0 is input


	while(1){
		if ( (P1IN & BIT3) == 0)
			P1OUT |= LED_Verde;

		else
			P1OUT &= ~LED_Verde;
	}
}
