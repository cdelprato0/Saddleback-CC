/************************************************************************************
 * AUTHOR	     :Chaz Del Prato
 * STUDENT ID    :382108
 * Assignment #13:Pattern Matching
 * CLASS	     :CS1D
 * SECTION	     :M/W 3:00 PM
 ************************************************************************************/
#ifndef KNUTHMORRISPRATT_H_
#define KNUTHMORRISPRATT_H_

#include "header.h"

class KnuthMorrisPratt {
public:
	KnuthMorrisPratt();
	virtual ~KnuthMorrisPratt();

	void preKMP(string pattern, int f[]);
	bool KMP(string pattern, string target);

	int getCount() const;

private:
	int count;

};

#endif /* KNUTHMORRISPRATT_H_ */
