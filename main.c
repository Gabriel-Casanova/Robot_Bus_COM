#include <msp430.h> 
#include <uart.h>
#include <fonction.h>
#include <ADC.h>
#include <SPI_2553.h>
#include <string.h>




/**
 * main.c
 */

void main( void )
{

    init_BOARD();
    init_UART();
    init_USCI();

    envoi_msg_UART("\rReady !\r\n"); // user prompt

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
