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


void Stack::Push(Person p)
{
	stackL.InsertHead(p);
}


Person Stack::Pop()
{
	return stackL.RemoveHead();
}


void Stack::ClearStack()
{
	stackL.ClearList();
}

//GETTERS
Person Stack::Peek()const
{
	return stackL.PeekHead();
}


int Stack::Size()const
{
	return stackL.Size();
}


bool Stack::IsEmpty()const
{
	return stackL.IsEmpty();
}


void Stack::Display()const
{
	stackL.Display();
}
