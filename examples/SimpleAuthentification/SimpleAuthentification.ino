/*
  Created on 4 Apr 2019 by
  Luai Malek and
  Roman Schulte
*/


/*
  Distinguish between authorized and unauthorized tags and play different beep-tones accordingly.
*/

#include "SimpleRFID.h"

String authorized_tags = "";  //this string will hold all registered IDs, seperated by whitespaces
const uint8_t rfid_rx_pin = 2;
const uint8_t rfid_tx_pin = 3;
SimpleRFID simple_rfid(rfid_rx_pin, rfid_tx_pin);
const uint8_t buzzer_pin = 5;
const uint8_t button_pin = 7; 

void setup() {
  pinMode(buzzer_pin, OUTPUT);
  pinMode(button_pin, OUTPUT);
}

void loop() {
  if (digitalRead(button_pin) == HIGH) 
  {
    if (simple_rfid.available()) 
    {
      String new_ID = simple_rfid.read();
      int index = authorized_tags.indexOf(new_ID);
      if (index > 0) 
      {
        authorized_tags = authorized_tags.substring(0, index - 1) \
        + authorized_tags.substring(index + new_ID.length());
        beep(200, 2);
      }
      else
      {
        authorized_tags = authorized_tags + " " + new_ID;
        beep(200, 1);
      }      
    }    
  }
  else
  {
    if (simple_rfid.available()) 
    {
      String new_ID = simple_rfid.read();
      int index = authorized_tags.indexOf(new_ID);
      if (index > 0) 
      {
        beep(600, 1);
      }
      else
      {
        beep(600, 2);
      }   
    }
    
  }
}

void beep(int duration, int times)
{
  for(int i = 0; i < times; ++i)
  {
    digitalWrite(buzzer_pin, HIGH);
    delay(duration/2);
    digitalWrite(buzzer_pin, HIGH);
    delay(duration/2);
  }
}
