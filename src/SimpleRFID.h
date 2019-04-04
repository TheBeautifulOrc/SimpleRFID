/*
    SIMPLE_RFID.h - Library intended for easy use of the "Grove-125KHz RFID Reader v1.0".
    Created by Roman Schulte and Luai Malek, April 4, 2019.
    Released into the public domain.
*/

#ifndef SIMPLE_RFID_H
#define SIMPLE_RFID_H

#include "Arduino.h"
#include "SoftwareSerial.h"

class SIMPLE_RFID
{
    public:
    SIMPLE_RFID(byte tx_pin, int rx_pin);
    bool available();
    String getID();
    private:
    SoftwareSerial simpleRFID_SoftSerial;
};

#endif