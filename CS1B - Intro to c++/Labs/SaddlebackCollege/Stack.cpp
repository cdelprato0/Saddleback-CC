/*
 * Stack.cpp
 *
 *  Created on: Apr 13, 2015
 *      Author: cdelprato0
 */

#include "Stack.h"

Stack::Stack()
{
	//stackL is auto-constructed through its constructor List::List()
}

Stack::~Stack()
{
	//stackL is auto-de-structed through its de-structor List::~List()
}


void Stack::Push(Student *p)
{
	InsertHead(p);
}


Student* Stack::Pop()
{
	return RemoveHead();
}


void Stack::ClearStack()
{
	ClearList();
}

//GETTERS
Student* Stack::Peek()const
{
	return PeekHead();
}


int Stack::Size()const
{
	return List::Size();
}


bool Stack::IsEmpty()const
{
	return IsEmpty();
}


void Stack::Display()const
{
	List::Display();
}

void Stack::VDisplay()const
{
	List::VDisplay();
}
