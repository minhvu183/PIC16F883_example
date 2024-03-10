/* 
 * File:   main.c
 * Author: nmvu1
 *
 * Created on 23 February 2024, 21:19
 */
#include "main.h"

uint8_t uart_read(void){
    uint8_t result = 0;
    
    while(RCIDL);
    while(!RCIDL);
    result = RCREG;

    return result;
}

void main() {
    uint8_t i;
    BRGH = 1;   //High speed
    BRG16 = 0;  //8-bit Baud Rate Generator is used
    SYNC = 0;   //Asynchronous mode
    SPBRG = 25; // Set baud rate
    SPEN = 1;   //Serial port enabled
    
    CREN = 1;   //Enables receiver 
    
    TRISC6 = 1;  // As stated in the datasheet
    TRISC7 = 1;

    TRISA = 0;
    ANSEL = 0;
    
    while(1){
        i = uart_read();
        PORTA = i;
        __delay_ms(400);   
    }
}









