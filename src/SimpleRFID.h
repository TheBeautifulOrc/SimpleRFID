/*
    SIMPLE_RFID.h - Library intended for easy use of the "Grove-125KHz RFID Reader v1.0".
    Created by Roman Schulte and Luai Malek, April 4, 2019.
    Released into the public domain.
*/

#ifndef SIMPLE_RFID_H
#define SIMPLE_RFID_H

#include "Arduino.h"
#include "SoftwareSerial.h"

class SimpleRFID
{
    public:
    SimpleRFID(uint8_t rx_pin, uint8_t tx_pin);
    bool available();
    String readID();
    ~SimpleRFID();
    private:
    SoftwareSerial* _simpleRFID_SoftSerial;
};

#endif
