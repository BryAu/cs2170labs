//************************** Open Lab Assignment #6****************************

// AUTHOR: Bryce Ault

// DESCRIPTION: Program checks braces to see if they are balanced

// INPUT: string from input file

// OUTPUT: prints the location of error or prints the file is balanced

//*****************************************************************************/




#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	//variable declaration
	stack <char> checkBrace;
	bool isBalanced = true;

	string line;			//store 1 line at a time
	int linePos = 1;		//keep track of line number
	char symbol;
	int stringLen;

	//open file
	ifstream myIn;
	myIn.open("Robotinput.txt");
	getline(myIn, line);

	//while reading file and characters are balanced
	while (myIn && isBalanced)
	{
		//get string length
		stringLen = line.length();

		//loop through entire string
		for (int i = 0; i < stringLen; i++)
		{
			//check each character in the string
			symbol = line.at(i);

			//push onto stack if opening bracket
			if (symbol == '(' || symbol == '[' || symbol == '{')
				checkBrace.push(symbol);

			//if closing bracket
			else if (symbol == ')' || symbol == ']' || symbol == '}')
			{
				//if stack is empty
				if (checkBrace.empty())
				{
					//print unbalanced
					cout << "unbalanced braces. \n";
					isBalanced = false;
				}

				//if closing bracket corresponds to opening bracket, pop the stack
				else if (checkBrace.top() == '(' && symbol == ')')
					checkBrace.pop();

				else if (checkBrace.top() == '[' && symbol == ']')
					checkBrace.pop();

				else if (checkBrace.top() == '{' && symbol == '}')
					checkBrace.pop();

				//if closing bracket does not correspond with opening bracket
				else if (checkBrace.top() != '(' && symbol == ')')
				{
					//brackets are not balanced and print the line error is on
					isBalanced = false;
					cout << "Error occurred on line " << linePos << endl;
				}

				//if closing bracket does not correspond with opening bracket
				else if (checkBrace.top() != '[' && symbol == ']')
				{
					//brackets are not balanced and print the line error is on
					isBalanced = false;
					cout << "Error occurred on line " << linePos << endl;
				}

				//if closing bracket does not correspond with opening bracket
				else if (checkBrace.top() != '{' && symbol == '}')
				{
					//brackets are not balanced and print the line error is on
					isBalanced = false;
					cout << "Error occurred on line " << linePos << endl;
				}
			}
		}

		//increment line position and read next line
		linePos++;
		getline(myIn, line);
	}

	//if stack is not empty, print unbalanced braces
	if (!checkBrace.empty())
		cout << "Error: unbalanced number of braces. \n";

	//is balanced returns true, then print that braces are balanced
	else if (isBalanced)
		cout << "the braces are balanced. \n";

	return 0;
}
