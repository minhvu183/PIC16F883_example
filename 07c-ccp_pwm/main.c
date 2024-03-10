/* 
 * File:   main.c
 * Author: nmvu1
 *
 * Created on 23 February 2024, 21:19
 */
#include "main.h"
uint16_t duty;
void set_duty(uint16_t duty_cycle){
    DC1B1 = (bool)(duty_cycle & 2);    //2 bit thap cua duty cycle
    DC1B0 = (bool)(duty_cycle & 1);
    
    CCPR1L = (uint8_t)(duty_cycle >> 2);
}
void main() {
    
    CCP1M3 = 1; //PWM mode
    CCP1M2 = 1;
    CCP1M1 = 0;
    CCP1M0 = 0;
    
    TRISC2 = 0; //RC2 la output
    
    PR2 = 124;  //PWM period
    
    T2CKPS0 = 1;    //cai bo chia truoc
    T2CKPS1 = 0;
    
    DC1B1 = (bool)350 & 2;    //2 bit thap cua duty cycle
    DC1B0 = (bool)350 & 1;
    
    CCPR1L = 350 >> 2;
    
    TMR2ON = 1; //timer2 on
    
    while(1){
        
        duty = 0;
        while(duty<500){
           set_duty(duty);
           duty++;
           __delay_ms(5); 
        }
        __delay_ms(200);
        
        while(duty>0){
           set_duty(duty);
           duty--;
           __delay_ms(5);
        }
        __delay_ms(200);
    }
}









