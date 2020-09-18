/*************************************************************************
 * AUTHOR     : Zeta & BBC
 * LAB #11    : Creating an Ordered List
 * CLASS      : CS1B
 * SECTION    : MW 8:30am-12:20p
 * DUE DATE   : 4/1/15
 ************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

/*******************************************************************
 * FUNCTION Header
 * _________________________________________________________________
 *
 * This function stores the pre-processor directives, Enum types,
 * Struct, and function prototypes that will allow the main program
 * to run without all of them to be included in each page.
 *******************************************************************/

//PRE PROCESSOR DIRECTIVES
#include <iomanip>
#include <iostream>
#include <string>
#include <limits>
#include <ios>
#include <fstream>
using namespace std;

//ENUM type Menu
enum Menu {
	EXIT,
	CREATELIST,
	DISPLAYLIST,
	ISEMPTY,
	SEARCHNAME,
	REMOVENODE,
	CLEARLIST
};

//STRUCT PersonNode
struct PersonNode{
	string name;      //IN & OUT - name
	char gender;      //IN & OUT - gender
	int age;          //IN & OUT - age
	PersonNode *next; //PROC     - Next point to the next node
};

//PrintHeader - This function will print the header to the console
//              All parameters will be passed by value into the function
void PrintHeader(string codeName,   // IN - the programmer's code name
                 string asName,     // IN - the assignment name
                 string classF,     // IN - the programmer's class
                 char   asType,     // IN - the assignment type
                                    //      (LAB or ASSIGNMENT)
                 int    asNum);     // IN - the assignment number

//DisplayMenu - This function Outputs the menu list
void DisplayMenu();

//GetCommand - This function will error check for a valid entry
void GetCommand(int &commandF); //OUT - the command entered by user
								//Pass by reference In & OUT of function

//CreateList - this function creates the list
void CreateList(PersonNode *&head, //PROC - Head points to the top of list
								   //Pass by reference IN & OUT of function
		        PersonNode *&tail);//PROC - tail points to the bottom of list
								   //Pass by reference IN & OUT of function

//DisplayList - This function Outputs the entire list.
void DisplayList(PersonNode *head);//PROC - Head points to the top of list
								   //Pass by value into the function

//IsEmpty - This function determines if the list is empty.
void IsEmpty(PersonNode *head); //PROC - Head points to the top of list
								//Pass by value into the function

//SearchName - This function searches for a name in the linked list
void SearchName(PersonNode* head);//PROC - Head points to the top of list
								  //Pass by value into the function

//RemovingNode - This function removes a node from the list
void RemovingNode(PersonNode *&head, //PROC - Head points to the top of list
									 //Pass by reference IN & OUT of function
		          PersonNode *&tail);//PROC - Tail points to the bottom of list
									 //Pass by reference IN & OUT of function

//ClearList - This function will clear the entire list
PersonNode* ClearList(PersonNode *&head);//PROC - Head points to the top of list
										 //Pass by reference IN & OUT of the function


#endif /* HEADER_H_ */
