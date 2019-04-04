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
        check_int = (int) temp_char;
        if(check_int != 2 && check_int != 3 && check_int != 255)
        {
            result += (char) temp_char;
        }
    }while(check_int != 3);
    return result;
}
