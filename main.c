/*
 * Author: Jason Mossing
 * Description: This is the main for Lab 4.
 * This project initializes a SPI and LCD.
 * Then scrolls two messages, one in the top and one in the bottom line.
 */

#include <msp430.h> 
#include "LCD.h"
/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
    initSPI();
    initLCD();
    clearLCD();

    char* string1 = "ECE382 is my favorite class! #";
    char* string2 = "Here is line2! #";
    scrollString(string1, string2);

    while(1){

    }

	return 0;
}
