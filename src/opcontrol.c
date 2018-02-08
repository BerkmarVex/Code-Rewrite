#include "main.h"
#include "buttons.h"
#include "dualzone.h"

bool switchC = true;
bool toggleS;
bool leftWest, rightEast, rightSouth;
int leftJoyX, leftJoyY, rightJoyX, rightJoyY;


void tank();
void arcade();


void update(char input){
	switch (input) {
		case 'A':
			leftWest = joystickGetDigital(1,7,JOY_LEFT);
			rightEast = joystickGetDigital(1,8,JOY_RIGHT);
			rightSouth = joystickGetDigital(1,8, JOY_DOWN);
			toggleS = buttonCheck(rightEast);
			break;
		case 'B':
		  rightJoyY = joystickGetAnalog(1,2);
			leftJoyY	= joystickGetAnalog(1,3);
			rightJoyY = dualzone(rightJoyY, 90, 0.5, 2);
			leftJoyY = dualzone(leftJoyY, 90, 0.5, 2);
			break;
		case 'C':
			rightJoyX = joystickGetAnalog(1,1);
			leftJoyY = joystickGetAnalog(1,3);
	}
}

void buttonOc(){
	update('A');
		if(toggleS){
			tank();
		}
		else if(!toggleS){
			arcade();
		}
	}

void tank(){
	update('B');
 	motorSet(RIGHTMOTOR, rightJoyY);
	motorSet(LEFTMOTOR, leftJoyY);
}
void arcade(){
	update('B');
}
void operatorControl() {
	while (1) {
		buttonOc();
		printf("right:%d\n", rightJoyY);
		printf("left:%d\n", leftJoyY);
		delay(20);
	}
}
