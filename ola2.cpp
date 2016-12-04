//************************** Open Lab Assignment #2****************************

// AUTHOR: Bryce Ault

// DESCRIPTION: draws a 2D Map, calculates min/max, calculates greedy solution from left to right

// INPUT: values into an array, starting row

// OUTPUT: mininum and maximum values, 2D array with greedy solution

// FORMULAS: absolute value of the difference of 2 integers

//*****************************************************************************/



#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//function prototypes
void MapData(int Map[100][100], int rowCount, int colCount);
void drawMap(int Map[100][100], int rowCount, int colCount);
int findMin(int Map[100][100], int rowCount, int colCount);
int findMax(int Map[100][100], int rowCount, int colCount);
int drawLowestElevPath(int Map[100][100], int rowCount, int colCount, int startingRow);

int main()
{	
	//variable declarations
	int Map[100][100];			//array for mapping data
	int rowCount = 100, colCount = 100;		
	int startingRow;

	//function calling
	MapData(Map, rowCount, colCount);	//stores values into the array
	drawMap(Map, rowCount, colCount);	//prints the array
	cout << endl << "The minimum is: " << findMin(Map, rowCount, colCount) << '.' << endl;	//calculates minimum value
	cout << "The maximum is: " << findMax(Map, rowCount, colCount) << '.';	//calculates maximum value

	//Starting column will be at index = 0
	cout << endl << endl << "Enter starting row number: ";
	cin >> startingRow;		//input for starting row

	//calls function to print greedy solution
	drawLowestElevPath(Map, rowCount, colCount, startingRow);

	return 0;
}

//function to store input file into an array
void MapData(int Map[100][100], int rowCount, int colCount)
{
	//open file
	ifstream myIn;
	myIn.open("mapdata.txt");

	//variable declaration for manipulating through array
	int i, j;
	
	//loop through row then by column
	for (i = 0; i < rowCount; i++)
	{
		for (j = 0; j < colCount; j++)
			myIn >> Map[i][j];	//store value
	}
	return;
}

//function to print an array
void drawMap(int Map[100][100], int rowCount, int colCount)
{
	//variable declaration for manipulating through array
	int i, j;

	for (i = 0; i < rowCount; i++)
	{
		for (j = 0; j < colCount; j++)
			cout << Map[i][j] << " ";	//print item
		cout << endl;	//endl after 1 row is done printing
	}
	return;
}

//function calculates minimum
int findMin(int Map[100][100], int rowCount, int colCount)
{
	//variable declarations
	int i, j;
	int data = Map[0][0];	//to store our current working item
	
	//compare current item to all items in the array
	for (i = 0; i < rowCount; i++)
		for (j = 0; j < colCount; j++)
			if (data > Map[i][j])
				data = Map[i][j];	//change item to lower value

		return data; //return item with lowest value
}

int findMax(int Map[100][100], int rowCount, int colCount)
{
	//variable declarations
	int i, j;
	int data = Map[0][0];	//to store our current working item
	
	//compare current item to all items in the array
	for (i = 0; i < rowCount; i++)
		for (j = 0; j < colCount; j++)
			if (data < Map[i][j])
				data = Map[i][j];	//change item to higher value

	return data;	//return item with highest value
}

//function that determines a greedy solution
int drawLowestElevPath(int Map[100][100], int rowCount, int colCount, int startingRow)
{	
	//variable declarations
	int data, curRow = startingRow, curCol = 0;
	int data1, data2, data3;	//store items in question for next move
	int Path[100][100];	//array to draw path
	
	//starting location
	data = Map[curRow][curCol];

	//loop through every column, draw path with '1'
	for (curCol; curCol < colCount; curCol++)
	{
		Path[curRow][curCol] = 1;	//set corrisponding array item to 1
		data1 = Map[curRow - 1][curCol + 1];
		data2 = Map[curRow][curCol + 1];		//initialize items in question
		data3 = Map[curRow + 1][curCol + 1];

		if (curRow == 0)		//condition for top row
		{
			//compare differences of items in question then move location
			if (abs(data - data3) < abs(data - data2))
			{
				data = data3; curRow += 1;	//increment row
			}
			else
			{
				data = data2;
			}
		}

		else if (curRow == 99)	//condition for bottom row
		{
			//compare differences of items in question then move location
			if (abs(data - data1) < abs(data - data2))
			{
				data = data1; curRow -= 1;	//decrement row
			}
			else
			{
				data = data2;
			}
		}

		else   //conditon for any middle row
		{
			//if difference of top row is smaller, go there 
			if (abs(data - data1) < abs(data - data2) && abs(data - data1) < abs(data - data3))
			{
				data = data1;	curRow -= 1;	//decrement row
			}

			//if difference of middle row is smaller, go there
			else if (abs(data - data2) < abs(data - data1) && abs(data - data2) < abs(data - data3))
			{
				data = data2;
			}

			//if difference of bottom row is smaller, go there
			else if (abs(data - data3) < abs(data - data1) && abs(data - data3) < abs(data - data2))
			{
				data = data3;	curRow += 1;	//increment row
			}

			//if difference of middle is same as other items, go there
			else if (abs(data - data2) == abs(data - data1) || abs(data - data2) == abs(data - data3))
			{
				data = data2;
			}
			else
			{
				srand(time(NULL));
				int coin = rand() % 2;
				
				//if top and bottom row have same difference, choose one at random
				if (coin == 0)
				{
					data = data1; curRow += 1;	//increment row
				}
				else
				{
					data = data3; curRow -= 1;	//decrement row
				}
			}	
		}
	}
	Path[startingRow][0] = 1; //set starting point to 1

	//set all other items in the array to 0
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			if (Path[i][j] != 1)
				Path[i][j] = 0;
		}
	}

	drawMap(Path, rowCount, colCount);	//draw the path
	return 0;
}
