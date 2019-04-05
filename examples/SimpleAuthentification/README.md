# SimpleAuthentificator

This example demonstrates how `SimpleRFID` can be used to register and recognize an RFID tag. 
By holding down a button tags can be registered/unregistered. When the button is released the system will compare any tag it reads to it's memory and will recognize known IDs. A Bbuzzer acts as audible user-feedback.  

## Materials

To run this example you need these components:
- [Arduino](https://store.arduino.cc/arduino-genuino/boards-modules)
- [Groove RFID Reader](http://wiki.seeedstudio.com/Grove-125KHz_RFID_Reader/)
- At least one RFID tag (chip or card)
- Buzzer
- Button
- Wires
- Bread board or [Grove Shield](http://wiki.seeedstudio.com/Base_Shield_V2/)

## Setup

1. Open the example sketch by selecting `File > Examples > SimpleRFID > SimpleAuthentificator`
2. Connect the RFID-reader to your Arduino (RX to PIN2, TX to PIN3)
3. Connect the buzzer to your Arduino as well (SIG to PIN5)
4. Finally connect the button to your Arduino (SIG to PIN7)
5. Connect your Ardunio to your PC
6. Upload the code to your Arduino

## Usage

1. Register the RFID tags by holding down the button and moving the tag close to the reader. If successful a short beep-tone should be audible. (You can also unregister tags, that have bee registered previously, by holding down the button and once again holding the tags close to the reader. If unregistered successfully two short beep-tones should be heared.)
2. To check, whether a tag has been registered, keep the button released and move the tag in question to the RFID reader. If it has been registered previously, one long beep-tone should be audible. If not, two long beep-tones will appear. 
