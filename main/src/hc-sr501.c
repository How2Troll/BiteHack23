#include "hc-sr501.h"

val = 0;

void motionCheckInitialize() //initialize
{
    pinMode(pirPin, input);
    pinMode(ledPin, output);
}

bool motionCheck()
{
  val = digitalRead(pirPin);

  if(val == HIGH)
  {
    motionState == true;
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    motionState == false;
    digitalWrite(ledPin, LOW);
  }
  return motionState;
}