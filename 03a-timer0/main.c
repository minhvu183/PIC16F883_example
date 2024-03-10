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
    PS1 = 1;
    PS2 = 1;
    
    TMR0 = 0x01;    //thanh ghi dem xung timer0
    
    TRISC2 = 0; //RC2 la output
    
    while(1){
        RC2 = !RC2;
        while(!T0IF);   //doi co bao tran timer0
        TMR0 = 0x01;
        T0IF = 0;
    }
    return;
}
