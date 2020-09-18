/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #2:Stacks & Dequeue
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:00 PM
 ************************************************************************************/
#include "Header.h"

void stlStack(){

	//Output to the console
	cout << "****************\n"
			"*    Part A    *\n"
	     << "*   STL Stack  *\n"
		 << "****************\n\n";

	stack<string> stringStack;  //Creates a stack of strings from the STL
	int currentSize = 0; //Keeps track of size of stack

	//PROCESSING - This is the push function, it was add a string to the stack and
	//				output so
	for( int index = 0; index < 6; index ++){

		//Calls the STL .push method to add the element to the stack
		stringStack.push(stringArray[index]);

		//Outputs to the console that the item is being added
		cout << "Adding: " << stringArray[index] << " to the STL Stack!\n";

		//Adds to the currentSize
		currentSize = stringStack.size();

	}//End FOR LOOP

	//Outputs the stack backwards for top to bottom
	cout << "\nThe items on the stack are: (From top to bottom)\n";
	for( int index = currentSize -1; index >= 0; index --){

		cout << stringArray[index] << endl;

	}//End FOR LOOP

	cout << endl;

	//*****************
	//*****DOUBLE******
	//*****************
	stack<double> doubleStack; //Creates an double STL stack
	int doubleSize = 0;

	//PROCESSING - This is the push function, it was add a double to the stack and
	//				output so
	for( int index = 0; index < 8; index++){

		//Calls the STL .push method to add the element to the stack
		doubleStack.push(doubleArray[index]);

		//Outputs to the console that the item is being added
		cout << "Adding: " << doubleArray[index] << " to the STL Stack!\n";

		doubleSize = doubleStack.size();
	}//End FOR LOOP


	//outputs the stack
	cout << "\nThe items on the stack are: (From top to bottom)\n";
	for( int index = doubleSize - 1; index >= 0; index--){

		cout << doubleArray[index] << endl;

	}//End FOR LOOP

	cout << endl <<  endl;

	//Output to the console
	cout << "***************************\n"
			"*          Part B         *\n"
	     << "* Removing from STL Stack *\n"
		 << "***************************\n\n";

	cout << "Removing from the STRING STL Stack: \n"
			"----------------------------------\n";

	//PROCESSING - This is the pop function, it will be able to remove an element off
	//				of the stack and output so.
	for( int index = 0; index < 2; index++){

		//PROC - Checks to see if the stack is empty or not
		if(!stringStack.empty())
		{
			//If not empty then it will output the top of the stack and output that
			//it is getting removed
			cout << "The top of the Stack: " << stringStack.top()
			     << ", has been popped of the Stack!\n";

			//Calls the Pop funtion from the Stack STL
			stringStack.pop();

			currentSize = stringStack.size();

		}// End IF
		else{
			//If the stack is empty it will output so
			cout << "The STACK is Empty!!!\n\n";

		}//End ELSE

	}//End FOR LOOP

	//PROCESSING - Outputs the rest of the stack to the console
	cout << "\nThe remaining items on the Stack are: \n";
	for(  int index = 0; index < currentSize; index++ ){
		//Outputs the top of the stack using the STL stack function Top
		cout << stringStack.top() << endl;

		//Then Pops of the stack in order to show the rest of the stack
		stringStack.pop();
	}//End FOR LOOP

	cout <<  endl;

	//*****************
	//*****DOUBLE******
	//*****************
	cout << "\nRemoving from the DOUBLE STL Stack: \n"
			"----------------------------------\n";

	//PROCESSING - This is the pop function, it will be able to remove an element off
	//				of the stack and output so.
	for( int index = 0; index < 2; index++){

		//Checks to see if the stack is empty or not
		if(!doubleStack.empty())
		{
			//If not empty then it will output the top of the stack and output that
						//it is getting removed
			cout << "The top of the Stack: " << doubleStack.top()
			     << ", has been popped of the Stack!\n";

			//Calls the STL .Pop function to remove from the stack
			doubleStack.pop();

			doubleSize = doubleStack.size();

		}//End IF
		else{
			//outputs if the stack is empty
			cout << "The STACK is Empty!!!\n\n";
		}//End ELSE

	}//End FOR LOOP

	//PROCESSING - Outputs the rest of the stack to the console
	cout << "\nThe remaining items on the Stack are: \n";
	for( int index = 0; index < doubleSize; index++ ){
		//Outputs the top of the stack using the STL stack function Top
		cout << doubleStack.top() << endl;

		//Then Pops of the stack in order to show the rest of the stack
		doubleStack.pop();

	}//End FOR LOOP
}//End FUNCTION
