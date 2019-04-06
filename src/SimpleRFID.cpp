/*
    Created by Roman Schulte and Luai Malek, April 4, 2019.
    Released into the public domain.
*/

#include "Arduino.h"
#include <SoftwareSerial.h>
#include "SimpleRFID.h"

SimpleRFID::SimpleRFID(uint8_t rx_pin, uint8_t tx_pin)
{
    _simpleRFID_SoftSerial = new SoftwareSerial(rx_pin, tx_pin);
    _simpleRFID_SoftSerial->begin(9600); //The RFID readers baudrate is fixed at 9600
}

SimpleRFID::~SimpleRFID()
{
    delete _simpleRFID_SoftSerial;
}

bool SimpleRFID::available()
{
    return _simpleRFID_SoftSerial->available() > 0;
}

String SimpleRFID::readID()
{
    String result = "";
    unsigned char temp_char;
    int check_int;
    do{
        temp_char = (unsigned char) _simpleRFID_SoftSerial->read();
        check_int = (int) temp_char;    //used to check, if temp_char is valid data
        //Control-characters are rendered invalid data. Consult ASCII-table for further information.
        if(check_int != 2 && check_int != 3 && check_int != 255)
        {
            result += (char) temp_char; //append valid character to output-string
        }
    }while(check_int != 3); //the control-character "end of message" ends the reading process
    while(_simpleRFID_SoftSerial.available())
    {
        char junk = _simpleRFID_SoftSerial->read();    //clear input buffer in case the reader read twice
    }
    return result;
}
