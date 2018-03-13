#include <msp430.h> 
#include <servomoteur.h>

/**
 * main.c
 */


int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   /* stop watchdog timer*/
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
}
