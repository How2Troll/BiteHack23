
#include "inc/example.hpp"
#include "inc/pirSensor.hpp"
#include "BluetoothSerial.h"

#include <L298NX2.h>


void move();
BluetoothSerial SerialBT;
// Pin definition
const unsigned int EN_A = 16;
const unsigned int IN1_A = 5;
const unsigned int IN2_A = 18;

const unsigned int IN1_B = 19;
const unsigned int IN2_B = 21;
const unsigned int EN_B = 17;
const uint8_t buzz = 4;

int direction;

// Initialize both motors
L298NX2 motors(EN_A, IN1_A, IN2_A, EN_B, IN1_B, IN2_B);

void setup(){
    setupPir();
    Serial.begin(115200);
    SerialBT.begin("Skunks");
    pinMode(buzz, OUTPUT);
    digitalWrite(buzz, LOW);
}

void loop(){
  if (SerialBT.available()) 
  {
    direction = SerialBT.read();
  }
  delay(20);
  bool motionState = loopPir();
  move(motionState);
}


void move(bool state){
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
          if(state == true){
            digitalWrite(buzz, HIGH);
            motors.forward();
            delay(1000);
            motors.stop();
            //TODO: piss();
            digitalWrite(buzz, LOW);
          }
    }
    
    else if(direction == 0x34){
        motors.reset();
        Serial.write("ua3\n");
        delay(2000);
        motors.setSpeedA(0x80);
        motors.setSpeedB(0x0A);

        motors.forwardA();
        motors.backwardB();
    }
    else if(direction == 0x33){
        motors.reset();
        Serial.write("ua4\n");
        delay(2000);
        motors.setSpeedB(0x80);
        motors.setSpeedA(0x0A);

        motors.backwardA();
        motors.forwardB();
    }
}