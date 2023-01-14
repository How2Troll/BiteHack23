
#define pirPin 2 // number of pin which will be connected to the sensor
#define ledPin 13

int val;
bool motionState; // We start with no motion detected.

void motionCheckInitialize(); //initialize

bool motionCheck();