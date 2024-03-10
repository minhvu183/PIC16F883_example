/* 
 * File:   main.c
 * Author: nmvu1
 *
 * Created on 23 February 2024, 21:19
 */
#include "main.h"

void main() {
    
    C1CH1 = 0;  //C12IN0 la dau vao C1Vin-
    C1CH0 = 0;  //
    
    C1R = 0;    //C1IN+ la dau vao C1Vin+
    C1POL = 0;  //bit chon C1OUT khong dao
    C1OE = 1;   //bit cho phep bo so sanh C1 hoat dong
    C1ON = 1;   //C1 bat day chay
    
    TRISA4 = 0; //RA4 la output
    TRISA0 = 1; //RA0 la input
    TRISA3 = 1; //RA3 la input
    ANS0 = 1;   //RA0 la analog
    ANS3 = 1;   //RA3 la analog
    
    while(1){
        
    }
}









