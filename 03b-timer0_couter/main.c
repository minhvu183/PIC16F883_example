/*
 * File:   main.c
 * Author: nmvu1
 *
 * Created on 26 February 2024, 15:38
 */


#include "main.h"

void main(void) {
    uint8_t couter;
    T0CS = 1;   //che do couter dem xung ngoai
    T0SE = 1;    //dem canh xuong
    PSA = 1;    //bo chia xung khong qua timer0
    
    TMR0 = 0x00;    //thanh ghi dem xung timer0
    
    TRISC = 0; //RC2 la output
    
    lcdInit();
    lcdText("Minh Vu");
    
    while(1){
        couter = TMR0;
        if(couter == 255){
            TMR0 = 0;
            couter = 0;
        }
        lcdSet(2,1);
        lcdNumber(couter);
    } 
    return;
}
