/* 
 * File:   main.c
 * Author: nmvu1
 *
 * Created on 23 February 2024, 21:19
 */
#include "main.h"

void __interrupt() ISR(void);

void main() {

    
    TRISC0 = 0; //RC0 la output
    TRISC1 = 0; //RC1 la output
    TRISB = 0xff; //RB0 la input
    ANSELH = 0;   //RB0 la digital
    nRBPU = 0;  //PORTB pull-ups are enabled
    
    
    RBIF = 0;
    RBIE = 1;   //Enables the PORTB change interrupt
    IOCB = 0xff;  //Interrupt-on-change enabled RB0
    GIE = 1;    //enable all interrupt
    
    while(1){
      
        RC0 = 1;
        __delay_ms(200);
        RC0 = 0;
        __delay_ms(200);
        
    }
}

void __interrupt() ISR(void){
    if(RBIF){   //co ngat INT
        
        while(PORTB != 0xff);
        RC1 = !RC1;
        RBIF = 0;   // xoa co ngat INT
        
    }
}







