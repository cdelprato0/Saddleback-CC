/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #8:Skip Lists
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/

/************************************************************************************
 * Assignment #8 - Skip Lists
 * ------------------------------
 *	This program will be able to create a skip list that is used for effiecnety
 *	with traversing a list. The program will show the insert, erase, find, print,
 *	and size capabilities of this skip list. After inserting all the nodes into the
 *	skip list, the program will out the nodes with their keys, values and levels.
 *	Then the program will erase a couple of  nodes from the skip list and will output
 *	the corresponding skip list. After that it will test the find function and search
 *	for a node that exists and a node that does not exist. At the end of the program
 *	it will check the size of the list and output.
 *	Random Number generator:
 *		WHILE a random number DIVIDED by the max random number is LESS than the 50/50
 *		Probability AND that the absolute value of a level is LESS than the max level
 *
 ************************************************************************************/
#include "SkipList.h"

int main()
{
//OUTPUT - Will output the header and a description of the output
cout << "*************************************************************************\n"
		"* PROGRAMMED BY : Chaz Del Prato                                        *\n"
		"* ASSIGNMENT #8 : Skip Lists                                            *\n"
		"* CLASS         : CS1D                                                  *\n"
		"* SECTION       : MW 3:00p                                              *\n"
		"-------------------------------------------------------------------------\n"
		"* Description   :                                                       *\n"
		"*  This program will insert all the keys and names of cities into the   *\n"
		"*  Skip List. Once the items have been added, then it will output the   *\n"
		"*  Skip list with the key, value and the level the nodes are on. Then it*\n"
		"*  will demonstrate erasing nodes from the skip list. It will call the  *\n"
		"*  erase function then it will output the skip list after the deletion. *\n"
		"*  After that it will display the find function. The find function will *\n"
		"*  determine if the node exists in the skip list and will output so. At *\n"
		"*  the end it will output the current size of the skip list. A          *\n"
		"*  dictionary was used to hold the values of the skip list.             *\n"
		"*************************************************************************\n\n";
	SkipList list;
	Skip_Node* search = NULL;

	//Checking the INSERT function
	cout << "*****   INSERTING   *****\n\n";
	list.insert(18, "Laguna Niguel");
	list.insert(41, "Mission Viejo");
	list.insert(22, "San Clemente");
	list.insert(44, "Irvine");
	list.insert(58, "Lake Forest");
	list.insert(32, "San Diego");
	list.insert(49, "Anaheim");
	list.insert(31, "Los Angeles");
	list.insert(17, "Orange");
	list.insert(72, "Palms Springs");
	list.insert(41, "Riverside");
	list.insert(19, "Brea");
	list.insert(60, "Santa Ana");
	list.insert(35, "Tustin");
	list.insert(103, "Oceanside");
	list.insert(11, "La Jolla");
	list.insert(18, "Del Mar");
	list.insert(22, "Aliso Viejo");
	list.insert(49, "Laguna Beach");
	list.insert(42, "Vista");
	list.insert(49, "San Diego");
	list.insert(99, "San Juan");
	list.insert(29, "Dana Point");
	list.insert(88, "El Segundo");
	list.insert(41, "San Clemente");
	list.insert(62, "Laguna Hills");

	//Checking the PRINT function
	list.print();

	//Checking the ERASE function
	cout << "\n\n*****   REMOVING KEY 41   *****\n";
	list.erase(41);
	list.print();

	cout << "\n\n*****   REMOVING KEY 58   *****\n";
	list.erase(58);
	list.print();

	cout << "\n\n*****   REMOVING KEY 73   *****\n";
	list.erase(73);
	list.print();

	cout << "\n\n*****   REMOVING KEY 41   *****\n";
	list.erase(41);
	list.print();


	//Checking the FIND function
	cout << "\n\n*****   FINDING KEY 100   *****\n";
    search = list.find(100);
    if(search){
    	cout <<"*****   Node found!   *****\nValue: "<< search->value <<'\n';
    }
    else{
    	cout <<"*****   Node NOT found!   *****\n";
    }

	cout << "\n\n*****   FINDING KEY 99   *****\n";
    search = list.find(99);
    if(search){
    	cout <<"*****   Node found!   *****\nValue: "<< search->value <<'\n';
    }
    else{
    	cout <<"*****   Node NOT found!   *****\n";
    }

    //Checking SIZE function
    cout << "\n\n*****   THE SIZE IS   *****\n"
    	 << list.size();

	return 0;
}
