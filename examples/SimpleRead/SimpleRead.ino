/*
  Created on 4 Apr 2019 by
  Luai Malek and
  Roman Schulte
*/

/*
  Prints out the ID of any chip you scan.
*/

#include "SimpleRFID.h"

SimpleRFID simple_rfid;
String ID = "";

void setup() 
{
  Serial.begin(9600); 
  simple_rfid(2,3);
}

void loop() {
  if (simple_rfid.available()) //check if data is ready to be read
  {
    ID = simple_rfid.readID(); //read the ID
    Serial.println(); //print the String 
  }

  //Here you can add additional behaviour if wanted.
}
