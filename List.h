// ********************************************************
// Header file List.h for the ADT list.
// Pointer-based implementation.
// *********************************************************

// Must define ListItemType before compilation
typedef int ListItemType;

class List
{
public:
	// constructors and destructor:
	List();                  // default constructor

							 // list operations:
	bool isEmpty() const;   //is list empty
	void insertFront(ListItemType newItem);  //insert a new node at the front

	void insertBack(ListItemType newItem);   //insert a new node at the back
	void insertOrdered(ListItemType newItem);  //insert a new node in ascending order

	void removeFront(ListItemType& dataItem);//remove a node from the front 
	void removeBack(ListItemType& dataItem); //remove a node from the end 

	void printList();  //print linked list in a form of   list ->10 ->5

private:
	struct ListNode // a node on the list
	{
		ListItemType item; // a data item on the list
		ListNode *next;    // pointer to next node
	}; // end struct

	ListNode *head; // pointer to linked list of items

}; // end class
   // End of header file.

