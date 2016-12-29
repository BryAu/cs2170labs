//************************** Open Lab Assignment #4****************************


// AUTHOR: Bryce Ault

// DESCRIPTION: Initializes a starting position and moves an Object according to input file

// INPUT: Starting x & y positions, characters for moving the robot

// OUTPUT: current position for robot, and total distance travelled by robot

//*****************************************************************************/



#include <iostream>
#include <fstream>
#include <stdio.h>
#include "robot.h"

using namespace std;

int main()
{
	//variable declarations
	Robot myRobot;
	int xPos, yPos;
	char movement;

	//open input file
	ifstream myIn;
	myIn.open("robotTravel.txt");

	//priming read
	//read 2 integer values for starting position
	myIn >> xPos >> yPos >> movement;	//read first character
	myRobot.setRobot(xPos, yPos);

	//while data in file
	while (myIn)
	{
		//move robot and print current position
		myRobot.moveTo(movement);
		myRobot.displayRobot();

		//read next data
		myIn >> movement;
	}
	return 0;
}

