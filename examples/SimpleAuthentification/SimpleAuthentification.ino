/*
  Distinguish between authorized and unauthorized tags and play 
  different beep-tones accordingly.

  Created on 4 Apr 2019 by
  Luai Malek and
  Roman Schulte
*/


#include "SimpleRFID.h"

String authorized_tags = "";  //this string will hold all registered IDs, seperated by whitespaces

// Initialize reader with pins 2 and 3 (D2 on base shield).
const uint8_t rfid_rx_pin = 2;
const uint8_t rfid_tx_pin = 3;
SimpleRFID simple_rfid(rfid_rx_pin, rfid_tx_pin);

// Connect buzzer with pin 5 (D5 on base shield).
const uint8_t buzzer_pin = 5;

// Connect button with pin 7 (D7 on base shield).
const uint8_t button_pin = 7; 

void setup() 
{
  // Setup pin modes
  pinMode(buzzer_pin, OUTPUT);
  pinMode(button_pin, INPUT);
}

void loop() 
{
  // Is RFID tag in front of reader?
  if (simple_rfid.available()) 
  {
    String new_ID = simple_rfid.readID();

    // Is button pressed?
    if (digitalRead(button_pin) == HIGH)
    {
      // Check if RFID tag is already authorized
      int index = authorized_tags.indexOf(new_ID);
      if (index > 0) 
      {
        // Remove tag from authorized list
        authorized_tags = authorized_tags.substring(0, index - 1) \
        + authorized_tags.substring(index + new_ID.length());
        beep(200, 2);
      }
      else
      {
        // Add tag to authorized list
        authorized_tags = authorized_tags + " " + new_ID;
        beep(200, 1);
      }   
    }
    else 
    {
      int index = authorized_tags.indexOf(new_ID);

      // Check if tag is authorized
      if (index > 0) 
      {
        //Access permitted :)
        beep(600, 1);
      }
      else
      {
        // Access denied!
        beep(600, 2);
      }  
    }
  }
}

// Plays a beep sound
void beep(int duration, int times)
{
  for(int i = 0; i < times; ++i)
  {
    digitalWrite(buzzer_pin, HIGH);
    delay(duration/2);
    digitalWrite(buzzer_pin, LOW);
    delay(duration/2);
  }
}
