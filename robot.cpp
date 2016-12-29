#include "robot.h"
#include <iostream>

using namespace std;

//starting position
void Robot::setRobot(int xLocation, int yLocation)
{
	//initalize variables
	xPos = xLocation;
	yPos = yLocation;
	disTravelled = 0;

	//print starting location
	cout << "Starting Robot position is x: " << xPos << " y: " << yPos << endl << endl;
}

//prints current robot position
void Robot::displayRobot()
{
	cout << "Current robot position is x: " << xPos << " y: " << yPos << endl;
	cout << "Total Distance: " << disTravelled << endl << endl;
}

//moves robot accoring to character input
void Robot::moveTo(char ch)
{
	//set character equal to input data
	character = ch;

	//moving North
	if (character == 'N')
	{
		xPos -= 1;			//subtract 1 from x position
		disTravelled += 1;	//add 1 to total distance travelled
	}

	//moving South
	else if (character == 'S')
	{
		xPos += 1;			//add 1 to x position
		disTravelled += 1;	//add 1 to total distance travelled
	}
	
	//moving East
	else if (character == 'E')
	{
		yPos += 2;			//add 2 to y position
		disTravelled += 2;	//add 2 to total distance travelled
	}

	//moving West
	else if (character == 'W')
	{
		yPos -= 2;			//subtract 2 from x position
		disTravelled += 2;	//add 2 to total distance travelled
	}
}


