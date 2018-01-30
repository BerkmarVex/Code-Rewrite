#include "main.h"

bool buttonCheck(bool pressed, bool *waspressed) {
    if(pressed && waspressed){
        return false;
        }

    else if(pressed){
        waspressed = &pressed;
        return true;
    }

    else{
        waspressed = &pressed;
        return false;
    }
}

int *dualZone(int joyRight, int joyLeft, int rangeOneStart, int rangeOneEnd, int rangeTwoStart, int rangeTwoEnd, double scalar) {
    int vars[2];

    if((abs(joyRight) >= rangeOneStart && abs(joyRight) <= rangeOneEnd)) {
        vars[0] = joyRight/2;
    }

    if((abs(joyLeft) >= rangeOneStart && abs(joyLeft) <= rangeOneEnd)) {
            vars[1] = joyLeft/2;
    }

    else{
        vars[0] = joyRight;
        vars[1] = joyLeft;
    }

    return vars;
}

