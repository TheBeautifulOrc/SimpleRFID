/*
    SIMPLE_RFID.h - Library intended for easy use of the "Grove-125KHz RFID Reader v1.0".
    Created by Roman Schulte and Luai Malek, April 4, 2019.
    Released into the public domain.
*/

#ifndef SIMPLE_RFID_H
#define SIMPLE_RFID_H

#include "Arduino.h"
#include "SoftwareSerial.h"

/*
    Abstraction handling the serial interface and data-type conversions internally.
    Users only need to use the provided high-level functions.
*/
class SimpleRFID
{
    public:
    //Constructor
    SimpleRFID(uint8_t rx_pin, uint8_t tx_pin);

    //Returns whether the reader is holding data, ready to be read
    bool available();

    //Returns the ID of the currently read RFID-chip 
    String readID();

    //Destructor
    ~SimpleRFID();

    private:
    SoftwareSerial* _simpleRFID_SoftSerial;
};

#endif
