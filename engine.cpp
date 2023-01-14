#include "inc/engine.hpp"




void setupENG(L298NX2 motors){
    motors.stop();
}

void move(L298NX2 motors, char input){
    if(input == 'w'){
        motors.forward();
    }
    if(input == 's'){
        motors.backward();
    }
}