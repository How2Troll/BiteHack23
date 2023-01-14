#include "BluetoothSerial.h"
#include "inc/serialBT.hpp"



void setupBT(BluetoothSerial SerialBT) {
  SerialBT.begin("Skunks"); 
  Serial.println("The device started, now you can pair it with bluetooth!");
}

int checkSerial(BluetoothSerial SerialBT) {
  int direction;
    if (SerialBT.available()) 
    {
      direction = SerialBT.read();
    }
  return direction;
}