/*
 * Stack.h
 *
 *  Created on: Apr 13, 2015
 *      Author: cdelprato0
 */

#ifndef STACK_H_
#define STACK_H_

#include "Header.h"
#include "List.h"
using namespace std;

class Stack {
public:
	Stack();
	virtual ~Stack();

	//SETTERS
	void Push(Person);
	Person Pop();
	void ClearStack();

	//GETTERS
	Person Peek()const;
	int Size()const;
	bool IsEmpty()const;
	void Display()const;

private:
	List stackL;

};

#endif /* STACK_H_ */
