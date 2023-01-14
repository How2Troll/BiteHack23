
#include "inc/example.hpp"
#include "inc/pirSensor.hpp"
#include "inc/serialBT.hpp"

BluetoothSerial SerialBT;

void setup(){
    setupPir();
    setupBT(SerialBT);
}


void loop(){
    bool motionState = loopPir();
    yhy();
}