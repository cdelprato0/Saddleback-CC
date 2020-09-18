/************************************************************************************
 * AUTHOR	     :Chaz Del Prato
 * STUDENT ID    :382108
 * Assignment #13:Pattern Matching
 * CLASS	     :CS1D
 * SECTION	     :M/W 3:00 PM
 ************************************************************************************/

/************************************************************************************
 * Assignment #13
 * --------------
 * 	This program will be determining the number of comparisons needed to match a
 * 	specific pattern using three different algorithms. There is a given pattern and
 * 	a given text. The first algorithm is the Brute Force algorithm. The next is the
 * 	Boyer-Moore algorithm that has a last c function attached. The last is the
 * 	Knuth-Morris-Pratt algorithm that has a failure function attached. I will be
 * 	outputing each algorithm in that order.
 ************************************************************************************/

#include "header.h"
#include "BruteForce.h"
#include "BoyerMoore.h"
#include "KnuthMorrisPratt.h"

int main(){
//OUTPUT - Will output the header and a description of the output
cout << "*************************************************************************\n"
		"* PROGRAMMED BY  : Chaz Del Prato                                       *\n"
		"* ASSIGNMENT #13 : Pattern Matching                                     *\n"
		"* CLASS          : CS1D                                                 *\n"
		"* SECTION        : MW 3:00p                                             *\n"
		"-------------------------------------------------------------------------\n"
		"* Description   :                                                       *\n"
		"*  This program will be able to take a given text and pattern and will  *\n"
		"*  use three different pattern matching algorithms to determine the     *\n"
		"*  number of comparisons needed to match the pattern. The first         *\n"
		"*  algorithm is the Brute Force (BF) algorithm that takes the most      *\n"
		"*  number of comparisons. The next is the Boyer-Moore(BM) algorithm that*\n"
		"*  appears to be the least amount of comparisons. It will also display  *\n"
		"*  last(c) function of BM. The last algorithm is the Knuth-Morris-Pratt *\n"
		"*  algorithm will display the failure function of KMP. In each test the *\n"
		"*  the program will output the text and pattern for each comparison. At *\n"
		"*  the end of each algorithm it will output the number of comparisons.  *\n"
		"*************************************************************************\n\n";

	BruteForce bf;
	BoyerMoore bm;
	KnuthMorrisPratt kmp;

	string text = "aaabcaadaabaaa";
	string pattern = "aabaaa";
	char txtt[] = "aaabcaadaabaaa";
	char patt[] = "aabaaa";


	cout << "********************************\n"
			"* BRUTE FORCE PATTERN MATCHING *\n"
			"********************************\n";
	bf.search(pattern, text);
	cout << bf.getCount() << " Comparisons\n\n";


	cout << "********************************\n"
			"* BOYER-MOORE PATTERN MATCHING *\n"
			"********************************\n\n";
	cout << "The last c of the Boyer-Moore pattern matching is: \n"
			"------------------------------------------\n"
			"    c   |   a   |   b   |   c   |    d   |\n"
			"-----------------------------------------|\n"
			" Last(c)|   5   |   2   |  -1   |   -1   |\n"
			"------------------------------------------\n\n";
	bm.search(txtt, patt);


	cout << "***************************************\n"
			"* KNUTH-MORRIS-PRATT PATTERN MATCHING *\n"
			"***************************************\n\n";
	cout << "The failure function of the KMP pattern matching is: \n"
			"	F(0) = 0 (a)\n"
			"	F(1) = 1 (aa)\n"
			"	F(2) = 0 (aab)\n"
			"	F(3) = 1 (aaba)\n"
			"	F(4) = 2 (aabaa)\n"
			"	F(5) = 2 (aabaaa)\n\n";
	if (kmp.KMP(pattern, text)) {
		cout<<"\n'"<<pattern<<"' found in string '"<<text<<"'"<<endl;
		cout << kmp.getCount() << " Comparisons" << endl;
	}
	else {
		cout<<"'"<<pattern<<"' not found in string '"<<text<<"'"<<endl;
	}

	return 0;
}
