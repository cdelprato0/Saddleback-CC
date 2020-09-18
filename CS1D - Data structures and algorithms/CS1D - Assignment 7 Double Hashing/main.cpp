/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #7:Double Hashing
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/

/************************************************************************************
 * Assignment #7 - Double Hashing
 * ------------------------------
 *	This program will be using the double hashing algorithm. The first hash function
 *	is h(k) = k %mod 31 and the second hash function is h’(k) = 17 - k %mod 17.
 *	This program will read in a bunch of different keys and different city names
 *	and will perform the double hashing algorithm. It will add all of the nodes
 *	to the hash table and will also be deleting some keys as it adds members.
 *	Once it has added and deleted all of the members, it will then output to the
 *	console the whole hash table.
 *
 ************************************************************************************/
#include <map>
#include <string>
#include <iostream>
#include "Hashing.h"
using namespace std;


int main()
{
//OUTPUT - Will output the header and a description of the output
cout << "**************************************************************************\n"
		"* PROGRAMMED BY : Chaz Del Prato                                         *\n"
		"* ASSIGNMENT #7 : Double Hashing                                         *\n"
		"* CLASS         : CS1D                                                   *\n"
		"* SECTION       : MW 3:00p                                               *\n"
		"--------------------------------------------------------------------------\n"
		"* Description   :                                                        *\n"
		"*  This program will be able to read in a whole bunch of unique keys and *\n"
		"*  string values of cities and perform a double hashing algorithm. The   *\n"
		"*  program will first assign all the nodes a key and value and then will *\n"
		"*  initialize the hash table. All the member will be added to the hash   *\n"
		"*  table while a couple will be deleted in the process. Once those       *\n"
		"*  operations are done, it will output the entire hash table. If the spot*\n"
		"*  has {Delete} then that means that spot on the hash table has been     *\n"
		"*  deleted. If the spot has a value of zero and just {} then it was never*\n"
		"*  assigned a double hash value. The hash table is 31 spots. I used an   *\n"
		"*  ARRAY for my data structure. When the same key value is entered, the  *\n"
		"*  value at that key will be changed.                                    *\n"
		"**************************************************************************\n\n";

	//Loads in all the data
	Node empty = Node(0, "{}");
	Node city1 = Node(18, "Laguna Niguel");
	Node city2 = Node(41, "Mission Viejo");
	Node city3 = Node(22, "San Clemente");
	Node city4 = Node(44, "Irvine");
	Node city5 = Node(58, "Lake Forest");
	Node city6 = Node(32, "San Diego");
	Node city7 = Node(49, "Anaheim");
	Node city8 = Node(31, "Los Angeles");
	Node city9 = Node(17, "Orange");
	Node city10 = Node(72, "Palms Springs");
	Node city11 = Node(41, "Riverside");
	Node city12 = Node(19, "Brea");
	Node city13 = Node(60, "Santa Ana");
	Node city14 = Node(35, "Tustin");
	Node city15 = Node(103, "Oceanside");
	Node city16 = Node(11, "La Jolla");
	Node city17 = Node(18, "Del Mar");
	Node city18 = Node(22, "Aliso Viejo");
	Node city19 = Node(49, "Laguna Beach");
	Node city20 = Node(42, "Vista");
	Node city21 = Node(49, "San Diego");
	Node city22 = Node(99, "San Juan");
	Node city23 = Node(29, "Dana Point");
	Node city24 = Node(88, "El Segundo");
	Node city25 = Node(41, "San Clemente");
	Node city26 = Node(62, "Laguna Hills");

	//Initializes the hash table
	Hashing table = (empty);

	//adds to the hash table
	table.AddToHash(city1);
	table.AddToHash(city2);
	table.AddToHash(city3);
	table.AddToHash(city4);

	//deletes from the has table
	table.DeleteFromHash(41);

	//adds to the hash table
	table.AddToHash(city5);
	table.AddToHash(city6);
	table.AddToHash(city7);

	//deletes from the has table
	table.DeleteFromHash(58);

	//adds to the hash table
	table.AddToHash(city8);
	table.AddToHash(city9);
	table.AddToHash(city10);
	table.AddToHash(city11);

	//deletes from the has table
	table.DeleteFromHash(73);

	//adds to the hash table
	table.AddToHash(city12);
	table.AddToHash(city13);
	table.AddToHash(city14);
	table.AddToHash(city15);
	table.AddToHash(city16);
	table.AddToHash(city17);
	table.AddToHash(city18);
	table.AddToHash(city19);

	//adds to the hash table
	table.DeleteFromHash(41);
	table.AddToHash(city20);
	table.AddToHash(city21);
	table.AddToHash(city22);
	table.AddToHash(city23);
	table.AddToHash(city24);
	table.AddToHash(city25);
	table.AddToHash(city26);

	//prints out the hash table
	table.Print();

	return 0;
}
