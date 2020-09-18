/*******************************************************************************
 * AUTHOR	     : Chaz Del Prato
 * STUDENT ID    : 382108
 * Assignment #13: Design Patterns
 * CLASS	     : CS1C
 * SECTION	     : M/W 2:00 PM
 *******************************************************************************/

#include <iostream>
#include <cstring>
#include "PrintQueueSingleton.h"
using namespace std;

int main(){

	try{
		cout << "****Singleton Pattern****\n\n";

		PrintQueueSingleton::instance()->AddJob("First Job");
		PrintQueueSingleton::instance()->AddJob("Second Job");
		PrintQueueSingleton::instance()->AddJob("Third Job");
		PrintQueueSingleton::instance()->AddJob("Fourth Job");

		PrintQueueSingleton::instance()->Display();


		PrintQueueSingleton::instance()->CancelJob();
		PrintQueueSingleton::instance()->Display();

		PrintQueueSingleton::instance()->CancelJob();
		PrintQueueSingleton::instance()->Display();

		PrintQueueSingleton::instance()->CancelJob();
		PrintQueueSingleton::instance()->Display();

		PrintQueueSingleton::instance()->CancelJob();
		PrintQueueSingleton::instance()->Display();

		PrintQueueSingleton::instance()->CancelJob();
		PrintQueueSingleton::instance()->Display();
	}
	catch(Exception_isEmpty & error){
		cout << "YOU can NOT remove from an EMPTY list!\n\n";
	}


	return 0;
}
