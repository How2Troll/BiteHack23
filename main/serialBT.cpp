#include "BluetoothSerial.h"
#include "inc/serialBT.hpp"

void setupBT(BluetoothSerial SerialBT) {
  SerialBT.begin("Skunks"); 
  Serial.println("The device started, now you can pair it with bluetooth!");
}

char checkSerial(BluetoothSerial SerialBT) {
  if (SerialBT.available()) 
  {
    delay(20);
    return SerialBT.read();
  }
  else return 0;
}