/*
 * LCD.h
 *
 *  Created on: Oct 21, 2013
 *      Author: C15Jason.Mossing
 *      Description: Library for msp430 to Geekbox LCD interaction.
 */

#ifndef LCD_H_
#define LCD_H_

void initLCD();

void clearLCD();

void initSPI();

void line1Cursor();

void line2Cursor();

void scrollString(char* line1strg, char* line2strg);

void writeString(char* strg2Write);

void writeChar(char char2Write);


#endif /* LCD_H_ */
