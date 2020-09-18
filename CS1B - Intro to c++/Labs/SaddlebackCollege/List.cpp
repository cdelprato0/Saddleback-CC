/*
 * List.cpp
 *
 *  Created on: Apr 13, 2015
 *      Author: cdelprato0
 */

#include "List.h"

List::List()
{
	head = tail = NULL;
	size = 0;
}

List::~List()
{
	ClearList();
	head = tail = NULL;
}

void List::InsertHead(Student *s)
{
	Node *currentNode;

	//Constructing Node
	currentNode          = new Node;
	currentNode->payLoad = s;
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
void List::InsertTail(Student *s)
{
	Node *currentNode;

	//Constructing Node
	currentNode          = new Node;
	currentNode->payLoad = s;
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


void List::ClearList()
{
	while(!IsEmpty())
	{
		RemoveHead();
	}
	head = tail = NULL;

}


Student* List::RemoveHead()
{
	Student *personRemove;
	Node *remove = head;

	if(!IsEmpty()) //Non empty list
	{
		head = head->next; //Move head to next node

		personRemove = remove->payLoad;

		delete remove;
		remove = NULL;

		size--;
	}
	return personRemove;
}
Student* List::RemoveTail()
{
	Node *travNode = head;
	Student *personRemoved;

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
		personRemoved = tail->payLoad;

		travNode->next = NULL;//Disconnect list from old tail

		delete tail;//Delete node data from old tail

		tail = travNode;//Point tail to new end of list

		size--;
	}
	return personRemoved;
}


Student* List::SearchName(string name)const
{
	Student *p;
	//TODO
	return p;

}


int List::Size()const
{
	return size;
}


bool List::IsEmpty()const
{
	return (size == 0);
}


void List::Display()const
{
	Node *currentNode = head;

	cout << "DISPLAY \n"
		 << "------- \n";

	while(currentNode != NULL)
	{
		cout << currentNode->payLoad->Display() << endl;
		currentNode = currentNode->next;
	}
}

void List::VDisplay()const
{
	Node *currentNode = head;

	cout << "DISPLAY \n"
		 << "------- \n";

	while(currentNode != NULL)
	{
		cout << currentNode->payLoad->VDisplay() << endl; //POLYMORPHISM: calls the VDisplay()
														  //method of the instantiated object
		currentNode = currentNode->next;
	}
}

Student* List::PeekHead() const
{
	Student *headPayload;

	if(!IsEmpty())
	{
		headPayload = head->payLoad;

	}
	return headPayload;
}


Student* List::PeekTail() const
{
	Student *tailPayload;

	if(!IsEmpty())
	{
		tailPayload = tail->payLoad;

	}
	return tailPayload;
}
