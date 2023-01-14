
#include "inc/example.hpp"
#include "inc/pirSensor.hpp"
#include "BluetoothSerial.h"

#include <L298NX2.h>

BluetoothSerial SerialBT;
// Pin definition
const unsigned int EN_A = 16;
const unsigned int IN1_A = 5;
const unsigned int IN2_A = 18;

const unsigned int IN1_B = 19;
const unsigned int IN2_B = 21;
const unsigned int EN_B = 17;

int direction;

// Initialize both motors
L298NX2 motors(EN_A, IN1_A, IN2_A, EN_B, IN1_B, IN2_B);

void setup(){
    setupPir();
    Serial.begin(115200);
    SerialBT.begin("Skunks");
}

void loop(){
  if (SerialBT.available()) 
  {
    direction = SerialBT.read();
  }
  delay(20);
  bool motionState = loopPir();
  if(direction == 0x31){
        motors.reset();
        Serial.write("ua1\n");
        delay(2000);
        motors.setSpeedA(0x40);
        motors.setSpeedB(0x40);

        motors.forwardA();
        motors.forwardB();
    }
    else if(direction == 0x32){
        motors.reset();
        Serial.write("ua2\n");
        delay(2000);
        motors.setSpeedA(0x00);
        motors.setSpeedB(0x00);
        motors.stopA();
        motors.stopB();
    }
}