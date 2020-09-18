/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #3:Queues - Deques
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/
#ifndef DEQUE_H_
#define DEQUE_H_

#include <iostream>
#include <string>
using namespace std;

class Deque {

public:


	Deque();
	virtual ~Deque();
	//SETTERS
	void InsertHead(string nameString);
	void InsertTail(string nameString);
	void ClearList();
	string RemoveHead();
	string RemoveTail();


	//GETTERS
	int Size()const;
	bool IsEmpty()const;
	void Display()const;
	string PeekHead() const;
	string PeekTail() const;

private:
	//Stores the elements into the list and saves them in this struct
	struct Node
	{
		string name;
		Node *next;
	};

	Node *head; //holds the head of the linked list
	Node *tail; //Holds the tail of the linked list
	int size;	//Holds the soze of the linked List

};

#endif /* DEQUE_H_ */
