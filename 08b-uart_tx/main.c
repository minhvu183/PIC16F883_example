/* 
 * File:   main.c
 * Author: nmvu1
 *
 * Created on 23 February 2024, 21:19
 */
#include "main.h"

void uart_write(uint8_t data){
    while(!TRMT);
    TXREG = data;
}

void main() {
    uint8_t i;
    BRGH = 1;   //High speed
    BRG16 = 0;  //8-bit Baud Rate Generator is used
    SYNC = 0;   //Asynchronous mode
    SPBRG = 25; // Set baud rate
    SPEN = 1;   //Serial port enabled
    TXEN = 1;   //Transmit enabled
    
    TRISC6 = 1;  // As stated in the datasheet
    TRISC7 = 1;

    
    while(1){
        for(i='a';i<='z';i++){
            uart_write(i);
            __delay_ms(200);
        }
            
    }
}









