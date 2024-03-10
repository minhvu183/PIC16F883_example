/* 
 * File:   main.c
 * Author: nmvu1
 *
 * Created on 23 February 2024, 21:19
 */
#include "main.h"

void main() {
    uint8_t i;
    ANSEL = 0x00;   //cac chan la digital
    ANSELH = 0x00;  //cac chan la digital   
    TRISC = 0x00;      // port A la output
    lcdInit();
    lcdText("Minh Vu");
    writeEeprom(0,200);
    i = readEeprom(0);
    lcdSet(2,1);
    lcdNumber(i);
    while(1){
        RC2 = 1;
        __delay_ms(200);
        RC2 = 0;
        __delay_ms(200);
    }
}









