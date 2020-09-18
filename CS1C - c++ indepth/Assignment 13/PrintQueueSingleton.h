/*******************************************************************************
 * AUTHOR	     : Chaz Del Prato
 * STUDENT ID    : 382108
 * Assignment #13: Design Patterns
 * CLASS	     : CS1C
 * SECTION	     : M/W 2:00 PM
 *******************************************************************************/
#include <string>
#include <iostream>
using namespace std;

#ifndef PRINTQUEUESINGLETON_H_
#define PRINTQUEUESINGLETON_H_

class Exception_isEmpty{ };

class PrintQueueSingleton {
public:
	static PrintQueueSingleton *instance();

	int AddJob(string sTexttoPrint);
	void CancelJob();
	void Display();

protected:
	PrintQueueSingleton();
	virtual ~PrintQueueSingleton();

	int     arraySize;
	int     jobNumber;
	string* stringArray;

private:
	static PrintQueueSingleton *inst;
};

#endif /* PRINTQUEUESINGLETON_H_ */
