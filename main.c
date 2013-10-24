/*
 * Author: Jason Mossing
 * Description: This is the main for Lab 4.
 * This project initializes a SPI and LCD.
 * Then scrolls two messages, one in the top and one in the bottom line.
 */

#include <msp430.h> 
#include "LCD.h"
#include "button.h"

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
    initSPI();
    initLCD();
    clearLCD();
    configureP2PinAsButton(BIT3|BIT4|BIT5);
    char* string1 = "ECE382 is my favorite class! ";
    char* string2;

    writeString("Message?");
    line2Cursor();
    writeString("PRESS123");

    char buttons[] = {BIT3, BIT4, BIT5};
    char pressedButton = pollP2Buttons(buttons, 3);

    if(pressedButton == BIT3){
    	string2 = "You pressed button 1. ";
    	waitForP2ButtonRelease(BIT3);
    }
    else if(pressedButton == BIT4){
    	string2 = "You pressed button 2. ";
    	waitForP2ButtonRelease(BIT4);
    }
    else{
    	string2 = "You pressed button 3. ";
    	waitForP2ButtonRelease(BIT5);
    }

    scrollString(string1, string2);

    //traps cpu
    while(1){

    }

	return 0;
}
