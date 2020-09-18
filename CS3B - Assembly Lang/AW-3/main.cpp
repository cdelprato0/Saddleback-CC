/************************************************************************************
 * AUTHOR	      :Chaz Del Prato
 * STUDENT ID     :382108
 * Assignment #3  :AW-3
 * CLASS	      :CS3B
 * SECTION	      :T/TH 3:30
 ************************************************************************************/
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){

	//Holds the array of string for each set of signed integers
	long intArray[] = {0, -1, 1000000, 2147483647, -2147483648,
			268435456, 16777216, 1048576, 65536, 16
	};

	//Main for loop that will convert the given decimal numbers to hexidecimal
	for( int ind = 0; ind < 10; ind++ ){

		long long decimal = intArray[ind]; //Holds the decimal value
		string binaryArray[32] = {""};	   //Holds the binary value of the decimal value
		string hexArray[8] = {""};		   //Holds the hex values for the result
		int index;						   //Used to keep an index for the binary numbers
		int hexIndex;					   //Used to keep an index for the hex numbers
		int binaryIndex;				   //Used to keep an index of the binary numbers
		bool negative = false;		       //Will determine if the number is negative or not
		char onesComp[32];				   //Used to get Ones complement
		char twosComp[32];				   //Used for twos complement
		int carry = 1;					   //Used in twos complement
		int count;						   //Used as an index
		string tempStr;					   //A temporary string to hold string values

		//Initializes the string array for the hex output to all zeros
		for( int i = 0; i < 32; i++ ){
			binaryArray[i] = "0";
		}

		//Checks to see if the value is negative, if it is, then it will take abs of number
		//and make it positive
		if(decimal < 0){
			decimal = abs(decimal);
			negative = true;
		}

		//Will determine the binary representation of the positive decimal value
		index = 31;
		while( decimal > 0 ){
			binaryArray[index] = string(1, (char)(decimal%2 + 48));
			decimal = decimal/2;
			index--;
		}

		//If the number is negative, it will find the ones comp, then the twos comp
		//and then save it into the binaryArray
		if(negative){
			for(int i = 0; i < 32; i++){
				tempStr = tempStr + binaryArray[i] ;
			}

			count = 0;
			//Will take in the input string and convert the binary word to its ones complement
			for( unsigned int i = 0; i < 32; i++ ){

				//Temp variables used in order to convert the ASCII char given from
				//signedBinary[bitCount], into an the appropriate integer in the string
				char temp = tempStr[count];
				int tempInt = temp - '0';

				//Determines when to reverse the binary digits
				if(tempInt == 1){
					onesComp[i] = '0';
				}else if(tempInt == 0){
					onesComp[i] = '1';
				}
				count++;
			}

			//Determines the twos complement of the ones complement character string
			carry = 1;
			for( int i = 31; i >= 0; i-- ){

				if( onesComp[i] == '1' && carry == 1){
					twosComp[i] = '0';
				}else if( onesComp[i] == '0' && carry == 1){
					twosComp[i] = '1';
					carry = 0;
				}else{
					twosComp[i] = onesComp[i];
				}
			}

			for(int i = 0; i < 32; i++){
				binaryArray[i] = twosComp[i];
			}
		}

		//Will now determine the hexadecimal representation of the binary numbers
		hexIndex = 7;
		binaryIndex = 31;
		for( int in = 0; in < 32; in = in+4){
			string temp = "";

			//Will load the temp variable with the next four binary digits to compare
			for( int i = 0; i < 4; i++ ){
				temp = binaryArray[binaryIndex] + temp;
				binaryIndex--;
			}

			//Will compare the four binary digits and determine which hex value they are
			if(temp.compare("0000") == 0 ) hexArray[hexIndex] = "0";
			else if(temp.compare("0001") == 0 ) hexArray[hexIndex] = "1";
			else if(temp.compare("0010") == 0 ) hexArray[hexIndex] = "2";
			else if(temp.compare("0011") == 0 ) hexArray[hexIndex] = "3";
			else if(temp.compare("0100") == 0 ) hexArray[hexIndex] = "4";
			else if(temp.compare("0101") == 0 ) hexArray[hexIndex] = "5";
			else if(temp.compare("0110") == 0 ) hexArray[hexIndex] = "6";
			else if(temp.compare("0111") == 0 ) hexArray[hexIndex] = "7";
			else if(temp.compare("1000") == 0 ) hexArray[hexIndex] = "8";
			else if(temp.compare("1001") == 0 ) hexArray[hexIndex] = "9";
			else if(temp.compare("1010") == 0 ) hexArray[hexIndex] = "a";
			else if(temp.compare("1011") == 0 ) hexArray[hexIndex] = "b";
			else if(temp.compare("1100") == 0 ) hexArray[hexIndex] = "c";
			else if(temp.compare("1101") == 0 ) hexArray[hexIndex] = "d";
			else if(temp.compare("1110") == 0 ) hexArray[hexIndex] = "e";
			else if(temp.compare("1111") == 0 ) hexArray[hexIndex] = "f";

			hexIndex--;
		}

		//Console output with the columns set
		cout << right << setw(11) << intArray[ind] << " = ";
		for( int i = 0; i < 8; i++ ){
			cout << hexArray[i];
		}
		cout << "h" <<  endl;

	}//End Main FOR
	//System pause
	system("PAUSE");
	return 0;
}//End MAIN
