/************************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #2:Stacks & Dequeue
 * CLASS	    :CS1D
 * SECTION	    :M/W 3:30 PM
 ************************************************************************************/
#include "Header.h"

//Set before the function so it can see it
bool checkChar( char character1, char character2 );

bool paraCheck(){
	List* head = NULL; 		//Keeps track of the head of the stack
	List* currentNode; 		//Creates a new node for the stack
	string input; 			//reads in user input
	int currentSize = 0; 	//Keeps track of the size of the stack
	char charArray[25]; 	//Used to convert the input to a character array
	int index = 0; 			//Used to keep an index of the char array

	//Reads in user input for the expression
	cout << "\n\nEnter the expression: \n";
	getline(cin, input);

	cout << "The expression " << input << " is: ";
	//Converts the string input into the character array so that each character can
	//be  using string copy
	strcpy(charArray, input.c_str());

	//PROCESSING - checks to see if there is a correct number of parenthesis and if
	//             they are placed in the right order
	while(charArray[index]){

		//Looks for the first bracket
		if(charArray[index] == '(' || charArray[index] == '[' || charArray[index] == '{'){

			//If it finds the first braket it will add the bracket to the stack and
			//will check later to see if the ending bracket exist
			currentNode = new List;
			currentNode->next = head;
			head = currentNode;
			head->exp = charArray[index];

			//Increments the size of the stack
			currentSize++;
		}

		List* remove = NULL; //used to remove from the stack

		//PROC - Checks to see if it can find the ending bracket of the expression
		if(charArray[index] == ')' || charArray[index] == ']' || charArray[index] == '}'){

			//Checks the stack to see if it is empty or if the characters are the same
			if(head == NULL || !checkChar(head->exp,charArray[index])){
				return false;
			}
			else{
				//If the ending brackets are found then it will delete the bracket
				//off the stack
				remove = new List;
				remove = head;
				head = remove->next;
				delete remove;

				//Decrements the size of the stack
				currentSize--;
			}

		}//End IF

		//Increments to the next index in the character array
		index++;
	}//End WHILE LOOP

	//returns if the head is equal to nothing or in other words if the stack is empty
	return (head == NULL);
}

//Checks to see if the the characters that have been entered are the same or if they
//are not and will return true if they are the same and false if they are not
bool checkChar( char character1, char character2 ){
	if(character1 == '(' && character2 == ')'){
		return true;
	}
	else if(character1 == '[' && character2 == ']')
	{
		return true;
	}
	else if(character1 == '{' && character2 == '}')
	{
		return true;
	}
	else{
		return false;
	}
}
