#include "Arduino.h"
#include "SoftwareSerial.h"
#include "SimpleRFID.h"

SimpleRFID::SimpleRFID(int tx_pin, int rx_pin)
{
    _simpleRFID_SoftSerial = SoftwareSerial(tx_pin, rx_pin);
    _simpleRFID_SoftSerial.begin(9600); //The RFID readers baudrate is fixed at 9600
}

SimpleRFID::available()
{
    return _simpleRFID_SoftSerial.available();
}

SimpleRFID::readID()
{
    String result = "";
    unsigned char temp_char;
    int check_int;
    do{
        temp_char = _simpleRFID_SoftSerial.read();
        check_int = (int) temp_char;
        if(check_int != 2 && check_int != 3 && check_int != 255)
        {
            result += (String) temp_char;
        }
    }while(check_int != 3);
    return result;
}