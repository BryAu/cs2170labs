//************************** Open Lab Assignment #1****************************

// FILE: ola1.cc

// AUTHOR: Bryce Ault

// DESCRIPTION: This program determines the remainder of long number division

// INPUT: Long numbers too long for integer division

// OUTPUT: Remainder of the number when divided by 97

// FORMULAS: longNumber % 97

//*****************************************************************************/

//did not test necessary libraries
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>


using namespace std;


int main()

{
	//variable declarations
	int divider = 97;
	int remainder, strlength;


	string data, tempstr;		//input data
	ifstream myIn;		//input file

	//open input file
	myIn.open("longNumber.txt");
	//priming read
	myIn >> data;
	
	//Loop through all data in txt file
	while (myIn)
	{
		cout << "The long integer number is: " << data << endl;  //print string to be divided
		
		//get first 9 digits and calculate remainder
		tempstr = data.substr(0, 9);
		remainder = atoi((tempstr).c_str()) % divider;
		
		strlength = data.length() - 9;
		int i = 9;	//index for string manipulation

		//while there are characters in data
		while (strlength > 0)
		{
			if (strlength >= 7)  //get next 7 characters
			{
				//concatinate prev remainder to new remainder
				remainder = remainder * 10000000;
				tempstr = data.substr(i, 7);
				remainder = (remainder + atoi((tempstr).c_str())) % divider;

				//pass through string characters and shift the index
				strlength = strlength - 7;
				i = i + 7;
			}
			else	//if there are less than 7 characters left
			{
				//get rest of the string
				tempstr = data.substr(data.length() - strlength);	//10^n when n is the number
				remainder = remainder * pow(10, tempstr.length());	//of characters left in the string
				remainder = (remainder + atoi((tempstr).c_str())) % divider;
				strlength = strlength - 7;
			}
		}
		//print remainder
		cout << "Divider = " << divider << endl << "Remainder = " << remainder << endl << endl;

		//process next data
		myIn >> data;
		
	}
	return 0;
}

