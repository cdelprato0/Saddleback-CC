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

class Stack : private List //Stack methods (retType Stack::StackMethodName() {})
						   //have access to all public and protected
						   //data members & methods of list

						   //Stack objects (Stack s;  s.methodName()) only
						   //have access to the public data
						   //members & methods of Stack
{
public:
	Stack();
	virtual ~Stack();

	//SETTERS
	void Push(Student*);
	Student* Pop();
	void ClearStack();

	//GETTERS
	Student* Peek()const;
	int Size()const;
	bool IsEmpty()const;
	void Display()const;
	virtual void VDisplay()const;

private:
	//List stackL;

};

#endif /* STACK_H_ */
