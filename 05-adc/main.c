/* 
 * File:   main.c
 * Author: nmvu1
 *
 * Created on 23 February 2024, 21:19
 */
#include "main.h"

void main() {
    uint16_t value;
    TRISC = 0;  //port C la output
    TRISA0 = 1; //RA0 la input
    ANS0 = 1;   //RA0 la analog
    
    CHS3 = 0;   //lua chon ngo vao bo ADC la ANS0
    CHS2 = 0;
    CHS1 = 0;
    CHS0 = 0;
    
    VCFG0 = 0;  //Vref+ noi voi Vdd
    VCFG1 = 0;  //Vref- noi voi Vss
    
    ADFM = 1;   //du lieu ADC can le phai
    
    ADCS1 = 0;  //lua chon bo dao song cho ADC
    ADCS0 = 0;
    
    ADON = 1;   //enabled ADC
    
    lcdInit();
    lcdText("Minh Vu");
    while(1){
        if(GO_nDONE ==0 )
            GO_nDONE = 1;   //bat dau chuyen doi ADC
        while(GO_nDONE);    //doi cho qua trinh chuyen doi ket thuc
        value = ADRESH;
        value = (value<<8)|ADRESL;
        lcdClear();
        lcdText("GiaTri ADC 10bit: ");
        lcdSet(2,6);
        lcdNumber(value);
        __delay_ms(700);    
        
    }
}









