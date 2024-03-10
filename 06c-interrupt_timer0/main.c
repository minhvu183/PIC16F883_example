/*
 * File:   main.c
 * Author: nmvu1
 *
 * Created on 26 February 2024, 15:38
 */


#include "main.h"

void main(void) {
    
    T0CS = 0;   //che do timer dem xung noi
    PSA = 0;    //bo chia xung timer0
    
    PS0 = 1;    //cai ti le bo chia truoc
    PS1 = 0;
    PS2 = 0;
    
    TMR0 = 0;    //thanh ghi dem xung timer0
    
    TRISC0 = 0; //RC2 la output
    
    T0IE = 1;   //Enables the Timer0 interrupt
    GIE = 1;
    PEIE = 1;    //Enables all unmasked peripheral interrupts
    while(1){
        
    }
    
}

void __interrupt() ISR(void){
    if(T0IF){
        RC0 = !RC0;
        TMR0 = 0;
        T0IF = 0;
    }
}


