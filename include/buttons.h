#ifndef BUTTONS_H
#define BUTTONS_H

#ifdef __cplusplus

extern "C" {
#endif

static bool buttonCheck(bool pressed, bool *waspressed) {
    if(pressed && waspressed){
        return false;
    }

    else if(pressed){
        waspressed = true;
        return true;
    }

    else{
        waspressed = false;
        return false;
    }
}
static int *dualZone(int joyRight, int joyLeft, int rangeOneStart, int rangeOneEnd, int rangeTwoStart, int rangeTwoEnd, double scalar) {
    static int vars[2];

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
    
#ifdef __cplusplus

}

#endif

#endif
