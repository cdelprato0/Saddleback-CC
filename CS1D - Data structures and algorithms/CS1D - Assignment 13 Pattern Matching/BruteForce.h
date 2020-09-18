/************************************************************************************
 * AUTHOR	     :Chaz Del Prato
 * STUDENT ID    :382108
 * Assignment #13:Pattern Matching
 * CLASS	     :CS1D
 * SECTION	     :M/W 3:00 PM
 ************************************************************************************/
#ifndef BRUTEFORCE_H_
#define BRUTEFORCE_H_

#include "header.h"

class BruteForce {
public:
	BruteForce();
	virtual ~BruteForce();
	bool search(string, string);

	int getCount() const;

private:
	int count;
};

#endif /* BRUTEFORCE_H_ */
