/*
 * servomoteur.c
 *
 *  Created on: 7 mars 2018
 *      Author: antoi
 */
#include <msp430G2231.h>
#include <fonction.h>

/*
 * Initialisation du timer
 */

void init_pwm_moteur()
{
    P1DIR |= (BIT2);
    P1SEL |= (BIT2);
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;
    TACTL = TASSEL_2 | MC_1 | ID_0;
    TACCTL1 = OUTMOD_7;
    TACCR0 = 20000;
    TACCR1 = 2500;
}


/**
 * main.c
 */

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   /* stop watchdog timer*/
    init_pwm_moteur();

    while(1);
}




