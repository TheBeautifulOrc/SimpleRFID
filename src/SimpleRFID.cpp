#include "Arduino.h"
#include "SoftwareSerial.h"
#include "SimpleRFID.h"

SIMPLE_RFID::SIMPLE_RFID(int tx_pin, int rx_pin)
{
    _simpleRFID_SoftSerial = SoftwareSerial(tx_pin, rx_pin);#
}