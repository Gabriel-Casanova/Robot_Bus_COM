#include <msp430.h> 
#include <uart.h>
#include <fonction.h>
#include <ADC.h>
#include <SPI_2553.h>
#include <string.h>
#include <SPI_2231.h>



/**
 * main.c
 */

void main( void )
{
    WDTCTL = WDTPW | WDTHOLD;   /* stop watchdog timer*/

    /*          Servomoteur     */

    int sens=1 ;
    int rc=0;
    init_BOARD();
    init_UART();
    init_USCI();
	}

    envoi_msg_UART("\rReady !\r\n"); // user prompt
          /* SPI   */
	void init_SPI();
    _enable_interrupt();
    if(CALBC1_1MHZ==0xFF || CALDCO_1MHZ==0xFF)
       {
           __bis_SR_register(LPM4_bits);
       }
       else
       {
           // Factory Set.
           DCOCTL = 0;
           BCSCTL1 = CALBC1_1MHZ;
           DCOCTL = (0 | CALDCO_1MHZ);
       }


    while(1)
    {
        if( intcmd )
        {
            interpreteur();         // execute la commande utilisateur
            intcmd = FALSE;         // acquitte la commande en cours
        }
        else
        {
            __bis_SR_register(LPM4_bits | GIE); // general interrupts enable & Low Power Mode
        }
    }
}




