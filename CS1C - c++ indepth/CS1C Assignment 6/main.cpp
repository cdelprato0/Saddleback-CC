/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #8:Abstract Classes
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#include "Rectangle.h"
#include "Triangle.h"
#include "Shape.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

//Function that prints out the perimeter
void PrintPerimeter(Shape* s);

//Function that prints out the area
void PrintArea(Shape* s);
/**************************************************************************
 * Assignment 6 - Abstract Classes
 * ________________________________________________________________________
 * This program will be able to take in the users input for the length and
 * width of a rectangle and the three sides of a triangle and will calculate
 * the perimeter and the area of each. The program will use abstract classes
 * and uses pure virtual methods for the derived classes. The rectangle and
 * triangle classes are subclasses from the Shape class. There are two
 * different print functions that print out the perimeter and area of each
 * object.
 *
 *************************************************************************/
int main()
{
	Rectangle* rect = new Rectangle; //Creates a new Rectangle class object
	Triangle* tri = new Triangle;	//Creates a new Triangle Class object

	//INPUT - Reads in the user input and save to these variables for a
	//			rectangle
	double length = 0.0;
	double width = 0.0;

	//INPUT - Reads in the users input for a Triangle and saves
	double sideOne = 0.0;
	double sideTwo = 0.0;
	double sideThree = 0.0;

	//INPUT - Prompts the user to enter the length and width for a rectangle
	cout << "...RECTANGLE...\n";
	cout << "Please enter the Length of the Rectangle: ";
	cin >> length;
	cin.ignore(1000, '\n');

	cout << "Please enter the Width of the Rectangle: ";
	cin >> width;
	cin.ignore(1000, '\n');
	cout << endl;

	//PROCESSING - Takes in the given values and sets them to the class
	//				data types
	rect->SetLength(length);
	rect->SetWidth(width);

	//OUTPUT - Outputs the given perimeter and area of the rectangles
	PrintPerimeter(rect);
	PrintArea(rect);

	//INPUT - Prompts the user to enter the three sides of the triangle
	cout << "\n...TRIANGLE...\n";
	cout << "Please enter One side of the Triangle: ";
	cin >> sideOne;
	cin.ignore(1000, '\n');

	cout << "Please enter One side of the Triangle: ";
	cin >> sideTwo;
	cin.ignore(1000, '\n');

	cout << "Please enter One side of the Triangle: ";
	cin >> sideThree;
	cin.ignore(1000, '\n');
	cout << endl;

	//PROCESSING - Sets the value of each side to the data members in the
	//				Triangle class
	tri->SetSideOne(sideOne);
	tri->SetSideTwo(sideTwo);
	tri->SetSideThree(sideThree);

	//OUTPUTS - Outputs the area and perimeter of the given triangle
	PrintPerimeter(tri);
	PrintArea(tri);

	return 0;
}//END MAIN


//***FUNCTIONS***
//Outputs to the console and calls the calcPerimeter method of the given
//shape
void PrintPerimeter(Shape* shape)
{

	cout << "Calculating the Perimeter...\n"
		 << "----------------------------\n"
		 << "The Perimeter is: " << shape->calcPerimeter()
		 << endl << endl;
}//End FUNCTION

//Outputs to the console and calls the calcArea method of the given shape
void PrintArea(Shape* shape)
{
	cout << "Calculating the Area...\n"
		 << "-----------------------\n"
		 << "The Area is: " << shape->calcArea()
		 << endl << endl;
}//End FUNCTION
