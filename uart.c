/*
 * uart.c
 *
 *  Created on: 7 mars 2018
 *      Author: antoi
 */

//------------------------------------------------------------------------------
// uart_simple.c
//
// test de l'UART : �cho des caract�res re�us
//
//                              benoit.decoux@esigelec.fr - 28/01/2013
//------------------------------------------------------------------------------
#include <msp430g2553.h>

void InitUART(void)
{
    P1SEL |= (BIT1 | BIT2);                 // P1.1 = RXD, P1.2=TXD
    P1SEL2 |= (BIT1 | BIT2);                // P1.1 = RXD, P1.2=TXD
    UCA0CTL1 = UCSWRST;
    UCA0CTL1 |= UCSSEL_3;                   // SMCLK

    UCA0CTL0 &= ~(UCPEN | UCMSB | UCMSB | UCDORM);
    UCA0CTL0 &= ~(UC7BIT | UCSPB  | UCMODE_3 | UCSYNC);
    UCA0CTL1 &= ~UCSWRST;                   // **Initialize USCI state machine**

    UCA0BR0 = 104;                          // 1MHz, 9600
    UCA0BR1 = 0;                            // 1MHz, 9600
    UCA0MCTL = 10;

    IE2 |= UCA0RXIE;                        // Enable USCI_A0 RX interrupt
}

void TXdata( unsigned char c )
{
    while (!(IFG2&UCA0TXIFG));  // USCI_A0 TX buffer ready?
    UCA0TXBUF = c;              // TX -> RXed character
}

unsigned char a;
unsigned char commande;

/*
void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;   // Stop WDT
    BCSCTL1 = CALBC1_1MHZ;      // Set DCO to 1Mhz
    DCOCTL = CALDCO_1MHZ;       // Set DCO to 1Mhz
    P1DIR = BIT0;               //
    P1DIR = BIT6;
    P1REN = BIT6;
    P1SEL = BIT6;
    P1SEL2 = BIT6;

    InitUART();

    __bis_SR_register(GIE); // interrupts enabled

    TXdata('a');
    while(1);
}


// Echo back RXed character, confirm TX buffer is ready first
unsigned char c;
#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{
    c = UCA0RXBUF;
    TXdata('c');

/*
 * Tentative de créer un switch afin de faire un menu en fonction de la lettre
 */

    /*if (UCB0RXBUF == a)
    {
        P1OUT |= BIT6;
    }
    else
    {
        P1OUT &=~ BIT6;
    }
    switch (c)
    {
    case c = 'h'
        {
            printf ("")
        }
    }
}*/



