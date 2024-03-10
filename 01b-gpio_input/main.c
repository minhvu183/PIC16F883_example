/* 
 * File:   main.c
 * Author: nmvu1
 *
 * Created on 23 February 2024, 21:19
 */
#include "main.h"

void main() {
    OSCCON = 0x7e;  //cai internal osc 8MHz
    ANSEL = 0x00;   //tat ca cac chan la digital
    ANSELH = 0x00;  //tat ca cac chan la digital
    
    TRISA0 = 1; //A0 la input
    TRISA1 = 0; //A1 la output
    TRISA2 = 0;
    RA2 = 1;
    while(1){
        
        if(RA0==1)
            RA1 = 1;
        else    
            RA1 = 0;
        SLEEP();
        
    }
}
