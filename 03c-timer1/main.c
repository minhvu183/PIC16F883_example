/*
 * File:   main.c
 * Author: nmvu1
 *
 * Created on 26 February 2024, 15:38
 */


#include "main.h"

void main(void) {
    
    TMR1CS = 0;     //che do dem xung noi
    T1CKPS1 = 1;    //cai dat bo chia xung
    T1CKPS0 = 0;
    T1SYNC = 1;     //khong dong bo hoa xung
    TMR1 = 0;    //thanh ghi gia tri xung cua timer1
    TMR1ON = 1;     //cho phep timer1 chay
    
    TRISC2 = 0; //RC2 la output
    
    while(1){
        RC2 = !RC2;
        while(!TMR1IF); //doi co tran timer1
        TMR1L = 0;
        TMR1H = 0;
        TMR1IF = 0;
    }
    return;
}
