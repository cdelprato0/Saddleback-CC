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
void Queue::Enqueue(Student *s)
{
	InsertTail(s);
}

Student* Queue::Dequeue()
{
	return RemoveHead();
}

void Queue::ClearQueue()
{
	ClearList();
}


//GETTERS
int Queue::Size()const
{
	return List::Size();
}

bool Queue::IsEmpty()const
{
	return IsEmpty();
}

void Queue::Display()const
{

	List::Display();
}

void Queue::VDisplay()const
{

	List::VDisplay();
}
