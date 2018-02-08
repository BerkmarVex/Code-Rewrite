#ifndef BUTTONS_H
#define BUTTONS_H
#include <main.h>

#ifdef __cplusplus

extern "C" {
#endif
int n = 0;
bool toggle;
static bool buttonCheck(bool press) {
  if(press && n == 0){
    n = 1;
    toggle = !toggle;
  }
  else if(!press){
    n = 0;
  }
  return toggle;
}

#ifdef __cplusplus

}

#endif

#endif
