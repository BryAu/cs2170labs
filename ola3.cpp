//************************** Open Lab Assignment #3****************************

// AUTHOR: Bryce Ault

// DESCRIPTION: Finds a path for a robot to travel based on the array item

// INPUT: rows/columns/startrow and characters for the array

// OUTPUT: the character array and the robot's path

// FORMULAS: up for N, down for S, right for E, left for W

//*****************************************************************************/



#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

//function declaration
void move(char grid[10][10], int startCol, int numRow, int numCol);		//moves the robot to the next position
int nextPos(char grid[10][10], int curRow, int curCol, char robotpos);		//returns the value of the next position

int main()
{
	//variable declaration
	int numRow, numCol, startCol;
	char grid[10][10];	//store array

	//open text file
	ifstream myIn;
	myIn.open("robotmotion.txt");

	//priming read
	myIn >> numRow >> numCol >> startCol;

	//while there is data and while number of rows does not equal 0
	while ((myIn) && (numRow != 0))
	{
		//loop through array indices
		for (int i = 0; i < numRow; i++)
		{
			for (int j = 0; j < numCol; j++)
			{
				myIn >> grid[i][j];		//set value
				cout << grid[i][j];		//and print
			}		cout << endl;
		}cout << endl;
		//function call to move robot around the array
		move(grid, startCol, numRow, numCol);
		
		//read next data
		myIn >> numRow >> numCol >> startCol;
	}
	return 0;
}

//function moves robot around the array
void move(char grid[10][10], int startCol, int numRow, int numCol)
{
	int curRow = 0, curCol = startCol;	//variables for robot position

	//starting position for robot
	char robotpos = grid[curRow][startCol];

	//while still inside the array
	while((curRow != -1) && (curCol != -1))
	{
		//if next position is not 1, then enter
		if (nextPos(grid, curRow, curCol, robotpos) != '1')
		{
			if (robotpos == 'N')	//current position is 'N'
			{
				curRow -= 1;	//move up 1 index in the array
				robotpos = grid[curRow][curCol];	//set robot to current position
				grid[curRow + 1][curCol] = '1';		//set path array index to 1
			}

			else if (robotpos == 'S')	//current position is 'S'
			{
				curRow += 1;	//move down 1 index in the array
				robotpos = grid[curRow][curCol];	//set robot position
				grid[curRow - 1][curCol] = '1';		//set path array index to 1
			}

			else if (robotpos == 'E')	//current positon is 'E'
			{
				curCol += 1;	//move right 1 index in the array
				robotpos = grid[curRow][curCol];	//set robot to current position
				grid[curRow][curCol - 1] = '1';		//set path array index to 1
			}

			else
			{
				curCol -= 1;	//move left 1 index in the array
				robotpos = grid[curRow][curCol];	//set robot to current position
				grid[curRow][curCol + 1] = '1';		//set path array index to 1
			}
		}
		//if the next posion has already been visited, break the loop
		else if (nextPos(grid, curRow, curCol, robotpos) == '1')
		{
			break;
		}
	} 

	//if next position has already been visited, then robot is looping
	if (nextPos(grid, curRow, curCol, robotpos) == '1')
		cout << "Robot stuck in a loop!" << endl;
	//if next position is outside array, then robot exited
	else
		cout << "Robot found a path!" << endl;

	//print the path array
	for (int i = 0; i < numRow; i++)
	{
		for (int j = 0; j < numCol; j++)
		{	
			if (grid[i][j] != '1')
				grid[i][j] = '0';
			cout << grid[i][j];
		}cout << endl;
	}
	cout << endl;
	return;
}

//function returning the next position in the array
int nextPos(char grid[10][10], int curRow, int curCol, char robotpos)
{
	if (robotpos == 'N')	//checking current position
	{
		curRow -= 1;
		return grid[curRow][curCol];	//return next position
	}

	else if (robotpos == 'S')	//checking current position
	{
		curRow += 1;
		return grid[curRow][curCol];		//return next position
	}

	else if (robotpos == 'E')	//checking current position
	{
		curCol += 1;
		return grid[curRow][curCol];		//return next position
	}

	else          //checking current position
	{
		curCol -= 1;
		return grid[curRow][curCol];		//return next position
	}
}
