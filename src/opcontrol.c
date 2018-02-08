#include "main.h"
#include "buttons.h"
#include "dualzone.h"

bool toggleSS = false;
bool toggleII = false;
bool toggleS;
bool toggleI;
bool leftWest, rightEast, rightSouth;
int leftJoyX, leftJoyY, rightJoyX, rightJoyY, inv;


void update(char input){
	switch (input) {
		case 'A':
			leftWest = joystickGetDigital(1,7,JOY_LEFT);
			rightEast = joystickGetDigital(1,8,JOY_RIGHT);
			rightSouth = joystickGetDigital(1,8, JOY_DOWN);
			toggleS = buttonCheck(rightEast, &toggleSS);
			toggleI = buttonCheck(rightSouth, &toggleII);
			break;
		case 'B':
		  rightJoyY = joystickGetAnalog(1,2);
			leftJoyY	= joystickGetAnalog(1,3);
			rightJoyY = dualzone(rightJoyY, 90, 0.5, 1);
			leftJoyY = dualzone(leftJoyY, 90, 0.5, 1);
			break;
		case 'C':
			rightJoyX = joystickGetAnalog(1,1);
			leftJoyY = joystickGetAnalog(1,3);
			leftJoyY = dualzone(leftJoyY, 90, 0.5, 1);
			rightJoyX = dualzone(rightJoyX, 90, 0.5, 1);
	}
}

void tank(){
	update('B');
 		motorSet(RIGHTMOTOR, inv * rightJoyY);
		motorSet(LEFTMOTOR, inv * leftJoyY);
}

void arcade(){
	update('C');
	motorSet(LEFTMOTOR, (inv * leftJoyY) + rightJoyX);
	motorSet(RIGHTMOTOR, (inv * leftJoyY) - rightJoyX);
}

void buttonOc(){
	update('A');

	if(toggleS){
		tank();
	}
		else if(!toggleS){
			arcade();
		}

		if(toggleI){
			inv = 1;
		}
		else if (!toggleI){
			inv = -1;
		}
}

void operatorControl() {
	while (1) {
		buttonOc();
		printf("right:%d\n", rightJoyX);
		printf("left:%d\n", leftJoyY);
		printf("rightY:%d\n", rightJoyY);
		printf("%d\n", toggleS);
		delay(20);
	}
}
