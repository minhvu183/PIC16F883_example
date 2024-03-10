/*
 * File:   main.c
 * Author: nmvu1
 *
 * Created on 26 February 2024, 15:38
 */


#include "main.h"

void main(void) {
    
    T2CKPS0 = 1;    //cai bo chia truoc
    T2CKPS1 = 0;
    
    TOUTPS0 = 0;    //cai bo chia sau
    TOUTPS1 = 0;
    TOUTPS2 = 0;
    TOUTPS3 = 0;
    
    TMR2 = 0;
    PR2 = 200;
    TMR2ON = 1;     //timer2 bat dau chay
    
    TRISC2 = 0; //RC2 la output
    
    TMR2IE = 1; //Enables the Timer2 to PR2 match interrupt
    GIE = 1;
    PEIE = 1;
    
    while(1){
        
        
    }
    return;
}

void __interrupt() ISR(void){
    if(TMR2IF){
        RC2 = !RC2;
        TMR2 = 0;
        TMR2IF = 0;
    }
}

