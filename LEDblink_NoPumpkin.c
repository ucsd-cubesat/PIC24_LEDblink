/* 
 * File:   LEDblink_NoPumpkin.c
 * Author: Annalisa Vilaysing
 *
 * Created on August 20, 2018, 11:56 PM
 */

#define FCY 30400000UL			// Setting cycle frequency, Hz
								// This is REQUIRED for __delayXXX() to work

#include <stdio.h>				// Standard header file
#include <stdlib.h>				// Another standard header file
#include <libpic30.h>			// __delay_ms function defined here
#include <p24fxxxx.h>			// PIC24 specific functions defined here

/*	This code opens up 2 ports on the Development Board
*		Pin H2.18 is opened for an LED to be continuously on
*		Pin H2.16 is opened for an LED to flash
*	Ground pins are H2.39, H2.30, and H2.32
*
*	Please note that for LEDs: anode(+) has been marked black and is long 
*							   while the cathode(-) is shorter
*/

int main(void) {
    TRISEbits.TRISE8 = 0;		// Configure io30 - pin H2.18 as an output
    LATEbits.LATE8 = 1;			// Set output value, HIGH
    
    TRISBbits.TRISB5 = 0;       // Configure io32 - pin H2.16 as an output
    while(1) {					// Begin while loop for continuous blinking
        LATBbits.LATB5 = 1;     // Set output value, HIGH
        __delay_ms(10);         // Delay for 10 ms
        LATBbits.LATB5 = 0;     // Set output value, LOW
        __delay_ms(10);         // Delay for 10 ms
    }
    
    return 0;
}
