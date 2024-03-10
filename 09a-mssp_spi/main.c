/* 
 * File:   main.c
 * Author: nmvu1
 *
 * Created on 23 February 2024, 21:19
 */
#include "main.h"

#define ss RC7

uint8_t spi_write(uint8_t data){
    BF = 0;
    SSPBUF = data;
    while(BF);
    return SSPBUF;
}

uint8_t spi_read(){
  uint8_t data;
  data = spi_write(0x00);
  return data;
}

void main() {
    uint8_t i;
    TRISA = 0;
    ANSEL = 0;
    
    TRISC7 = 0; //SS
    TRISC5 = 0; //SDA
    TRISC4 = 1; //SDI
    TRISC3 = 0; //SCK
    
    SSPM3 = 0;  //SPI Master mode, clock = FOSC/4
    SSPM2 = 0;
    SSPM1 = 0;
    SSPM0 = 0;
    
    SSPEN = 1;  //Enables serial port and configures SCK, SDO, SDI and SS as the source of the serial port pins
    
    CKP = 0;    //Idle state for clock is a low level
    CKE = 0;    //Data transmitted on rising edge of SCK
    
    SMP = 0;    //Input data sampled at middle of data output time
    
    ss = 1;
    __delay_ms(100);
    
//    ss = 0;    
//    spi_write(0x06);
//    __delay_ms(10);
//    ss = 1;
//    __delay_ms(10);
//    
//    ss = 0;    
//    spi_write(0x02);
//    __delay_ms(10);
//    spi_write(0x00);
//    __delay_ms(10);
//    spi_write(0x00);
//    __delay_ms(10);
//    spi_write('a');
//    __delay_ms(10);
//    ss = 1;
    
    ss=0;
    spi_write(0x03);
    __delay_ms(10);
    spi_write(0);
    __delay_ms(10);
    spi_write(0);
    __delay_ms(10);
    i=spi_read();
    __delay_ms(10);
    ss = 1;
    PORTA = i;
    while(1){
        
    }
}









