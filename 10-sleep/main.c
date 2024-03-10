/* 
 * File:   main.c
 * Author: nmvu1
 *
 * Created on 23 February 2024, 21:19
 */
#include "main.h"
uint8_t i=0;
void main() {
    
    GIE = 1;    //enable all interrupt
    INTE = 1;   //enable INT interrupt
    INTEDG = 0; //Interrupt on falling edge of INT pin
    
    TRISC0 = 0; //RC0 la output
    TRISC1 = 0; //RC1 la output
    TRISB0 = 1; //RB0 la input
    ANS12 = 0;   //RB0 la digital
    nRBPU = 0;  //PORTB pull-ups are enabled
    while(1){
        if(i){
            SLEEP();
        }
        else{
            RC0 = !RC0;
            __delay_ms(200);
        }
    }
}

void __interrupt() ISR(void){
    if(INTF){   //co ngat INT      
        if(i)
            i=0;
        else
            i=1;  
        INTF = 0;   // xoa co ngat INT
    }
}







