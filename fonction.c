/*
 * fonction.c
 *
 *  Created on: 13 mars 2018
 *      Author: antoi
 */


#include <MSP430G2553.h>
#include <ADC.h>


float sec=0,sec2=0,distance;

void init_pwm_moteur_2(){
    P2DIR |= (BIT2 | BIT1 | BIT4 | BIT5);
    P2SEL |= (BIT2 | BIT4);
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;
    TA1CTL = TASSEL_2 | MC_1 | ID_0;
    TA1CCTL1 = TA1CCTL2 = OUTMOD_7;
    TA1CCR0 = 1000;
    TA1CCR1 = 800;
    TA1CCR2 = 800;
}

void init_obstacle(){
    P1DIR &=~ BIT4;
    P1IES |= BIT4;
    P1IFG &=~ BIT4;
    P1IE |= BIT4;
}

void sens_A(int sens){
    if(sens==0)
        P2OUT &=~ BIT1;
    else
        P2OUT |= BIT1;
}

void sens_B(int sens){
    if(sens==0)
        P2OUT &=~ BIT5;
    else
        P2OUT |= BIT5;
}

void stop(){
    TA1CCTL1=TA1CCTL2=OUTMOD_0;
}

void avancer(){
    TA1CCTL1=TA1CCTL2=OUTMOD_7;
    sens_A(0);
    sens_B(1);
}

void reculer(){
    TA1CCTL1=TA1CCTL2=OUTMOD_7;
    sens_A(1);
    sens_B(0);
}

void tourner_gauche(){
    sens_A(1);
    sens_B(1);
}

void tourner_droite(){
    sens_A(0);
    sens_B(0);
}

int ob_devant(){
    ADC_Demarrer_conversion(4);
    if(ADC_Lire_resultat()>920)
        return 0;
    return 1;
}

#pragma vector = PORT1_VECTOR
__interrupt void Port_0(void)
{
    ADC_Demarrer_conversion(4);
    stop();
}




