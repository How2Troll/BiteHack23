#include "inc/pirSensor.hpp"

int val;
bool motionState;

void setupPir() {
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  Serial.begin(9600);
}

bool loopPir() {
  val = digitalRead(pirPin);

  if (val == HIGH) {
    digitalWrite(ledPin, HIGH);

    if (motionState == false) {
      Serial.println("Motion detected!");
      motionState = true;
    }
  }

  else {
    digitalWrite(ledPin, LOW);
    if (motionState == true) {
      Serial.println("Motion ended!");
      motionState = false;
    }
  }
  return motionState;
}