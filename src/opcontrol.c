#include "main.h"
#include "buttons.h"

bool testers1 = false;
bool testers2 = false;
bool testers3 = false;
bool switchC = true;
bool leftWest, rightEast, rightSouth;
int leftJoyX, leftJoyY, rightJoyX, rightJoyY;
int *tankDriveValues[2];

void update(char input){
	switch (input) {
		case 'A':
			leftWest = joystickGetDigital(1,7,JOY_LEFT);
			rightEast = joystickGetDigital(1,8,JOY_RIGHT);
			rightSouth = joystickGetDigital(1,8, JOY_DOWN);
			buttonCheck(leftWest, &testers1);
			buttonCheck(rightEast, &testers2);
			buttonCheck(rightSouth, &testers3);
			break;
		case 'B':
		  rightJoyY = joystickGetAnalog(1,2);
			leftJoyY = joystickGetAnalog(1,3);
		  *tankDriveValues = dualZone(leftJoyY, rightJoyY, 0, 90, 91, 120, 0.5); //Tank Dualzone
			break;
		case 'C':
			rightJoyX = joystickGetAnalog(1,1);
			leftJoyY = joystickGetAnalog(1,3);
			dualZone(rightJoyX, rightJoyY, 0, 120, 121, 180, 0.5); //Arcade Dualzone
	}
}

void buttonOc(){
	update('A');
	if(leftWest && rightEast){
		if(switchC){
			switchC = false;
		}

		else{
			switchC = buttonCheck(rightEast, &testers2);
		}

	}

	else{
		//switchC = false;
	}
}

void tank(){
	update('B');
 	motorSet(2, *tankDriveValues[0]);
	motorSet(3, *tankDriveValues[1]);
}

void operatorControl() {
	while (1) {
		buttonOc();
		tank();
		if(switchC){
			printf("Hello\n");
		}
			else {
				printf("BLAHH\n");
			}
		delay(20);
	}
}
