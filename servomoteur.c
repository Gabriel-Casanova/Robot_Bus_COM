/*
 * servomoteur.c
 *
 *  Created on: 7 mars 2018
 *      Author: antoi
 */
#include <msp430G2231.h>


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
    TACCR0 = 19600;
    TACCR1 = 500;
}



/**
 * main.c
 */

/*
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;    //stop watchdog timer
    int sens=1 ;
    int rc=0;

    init_pwm_moteur();
    rc=TACCR1;
    while (1){
        __delay_cycles(400000);
        if (sens==1){
            rc+=100;}
        else {
            rc-=100;}
        if (rc > 2000){
            sens = 0;}
        else if (rc<500){
            sens = 1;}
        TACCR1 = rc;

    }
}*/




