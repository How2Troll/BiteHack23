#include "BluetoothSerial.h"
#include "inc/serialBT.hpp"

int direction;
void setupBT(BluetoothSerial SerialBT) {
  SerialBT.begin("Skunks"); 
  Serial.println("The device started, now you can pair it with bluetooth!");
}

char checkSerial(BluetoothSerial SerialBT) {
  if (SerialBT.available()) 
  {
    direction = SerialBT.read();
  }
  delay(20);
  return direction;
}