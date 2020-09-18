/*************************************************************************
 * AUTHOR     : Myrmidon & BBC
 * LAB #10    : Implementing a Queue
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 3/18/15
 ************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <ios>
using namespace std;

enum Menu{
		   EXIT,
		   ENQUEUE,
		   DEQUEUE,
		   ISEMPTY,
		   FRONT,
		   SIZE,
		   CLEARQUEUE,
		 };

struct PersonNode
{
	string 		name;		// IN   - the name to be entered on stack
	char   		gender;		// IN   - the gender to be entered on stack
	int	   		age;		// IN   - the age to be entered on stack
	PersonNode  *next;		// PROC - the pointer connects nodes on stack

};


void PrintHeader(string codeName,   // IN - the programmer's code name
                 string asName,     // IN - the assignment name
                 string classF,     // IN - the programmer's class
                 char   asType,     // IN - the assignment type
                                    //      (LAB or ASSIGNMENT)
                 int    asNum);      // IN - the assignment number

void DisplayMenu();

void GetCommand(int &commandF);

PersonNode* Enqueue(PersonNode *head);

PersonNode* Dequeue(PersonNode *head);

void IsEmpty(PersonNode *head);

void Front(PersonNode *head);

int Size(PersonNode* head);

//void ClearQueue(PersonNode *head);

#endif /* HEADER_H_ */
