/*******************************************************************************
 * AUTHOR	     : Chaz Del Prato
 * STUDENT ID    : 382108
 * Assignment #13: Design Patterns
 * CLASS	     : CS1C
 * SECTION	     : M/W 2:00 PM
 *******************************************************************************/
#include "PrintQueueSingleton.h"

PrintQueueSingleton::PrintQueueSingleton() {
	arraySize   = 8;
	jobNumber = 0;
	stringArray  = new string[arraySize];

}

PrintQueueSingleton::~PrintQueueSingleton() {
	delete[] stringArray;
}

PrintQueueSingleton *PrintQueueSingleton::instance() {
	if(!inst)
		inst = new PrintQueueSingleton();

	return inst;
}

PrintQueueSingleton *PrintQueueSingleton::inst = 0;

//Adds a job to the stack
int PrintQueueSingleton::AddJob(string sTexttoPrint) {
	if( jobNumber == arraySize ) {
		cout << "Can not add to the list because it is FULL!!!\n";
	}//End IF
	else if(jobNumber == 0) {
		stringArray[0] = sTexttoPrint;
		jobNumber++;
	}//End ELSE IF
	else {
		stringArray[jobNumber] = sTexttoPrint;
		jobNumber++;
	}//End ELSE

	return jobNumber;
}

//Deletes a job off the list
void PrintQueueSingleton::CancelJob() {
	if( jobNumber == 0 ) {
		throw Exception_isEmpty();
	}//End IF
	else {

		for( int index = 0; index < arraySize; index++ ) {
			if( index < arraySize )
				stringArray[index] = stringArray[index+1];
			}
		jobNumber--;
	}//End ELSE
}

//Outputs the List
void PrintQueueSingleton::Display() {
	cout << "Outputting the Queue: ";

	for( int index = 0; index < arraySize; index++ ) {
		cout << stringArray[index];
		if ( stringArray[index] != "" )
			cout << ", ";
	}//End FOR

	cout << endl << endl;
}


