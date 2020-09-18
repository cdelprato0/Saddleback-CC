/************************************************************************************
 * AUTHOR	     :Chaz Del Prato
 * STUDENT ID    :382108
 * Assignment #13:Pattern Matching
 * CLASS	     :CS1D
 * SECTION	     :M/W 3:00 PM
 ************************************************************************************/
#ifndef BOYERMOORE_H_
#define BOYERMOORE_H_

#include "header.h"

class BoyerMoore {
public:
	BoyerMoore();
	virtual ~BoyerMoore();

	int max(int a, int b);
	void badCharHeuristic(char *str, int size, int badchar[NO_OF_CHARS]);
	void search(char *txt, char *pat);
};

#endif /* BOYERMOORE_H_ */
