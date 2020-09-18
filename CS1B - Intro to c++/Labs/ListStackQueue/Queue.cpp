/*
 * Queue.cpp
 *
 *  Created on: Apr 13, 2015
 *      Author: cdelprato0
 */

#include "Queue.h"

Queue::Queue()
{

}

Queue::~Queue()
{

}

//SETTERS
void Queue::Enqueue(Person p)
{
	queueL.InsertTail(p);
}

Person Queue::Dequeue()
{
	return queueL.RemoveHead();
}

void Queue::ClearQueue()
{
	queueL.ClearList();
}


//GETTERS
int Queue::Size()const
{
	return queueL.Size();
}

bool Queue::IsEmpty()const
{
	return queueL.IsEmpty();
}

void Queue::Display()const
{

	queueL.Display();
}
