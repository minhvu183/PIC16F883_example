/*
 * File:   main.c
 * Author: nmvu1
 *
 * Created on 26 February 2024, 15:38
 */


#include "main.h"

void main(void) {
    uint16_t i;
    TMR1CS = 1;     //che do dem xung ngoai
    T1SYNC = 1;     //khong dong bo hoa xung
    TMR1 = 0;    //thanh ghi gia tri xung cua timer1
    TMR1ON = 1;     //cho phep timer1 chay
    
    TRISC2 = 0; //RC2 la output
    TRISC3 = 0;
    TRISC4 = 0;
    TRISC5 = 0;
    TRISC6 = 0;
    TRISC7 = 0;
//    TRISC0 = 1;
            
    lcdInit();
    lcdText("Minh Vu");
    
    while(1){
        i = TMR1;
        if(i==250){
            i=0;
            TMR1=0;
        }
        lcdSet(2,1);
        lcdNumber(i);
    }
    return;
}
