//************************** Open Lab Assignment #5****************************

// AUTHOR: Bryce Ault

// DESCRIPTION: List pointer operations

// INPUT: integer values from standard input

// OUTPUT: prints list of elements

//*****************************************************************************/



#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List myList, otherList;   //list objects to test List implementation
	int choice;    //user choice
	int value;     //value to add or value in the deleted node

				   // ask user to choose operations on list  
	do
	{
		//display options
		cout << "\n"
			<< " 1: add a new node at the front of myList \n"
			<< " 2: add a new node at the end of myList \n"
			<< " 3: delete the first node  of myList \n"
			<< " 4: delete last node  of myList \n"
			<< " 5: display myList \n"
			<< " 6: add a new node in ordered list otherList \n"
			<< " 7: display otherList \n"
			<< " 8: quit \n\n";
		cout << "choose your option from the above: ";
		cin >> choice;

		switch (choice)
		{

		case 1:
			//add a new node at the front of myList
			cout << "item value? ";
			cin >> value;

			myList.insertFront(value);
			break;
		case 2:
			//add a new node at the end of myList
			cout << "item value? ";
			cin >> value;

			myList.insertBack(value);
			break;
		case 3:
			//delete the first node  of myList
			myList.removeFront(value);
			cout << value << " is removed from myList\n";
			break;
		case 4:
			//delete last node  of myList
			myList.removeBack(value);
			cout << value << " is removed from myList\n";
			break;
		case 5:
			//display myList
			myList.printList();
			break;
		case 6:
			//add a new node in ascending order to otherList
			cout << "item value? ";
			cin >> value;
			otherList.insertOrdered(value);

			break;
		case 7:
			//display otherList
			otherList.printList();
			break;
		case 8:

			break;

		} //end of switch


	} while (choice <8);


	return 0;
}  // end main

