/* 
 * File:   main.c
 * Author: nmvu1
 *
 * Created on 23 February 2024, 21:19
 */
#include "main.h"

#define I2C_BaudRate 400000

void i2c_master_init()
{
    //SSPCON Register
    SSPEN = 1;  //Enables the serial port and configures the SDA and SCL pins as the source of the serial port pins
    SSPM3 = 1;  //I2C Master mode, clock = FOSC / (4 * (SSPADD+1))
    SSPM2 = 0;
    SSPM1 = 0;
    SSPM0 = 0;  
  
    //SSPADD Register
    SSPADD = ((_XTAL_FREQ/4)/I2C_BaudRate) - 1;
    
    TRISC3 = 1; //SCL
    TRISC4 = 1; //SDA
}

void i2c_start(){
    SEN = 1;    //Initiate Start condition on SDA and SCL pins. Automatically cleared by hardware.
    while(SEN);
}

void i2c_restart(){
    RSEN = 1;    //Initiate Repeated Start condition on SDA and SCL pins. Automatically cleared by hardware.
    while(RSEN);
}

void i2c_stop(){

    PEN = 1;    //Initiate Stop condition on SDA and SCL pins. Automatically cleared by hardware.
    while(PEN);
}

uint8_t i2c_write(uint8_t data)
{
    SSPIF = 0;
    SSPBUF = data;
    while(!SSPIF);
    return ACKSTAT;
}

uint8_t i2c_read(bool ack){
    SSPIF = 0;
    RCEN = 1;       //Enables Receive
    while(!SSPIF);
    RCEN = 0;       //Disables Receive
    SSPIF = 0;      // Clear The Interrupt Flag Bit
    ACKDT = ack;    //bit ack
    ACKEN = 1;      //Initiate Acknowledge sequence on SDA and SCL pins, and transmit ACKDT data bit.
    while(ACKEN);
    return SSPBUF;
}

void main() {
    TRISB = 0;
    ANSELH = 0;
    i2c_master_init();
    
    i2c_start();
    i2c_write(0x40);
    i2c_write(0xaa);
    i2c_stop();
    
    while(1){
        i2c_start();
        i2c_write(0x4f);
        PORTB = i2c_read(1);
        i2c_stop(); 
        __delay_ms(400);
    }
}









