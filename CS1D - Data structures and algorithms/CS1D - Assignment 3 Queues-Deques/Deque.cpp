/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #3:Queues - Deques
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/
#include "Deque.h"

//Constructor
Deque::Deque()
{
	head = tail = NULL;
	size = 0;
}

//Deconstructor
Deque::~Deque()
{
	ClearList();
	head = tail = NULL;
}

//Inserts the node to the head of the list, used for stacks
void Deque::InsertHead(string p)
{
	Node *currentNode;

	//Constructing Node
	currentNode          = new Node;
	currentNode->name = p;
	currentNode->next    = NULL;

	if(head == NULL) //Empty List
	{
		head = tail = currentNode;
	}
	else
	{
		currentNode->next = head;
		head     		  = currentNode;
	}

	size++;
}

//Inserts a node at the tail of a linked list  and is used for the queue
void Deque::InsertTail(string p)
{
	Node *currentNode;

	//Constructing Node
	currentNode          = new Node;
	currentNode->name = p;
	currentNode->next    = NULL;

	if(tail == NULL) //Empty List
	{
		head = tail = currentNode;
	}
	else
	{
		tail->next = currentNode;
		tail       = currentNode;
	}

	size++;
}

//Clears the entire list
void Deque::ClearList()
{
	while(!IsEmpty())
	{
		RemoveHead();
	}
	head = tail = NULL;

}

//Removes the head of the list and is used with queues
string Deque::RemoveHead()
{
	string personRemove;
	Node *remove = head;

	if(!IsEmpty()) //Non empty list
	{
		head = head->next; //Move head to next node

		personRemove = remove->name;

		delete remove;
		remove = NULL;

		size--;
	}
	return personRemove;
}

//Removes the tail of the linked list and is used for stacks
string Deque::RemoveTail()
{
	Node *travNode = head;
	string personRemoved;

	if(Size() == 1)//One node is the list
	{
		personRemoved = RemoveHead();
	}
	else if(Size() > 1)//More than one node in the list
	{
		//Find node previous to tail
		while(travNode->next != tail)
		{
			travNode = travNode->next;
		}

		//Node previous to tail is found
		personRemoved = tail->name;

		travNode->next = NULL;//Disconnect list from old tail

		delete tail;//Delete node data from old tail

		tail = travNode;//Point tail to new end of list

		size--;
	}
	return personRemoved;
}

//Returns the size of the linked list
int Deque::Size()const
{
	return size;
}

//Checks to see if the linked list is empty or not
bool Deque::IsEmpty()const
{
	return (size == 0);
}

//Displays the entire contents of the list
void Deque::Display()const
{
	Node *currentNode = head;

	cout << "\nDisplaying contents of the Queue \n"
		 << "-------------------------------- \n";

	while(currentNode != NULL)
	{
		cout << "\"" << currentNode->name << "\"\n";
		currentNode = currentNode->next;
	}
}

//Shows the element at the head of the list
string Deque::PeekHead() const
{
	string headPayload;

	if(!IsEmpty())
	{
		headPayload = head->name;

	}
	return headPayload;
}

//Shows the element at the tail of the linked list
string Deque::PeekTail() const
{
	string tailPayload;

	if(!IsEmpty())
	{
		tailPayload = tail->name;

	}
	return tailPayload;
}
