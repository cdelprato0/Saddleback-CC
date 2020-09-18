/*
 * List.h
 *
 *  Created on: Apr 13, 2015
 *      Author: cdelprato0
 */

#ifndef LIST_H_
#define LIST_H_

#include "Header.h"
#include "Person.h"
#include "Student.h"

class List {
public:
	List();
	virtual ~List();

	//SETTERS
	void InsertHead(Student*);
	void InsertTail(Student*);
	void ClearList();
	Student* RemoveHead();
	Student* RemoveTail();


	//GETTERS
	Student* SearchName(string)const;
	int Size()const;
	bool IsEmpty()const;
	void Display()const;
	virtual void VDisplay()const;
	Student* PeekHead() const;
	Student* PeekTail() const;

private:
	struct Node
	{
		Student *payLoad; //Only has access to Student(and base : Person), methods/attributes
		Node *next;
	};

	Node *head;
	Node *tail;
	int size;
};

#endif /* LIST_H_ */
