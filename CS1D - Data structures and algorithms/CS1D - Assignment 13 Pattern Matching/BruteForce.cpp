/************************************************************************************
 * AUTHOR	     :Chaz Del Prato
 * STUDENT ID    :382108
 * Assignment #13:Pattern Matching
 * CLASS	     :CS1D
 * SECTION	     :M/W 3:00 PM
 ************************************************************************************/
#include "BruteForce.h"

BruteForce::BruteForce() {
	count = 0;

}

BruteForce::~BruteForce() {

}

bool BruteForce::search(string pattern, string text)
{
    for (unsigned int i=0; i<= text.length()-pattern.length(); i++) {

        unsigned int j=0;
        while (j < pattern.length() && pattern.at(j) == text.at(i+j)) {
            j++;
            cout << "Comparing \"" << text << "\" with \"" << pattern << "\"\n";

            count++;

        }
        if (j == pattern.length()) {
        	cout << "\nPattern was found\n";
            return true;

        }
        cout << "Comparing \"" << text << "\" with \"" << pattern << "\"\n";
        count++;

    }
    return false;
}

int BruteForce::getCount() const {
	return count;
}
