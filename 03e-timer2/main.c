/*
 * File:   main.c
 * Author: nmvu1
 *
 * Created on 26 February 2024, 15:38
 */


#include "main.h"

void main(void) {
    
    T2CKPS0 = 0;    //cai bo chia truoc
    T2CKPS1 = 1;
    
    TOUTPS0 = 1;    //cai bo chia sau
    TOUTPS1 = 1;
    TOUTPS2 = 1;
    TOUTPS3 = 1;
    
    TMR2 = 0;
    PR2 = 200;
    TMR2ON = 1;     //timer2 bat dau chay
    
    TRISC2 = 0; //RC2 la output
    
    while(1){
        RC2 = !RC2;
        while(!TMR2IF); //doi co tran timer2
        TMR2IF = 0;
    }
    return;
}
