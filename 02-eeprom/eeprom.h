#ifndef EEPROM_H
#define EEPROM_H

#include "main.h"

void writeEeprom(uint8_t add, uint8_t data);
uint8_t readEeprom(uint8_t add);
        
#endif