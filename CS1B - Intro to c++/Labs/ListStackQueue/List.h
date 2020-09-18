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

class List {
public:
	List();
	virtual ~List();

	//SETTERS
	void InsertHead(Person);
	void InsertTail(Person);
	void ClearList();
	Person RemoveHead();
	Person RemoveTail();


	//GETTERS
	Person SearchName(string)const;
	int Size()const;
	bool IsEmpty()const;
	void Display()const;
	Person PeekHead() const;
	Person PeekTail() const;

private:
	struct Node
	{
		Person payLoad;
		Node *next;
	};

	Node *head;
	Node *tail;
	int size;
};

#endif /* LIST_H_ */
