
#include "inc/example.hpp"
#include "inc/pirSensor.hpp"
#include "BluetoothSerial.h"
#include <HCSR04.h>
#include <L298NX2.h>

#define pump 15
void move();
BluetoothSerial SerialBT;
UltraSonicDistanceSensor distanceSensor(14, 27);
// Pin definition
const unsigned int EN_A = 16;
const unsigned int IN1_A = 5;
const unsigned int IN2_A = 18;

const unsigned int IN1_B = 19;
const unsigned int IN2_B = 21;
const unsigned int EN_B = 17;
const uint8_t buzz = 4;

int direction;
bool manual_mode = true;
float meas = 0;
// Initialize both motors
L298NX2 motors(EN_A, IN1_A, IN2_A, EN_B, IN1_B, IN2_B);

void setup(){
    setupPir();
    Serial.begin(115200);
    SerialBT.begin("Skunks");
    pinMode(buzz, OUTPUT);
    digitalWrite(buzz, LOW);
    pinMode(pump, OUTPUT);
}

void loop()
{
  Serial.println(distanceSensor.measureDistanceCm());
  delay(500);
  if (SerialBT.available()) 
  {
    direction = SerialBT.read();
  }
  delay(20);
  bool motionState = loopPir();
  move(motionState);
}


void move(bool state){
  if(manual_mode){
  if(direction == 0x31){
        motors.reset();
        Serial.write("ua1\n");
        delay(10);
        motors.setSpeedA(0x80);
        motors.setSpeedB(0x80);

        motors.forwardA();
        motors.forwardB();
    }
    else if(direction == 0x32){
        motors.reset();
        Serial.write("ua2\n");
        delay(10);
        motors.setSpeedA(0x00);
        motors.setSpeedB(0x00);
        motors.stopA();
        motors.stopB();
    }
    else if(direction == 0x34){
        motors.reset();
        Serial.write("ua3\n");
        delay(10);
        motors.setSpeedA(0x80);
        motors.setSpeedB(0x40);

        motors.forwardA();
        motors.backwardB();
    }
    else if(direction == 0x33){
        motors.reset();
        Serial.write("ua4\n");
        delay(10);
        motors.setSpeedB(0x80);
        motors.setSpeedA(0x40);

        motors.backwardA();
        motors.forwardB();
    }
      else if(direction == 0x35){
        manual_mode = false;
    }
    if(state == true){
      digitalWrite(buzz, HIGH);
      digitalWrite(pump, HIGH);
      delay(10);
      digitalWrite(buzz, LOW);
      digitalWrite(pump, LOW);
    } 
  }
  else{
    meas = distanceSensor.measureDistanceCm();
    if(meas>0 && meas<10)
    {
        motors.reset();
        Serial.write("ua4\n");
        delay(10);
        motors.setSpeedB(0x80);
        motors.setSpeedA(0x40);
        motors.backwardA();
        motors.forwardB();
        if(state){        
        digitalWrite(pump, HIGH);
        digitalWrite(buzz, HIGH);
        delay(1000);
        }
    }
    else {
        motors.reset();
        Serial.write("ua4\n");
        digitalWrite(buzz, LOW);
        digitalWrite(pump, LOW); 
        delay(10);
        motors.setSpeedB(0x80);
        motors.setSpeedA(0x80);
        motors.forwardA();
        motors.forwardB();
    }
  if (SerialBT.available()) 
    {
      if (SerialBT.read() == 0x31);
      {
        manual_mode = true;
      }
    }
  }
}