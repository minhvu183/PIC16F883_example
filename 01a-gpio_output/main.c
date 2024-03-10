/* 
 * File:   main.c
 * Author: nmvu1
 *
 * Created on 23 February 2024, 21:19
 */
#include "main.h"

void main() {
    ANSEL = 0x00;
    ANSELH = 0x00;
    TRISA = 0;  //port A la output
    TRISB0 = 0; //chan RB0 la output
    
    while(1){
        PORTA = 0xff;
        RB0 = 1;
        __delay_ms(200);
        PORTA = 0;
        RB0 = 0;
        __delay_ms(200);
    }
}









