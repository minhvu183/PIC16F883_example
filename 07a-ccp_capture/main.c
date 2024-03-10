/* 
 * File:   main.c
 * Author: nmvu1
 *
 * Created on 23 February 2024, 21:19
 */
#include "main.h"
uint16_t i;
void main() {
    
    TRISA = 0;
    ANSEL = 0;
    
    TMR1CS = 0;     //che do dem xung noi
    T1CKPS1 = 0;    //cai dat bo chia xung
    T1CKPS0 = 0;
    T1SYNC = 1;     //khong dong bo hoa xung
    TMR1 = 0;    //thanh ghi gia tri xung cua timer1
    TMR1ON = 1;     //cho phep timer1 chay
    
    CCP1M3 = 0; //che do Capture mode, every falling edge
    CCP1M2 = 1;
    CCP1M1 = 0;
    CCP1M0 = 0;
    
    CCP1IE = 1;
    PEIE = 1;
    GIE = 1;
    
    lcdInit();
    lcdChar('a');
    
    while(1){
        GIE = 0;
        lcdClear();
        lcdNumber(i);
        __delay_ms(500);
        GIE = 1;
        __delay_ms(100);
    }
}

void __interrupt() ISR(void){
    if(CCP1IF){
        i = CCPR1;
        TMR1 = 0;
        CCP1IF = 0;
    }
}







