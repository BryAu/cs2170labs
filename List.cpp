//************************** Open Lab Assignment #5****************************

// FILE: ola5.cc

// AUTHOR: Bryce Ault

//*****************************************************************************/

#include "List.h"
#include <cstdlib>
#include <iostream>
using namespace std;

typedef int ListItemType;

List::List()
{
	head = NULL;	//initialize to NULL
}

bool List::isEmpty() const
{
	return (head == NULL);	//returns true or false
}

void List::insertFront(ListItemType newItem)
{
	ListNode *newNode;		
	newNode = new ListNode;		//create new node
	newNode->item = newItem;		//to store data in
	
	if (isEmpty())	//if list is empty
		head = newNode;		//head and newNode point to same node
	else
	{
		newNode->next = head;
		head = newNode;	//point head to new node
	}
}

void List::insertBack(ListItemType newItem)
{
	ListNode *newNode;
	newNode = new ListNode;	//create new node
	newNode->item = newItem;	//to store data in

	ListNode *q;	//variable for traversing list
	q = head;

	//traverse
	while (q->next != NULL)
	{
		q = q->next;	//until last item in list is found
	}
	q->next = newNode;		//point last item in list to new node
	newNode->next = NULL;		//new node next is NULL
	
}

void List::insertOrdered(ListItemType newItem)
{
	ListNode *newNode;
	newNode = new ListNode;	//create new node
	newNode->item = newItem;	//to store data in

	ListNode *p, *q;	//variables for traversing list
	p = head;
	q = p;

	//if list is empty, make head point to the new node
	if (isEmpty())	
		head = newNode;

	//if new item is smaller than the 1st element
	else if (newItem < head->item)
	{
		newNode->next = head;		//insert in the front
		head = newNode;
	}
	
	//if there is 1 node in the list
	else if (p->next == NULL)		
	{
		//insert after the first element
		newNode->next = p->next;
		p->next = newNode;		
	}
	else
	{
		//traverse until p's item is greater than newNode's item
		while (p->item <= newItem && p->next != NULL)
		{
			q = p;
			p = p->next;
		}

		//if we traversed until the last node
		if (p->next == NULL && p->item < newItem)
		{
			//make the new node the last node
			newNode->next = NULL;
			p->next = newNode;
		}

		//if not traversed until the last node
		else
		{
			//insert after q and before p
			newNode->next = q->next;
			q->next = newNode;
		}
	}
}

void List::removeFront(ListItemType& dataItem)
{
	head = head->next;
}

void List::removeBack(ListItemType& dataItem)
{
	ListNode *newNode;	//variable for traverising list
	newNode = head;

	//traverse until 2nd to last node in list
	while (newNode->next->next != NULL)
	{
		newNode = newNode->next;	
	}

	//nullify newNode pointer
	newNode->next = NULL;
}

void List::printList()
{
	ListNode *p;	//variable for traverising list
	p = head;

	//traverse	until the end is found
	while (p != NULL)
	{
		cout << p->item << " ";	//print node contents
		p = p->next;	
	}
}
