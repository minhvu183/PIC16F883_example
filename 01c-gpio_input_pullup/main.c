/* 
 * File:   main.c
 * Author: nmvu1
 *
 * Created on 23 February 2024, 21:19
 */
#include "main.h"

void main() {
    OSCCON = 0x7e;
    TRISA0=0;   //A0 la output
    TRISB0=1;   //B0 la input
    ANS12=0;    //B0 la digital
    WPUB0=1;    //cho phep pullup B0
    nRBPU=0;     //cho phep pullup toan cuc
    while(1){
        
        if(RB0==0)
            RA0 = 1;
        else    
            RA0 = 0;
        
    }
}