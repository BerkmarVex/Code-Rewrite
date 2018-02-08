#ifndef MAIN_H_
#define MAIN_H_

#include <API.h>

#ifdef __cplusplus
extern "C" {
  #endif

  void autonomous();
  void initializeIO();
  void initialize();
  void operatorControl();

  static const int LEFTMOTOR  = 1;
  static const int RIGHTMOTOR = 10;


#ifdef __cplusplus


}

#endif

#endif
