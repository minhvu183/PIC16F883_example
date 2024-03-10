#include "eeprom.h"

void writeEeprom(uint8_t add, uint8_t data){
    bool i = GIE;
    EEADR = add;
    EEDAT = data;
    EEPGD = 0;
    WREN = 1;
    GIE = 0;
    EECON2 = 0x55;
    EECON2 = 0xaa;
    WR = 1;
    while(WR);
    GIE = i;
    WREN = 0;   
}

uint8_t readEeprom(uint8_t add){
    uint8_t result;
    EEADR = add;
    EEPGD = 0;
    RD = 1;
    while(RD);
    result = EEDAT;
    return result;
    
}