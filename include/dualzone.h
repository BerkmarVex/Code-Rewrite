#ifndef DUALZONE_H
#define DUALZONE_H
#include <main.h>

#ifdef __cplusplus

extern "C" {
#endif

 static int dualzone(int speed, int range, double multiplier, double multiplier2){
   if(abs(speed) > 15 || abs(speed) > 15) {
     if (abs(speed) < range){
        speed = speed * multiplier;
      }
      if (abs(speed) >=range){
        speed = speed * multiplier2;
      }
    }
  if (abs(speed) <= 15 || abs(speed) <= 15){
    speed = 0;
    motorStop(LEFTMOTOR);
    motorStop(RIGHTMOTOR);
  }
  return speed;
  }
#ifdef __cplusplus

}
#endif

#endif
