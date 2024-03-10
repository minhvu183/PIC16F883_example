/* 
 * File:   main.c
 * Author: nmvu1
 *
 * Created on 23 February 2024, 21:19
 */
#include "main.h"



void main() {
    TRISC0 = 0;
    RC0 = 1;
    
    CSRC = 1;   //Synchronous Master mode
    TXEN = 1;   //Transmit enabled
    SYNC = 1;   //Synchronous mode
    SPEN = 1;   //Serial port enabled
    SPBRG = 100; //Set boud rate
    SCKP = 1;   //Data is clocked on rising edge of the clock
    
    while(!TRMT);   //Transmit Shift Register Status
    TXREG = 0x05;
    
    RC0 = 0;
    __delay_ms(1);
    RC0 = 1;
    
    while(1){
        
         
    }
}









