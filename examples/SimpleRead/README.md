# SimpleRead

This example demonstrates how you can use `SimpleRFID` to read the ID from a near RFID tag.

## Materials

To run this example you need these components:
- [Arduino](https://store.arduino.cc/arduino-genuino/boards-modules)
- [Groove RFID Reader](http://wiki.seeedstudio.com/Grove-125KHz_RFID_Reader/)
- At least one RFID tag (chip or card)
- Wires
- Bread Board or [Grove Shield](http://wiki.seeedstudio.com/Base_Shield_V2/)

## Setup

1. Open the example skecth by selecting `File > Examples > SimpleRFID > SimpleNoise`
2. Connect the RFID-reader to your Arduino (RX to PIN2, TX to PIN3)
3. Connect your Ardunio to your PC
4. Upload the code to your Arduino
5. Open the serial monitor by selecting `Tools > Serial Monitor`

## Usage

Hold a RFID tag close to the RFID reader and look at the monitor. The monitor
should print the ID of the tag.
