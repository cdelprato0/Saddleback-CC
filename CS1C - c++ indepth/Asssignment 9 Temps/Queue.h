/*
 * Queue.h
 *
 *  Created on: Apr 19, 2016
 *      Author: Chaz
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <string>
using namespace std;

template <class Type>
class Queue {

public:
	Queue();
	virtual ~Queue();

	//MUTAUTORS
	void   Enqueue(Type p);
	Type* Dequeue();
	void   ClearQueue();

	//ACESSORS
	int  Size()     const;
	Type Front()    const;
	bool IsEmpty()  const;
	bool IsFull()   const;
	void Display()  const;
	virtual void VDisplay() const;

private:

	struct Node{
		Type payload;
		Node  *next;
	};

	Node *head;
	Node *tail;
	int   size;
};

template <class Type>
Queue<Type>::Queue() {
	// TODO Auto-generated constructor stub
	head = tail = NULL;
	size = 0;
}

template <class Type>
Queue<Type>::~Queue() {
	// TODO Auto-generated destructor stub
	ClearQueue();
	head = tail = NULL;
}

template <class Type>
void Queue<Type>::Enqueue(Type p)
{
//	List<Type>::InsertTail(p);
	Node *newNode;

	newNode = new Node;

	   // INITIALIZE - the name, gender, and age into one node from the struct
	if(newNode != NULL)
	{
		cout << "Adding " << p << " to the queue!\n";
		newNode->payload = p;

		// PROC - links the node to the list
		newNode -> next = tail;
		tail = newNode;
	}


	if(size == 0)
	{
		head = newNode;
	}

	//size is incremented
	size++;
}

template <class Type>
Type* Queue<Type>::Dequeue()
{
	Node *nodeRemove;

	nodeRemove = new Node;

	nodeRemove = head;

	if(!IsEmpty())//non-empty list
	{
		head = nodeRemove->next; //move head to text node

		delete nodeRemove;
		nodeRemove = NULL;

		size--;
	}

	return head;

}

template <class Type>
void   Queue<Type>::ClearQueue()
{
	if(head != NULL)
	{

		while( head!=NULL )
		{
			// PROC - since a node was removed from queue, the head must
			//		  be set to the next node in queue
			head = head->next;
			size--;
		}

		// deallocates the node that was used to remove the node
		delete head;
		head = NULL; // set back to null for safety
	}
	size = 0;
}

template <class Type>
int  Queue<Type>::Size() const
{
	return size;
}

template <class Type>
Type Queue<Type>::Front() const
{
	Type frontOfList;

	if(!IsEmpty())
	{
		frontOfList = head->payload;
	}

	return frontOfList;
}

template <class Type>
bool Queue<Type>::IsEmpty()  const
{
	return ( size == 0 );
}

template <class Type>
bool Queue<Type>::IsFull()   const
{
	return( size == 25 );
}

#endif /* QUEUE_H_ */
