#include <src/hc-sr501.h>

int val = 0;
bool motionState; // We start with no motion detected.

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