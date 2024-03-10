/* 
 * File:   main.c
 * Author: nmvu1
 *
 * Created on 23 February 2024, 21:19
 */
#include "main.h"

void main() {
    TRISC0 = 0;
    
    TMR1CS = 0;     //che do dem xung noi
    T1CKPS1 = 0;    //cai dat bo chia xung
    T1CKPS0 = 0;
    T1SYNC = 1;     //khong dong bo hoa xung
    TMR1 = 0;    //thanh ghi gia tri xung cua timer1
    TMR1ON = 1;     //cho phep timer1 chay
    
    CCP1M3 = 1; //che do Capture mode, every falling edge
    CCP1M2 = 0;
    CCP1M1 = 1;
    CCP1M0 = 1;
    CCPR1 = 50000;
    
    CCP1IE = 1;
    PEIE = 1;
    GIE = 1;
        
    while(1){
        
    }
}

void __interrupt() ISR(void){
    if(CCP1IF){
        RC0 = !RC0;
        CCP1IF = 0;
    }
}







