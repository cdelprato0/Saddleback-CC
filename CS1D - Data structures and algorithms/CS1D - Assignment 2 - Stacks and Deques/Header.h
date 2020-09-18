/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #2:Stacks & Dequeue
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/
#include <iostream>
#include <string.h>
#include <stack>
#include <queue>
#include <stdio.h>
using namespace std;

#ifndef HEADER_H_
#define HEADER_H_

//Global Variables
const string stringArray[] = {"Tasha", "JoAnn", "Lucy", "Mark", "Cathy", "Jane"};
const double doubleArray[] = {48.4, 887.55, 88.88, 123.123, 8.455, 983.3, 1.2, 354.8};

//Stuct is used to create a linked list
struct List{
	string name;
	double number;
	char exp;
	List* next;
	List* prev;
};

void stlStack();

void singlyLinkedList();

void queueLinkedList();

void dequeLinkedList();

bool paraCheck();

#endif /* HEADER_H_ */
