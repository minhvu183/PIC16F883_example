#ifndef _LCD_4BIT_H_
#define _LCD_4BIT_H_

#include "main.h"


void lcdClear(void);
void lcdInit(void);
void lcdSet(uint8_t x,uint8_t y);
void lcdChar(char b);
void lcdText(char *str);
void lcdContro(uint8_t i);
void lcdCustom(uint8_t location,uint8_t x,uint8_t y, char * lcd_char);
void lcdNumber(uint32_t n);
void lcdNumberHex(uint32_t h);


#endif