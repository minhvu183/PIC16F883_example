#include "lcd_4bit.h"
/*Khai bao chan cac LCD
#define rs RA0
#define en RA1
#define lcdD7 RA7
#define lcdD6 RA6
#define lcdD5 RA5
#define lcdD4 RA4 
*/


void clockLcd(){
	en=1;
    __delay_ms(4);
	en=0;
}
void lcdWriteHigh(uint8_t b){
	lcdD7=(b&0x80)>>7;
	lcdD6=(b&0x40)>>6;
	lcdD5=(b&0x20)>>5;
	lcdD4=(b&0x10)>>4;
}
void lcdWriteLow(uint8_t b){
	lcdD7=(b&0x08)>>3;
	lcdD6=(b&0x04)>>2;
	lcdD5=(b&0x02)>>1;
	lcdD4=b&0x01;
}
void lcdCmd(uint8_t b){
	rs=0;
	lcdWriteHigh(b);
	clockLcd();
	lcdWriteLow(b);
	clockLcd();
	__delay_ms(2);	
}
void lcdClear(void){
	lcdCmd(0x01);	
}
void lcdInit(void){
	rs=0;
	en=0;
    __delay_ms(20);
    
	lcdWriteHigh(0x30);
	clockLcd();
	__delay_ms(5);
    
	lcdWriteHigh(0x30);
	clockLcd();
	__delay_us(150);
    
    lcdWriteHigh(0x30);
	clockLcd();
    
	lcdWriteHigh(0x20);
	clockLcd();
	__delay_ms(1);
    
	lcdCmd(0x28);
	lcdCmd(0x0c);
	lcdCmd(0x01);
	lcdCmd(0x06);
}
void lcdSet(uint8_t x,uint8_t y){
	uint8_t add;
	if(x==1)
		add=0x80;
	else if(x==2)
		add=0xc0;
	add+=y-1;
	lcdCmd(add);
}
void lcdChar(char b){
	rs=1;
	lcdWriteHigh(b);
	clockLcd();
	lcdWriteLow(b);
	clockLcd();
	__delay_us(40);	
}
void lcdText(char *str){
	uint8_t i;
	for(i=0;str[i]!=0;i++){
	 	lcdChar(str[i]);
	}
}
void lcdContro(uint8_t i){
	if(i==0)
		lcdCmd(0x0c);
	else
		lcdCmd(0x0f);
}
void lcdCustom(uint8_t location,uint8_t x,uint8_t y, char * lcd_char) {
  	uint8_t i;
    lcdCmd(0x40+location*8);
    for (i = 0; i<=7; i++)
	{ 
		lcdChar(lcd_char[i]);
	}
	lcdSet(x,y);
	lcdChar(location);
}
void lcdNumber(uint32_t n){
	uint8_t i,num[10],j=0;
	while(n){
	 	num[j]=n%10;
		n/=10;
		j++;
	}
	for(i=0;i<j;i++){
	 	lcdChar(num[j-i-1]+48);	
	}	
}
void lcdNumberHex(uint32_t h){
	uint8_t i,j=0,hex[8];
	while(h){
		hex[j]=h&0xf;
		h=h>>4;
		j++;
	}
	for(i=0;i<j;i++){
		if(hex[j-i-1]<10)
			lcdChar(hex[j-i-1]+48);
		else
			lcdChar(hex[j-i-1]+55);
	}
}










