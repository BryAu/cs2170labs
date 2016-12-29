#ifndef ROBOT_H
#define ROBOT_H

class Robot
{
private:
	//variable declarations
	char character;		//for character input
	int xPos;			//storing x position
	int yPos;			//storing y position
	int disTravelled;	//total distance robot travels

public:
	void setRobot(int xLocation, int yLocation);	//initial robot location
	void displayRobot();	//prints the current robot location
	void moveTo(char ch);	//moves robot accoring to character input
};

#endif
