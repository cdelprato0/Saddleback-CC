/************************************************************************************
 * AUTHOR	    :Chaz Del Prato & Eric Le
 * LAB # 2      :Recursion
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <locale>
#include <algorithm>
using namespace std;

/*******************************************************************************
 * CS1D - Lab Two: Recursion
 * _____________________________________________________________________________
 * This program will be able to take in an array of strings and will be able to
 * determine if the strings are palindromes or not. This program uses recursion to
 * decipher the strings in order to find if they have the same spelling forwards
 * and backwards. The input that is entered will be check and cleared of any white
 * spaces, capital letters, and special characters. The program will first have the
 * input of the strings and will clean them up and remove the unnecessary characters
 * so that it will be looking at just the letters. Then the palindrome function will
 * be called and determine if the string in a palindrome. The program will output
 * if all the strings are palindromes or not.
 *******************************************************************************/

bool isPalindrome(string input);
void lowerCase( string& newStr);

int main(){

	//OUTPUT - Will output the header and a description of the output
	cout << "************************************************************************\n"
		    "* PROGRAMMED BY : Eric Le & Chaz Del Prato                             *\n"
			"* LAB # 2       : Recursion                                            *\n"
	        "* CLASS         : CS1D                                                 *\n"
	        "* SECTION       : MW 3:00p                                             *\n"
			"------------------------------------------------------------------------\n"
	        "* Description   :                                                      *\n"
	        "*  The Output of this function will show that the strings that         *\n"
	        "*  have been enter are a palindrome or not. It will output the         *\n"
	        "*  untouched word in quotes and will go through the process of         *\n"
	        "*  determining if the string is a palindrome or is not a plaindrome.   *\n";
	cout << "************************************************************************\n\n";

	//Input to test if it is a palindrome
	string input[] = { "radar", "CS1D", "Racecar", "Saddleback", "dad", "mom",
					 "A man a plan a canal Panama", "The rain in Spain",
					 "No lemon, no melon", "Was it a cat I saw?" };

	//PROCESSING - This for loop will run through the test data and determine if
	//				the data is a palindrome or not
	for( int index = 0; index < 10 ; index ++ )
	{

		//Outputs the raw word to the console in quotes
		cout << "\"" << input[index] << "\" is ";

		//Calls the lowercase function that sets all the letters of the word to
		//lowercase letters
		lowerCase(input[index]);

		//These will remove any of the white spaces and special characters out of
		//the phrase
		input[index].erase(remove( input[index].begin(), input[index].end(),
									' ' ), input[index].end()) ;

		input[index].erase(remove( input[index].begin(), input[index].end(),
									'?' ), input[index].end()) ;

		input[index].erase(remove( input[index].begin(), input[index].end(),
									',' ), input[index].end()) ;


		//This IF statement will call the isParindrome function and will determine
		//if the phrase entered is a palindrome and will return the result
		if(isPalindrome(input[index]))
		{
			//If it is a palindrome then it will output
			cout << "a palindrome!" << endl;
		}
		else
		{
			//If  it is not a plaindrome then it will output
			cout << "not a palindrome!" << endl;
		}
	}
	return 0;
}

//This function will test data to see if it is a palindrome (the letters are the same
//in both forward and reverse order)
bool isPalindrome(string input){

	//Sets the first and last letters of the phrase equal to variables
	string first = input.substr(0,1);
	string last = input.substr(input.length() - 1, 1);

	//Checks to see if the first letter is the same as the last letter
	if(first == last){

		//If the letters are the same then it will remove the letters and move to
		//the next set
		input = input.substr( (0+1), (input.length() - 2) );

		//If the input is at the last letter then it will return that it is a
		//palindrome
		if(input.length() <= 1){
			return true;
		}

		//Will perform RECURSION if the letters are the same and will go until
		//they are not or the phrase ends
		return isPalindrome(input);
	}
	//returns false if the letters are not the same
	else{
		return false;
	}
}

//This function sets the string to all lower case letters
void lowerCase( string& temp ){

	//This for loop runs through the entire string and converts each character to
	//lower case
	for( unsigned int index = 0; index < temp.length(); index++ )
	{
		temp[index] = tolower(temp[index]);
	}//End FOR LOOP

}//End lowerCase FUNCTION
