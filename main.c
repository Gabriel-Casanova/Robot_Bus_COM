#include <msp430.h> 
#include <uart.h>
#include <fonction.h>
#include <ADC.h>

/**
 * main.c
 */



void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;   // Stop WDT
    BCSCTL1 = CALBC1_1MHZ;      // Set DCO to 1Mhz
    DCOCTL = CALDCO_1MHZ;       // Set DCO to 1Mhz
    P1DIR = BIT0;               //
    P1DIR = BIT6;
    P1REN = BIT6;
    P1SEL = BIT6;


    InitUART();

    __bis_SR_register(GIE); // interrupts enabled

    TXdata('a');
    while(1);
}
