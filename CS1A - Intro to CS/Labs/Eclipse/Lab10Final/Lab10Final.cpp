/**************************************************************************
 * PROGRAMMED BY: Chris COyle & Chaz Del Prato
 * CLASS		: CS1A
 * SECTION		: MW 9:30a
 * Lab #10		: Input & Output - Geometry
 *************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**************************************************************************
 * This program will calculate,store,and output the area and circumference
 * of a triangle, rectangle, and circle object.
 *************************************************************************/

int main()
{
	//This is the header that will display in the output

	const char PROGRAMMER[30]	= "Chris Coyle & Chaz Del Prato";
	const char CLASS[5]			= "CS1A";
	const char SECTION[25]		= "MW: 9:30AM";
	const int  LAB_NUM			= 10;
	const char LAB_NAME[28]		= "Output - Geometry";

	cout << left;
	cout << "********************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB#" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n********************************\n\n";
	cout << right;


	float pi=3.14159;		//ASSIGN - value of pi
	float height;			//INPUT - User enters height
	float base;				//INPUT - User enters base
	float width;			//INPUT - User enters width
	float radius;			//INPUT - User enters radius
	float tarea;			//CALC & OUT - Area of a triangle
	float tcircumference;	//CALC & OUT - Circumference of a triangle
	float rarea;			//CALC & OUT - Area of a rectangle
	float rcircumference;	//CALC & OUT - Circumference of a rectangle
	float carea;			//CALC & OUT - Area of a circle
	float ccircumference;	//CALC & OUT - Circumference of a circle


	//INPUT - reads in two inputs from the user (height & base)
	cout << left << setw(34);
	cout << "Enter the height of the triangle:";
	cin  >> height;
	cout << setw(34);
	cout << "Enter the base of the triangle:";
	cin  >> base;
	cout << endl;

	//PROCESSING - Calculates the area and circumference of triangles
	tarea = height*base/2;
	tcircumference = base*3;

	//OUTPUT - Outputs the inputs and the Area and Circumference
	cout << "TRIANGLE OBJECT"<<endl << setw(9) << right;
	cout << "Area:"<< setw(18) << "Circumference:";
	cout << endl << setw(9) << tarea << setw(18)  << tcircumference;
	cout << endl << endl << endl;

	//INPUT - reads in two inputs from the user (height & width)
	cout << left << setw(34);
	cout << "Enter the width of the rectangle:  ";
	cin  >> width;
	cout << setw(34);
	cout << "Enter the height of the rectangle: ";
	cin  >> height;
	cout << endl;

	//PROCESSING - Calculates the area and circumference of rectangles
	rarea = width*height;
	rcircumference = (width+height)*2;

	//OUTPUT - Outputs the inputs and the Area and Circumference
	cout <<"RECTANGLE OBJECT"<< endl << setw(9) << right;
    cout <<"Area:"<< setw(18) << "Circumference:";
	cout << endl << setw(9) << rarea << setw(18) <<rcircumference;
	cout << endl << endl << endl;

	//INPUT - read in one input from the user (radius)
	cout << left << setw(34);
	cout << "Enter the radius of the circle: ";
	cin  >> radius;
	cout << endl;

	//PROCESSING - Calculates the area and circumference of circles
	carea = pi*(radius*radius);
	ccircumference = pi*radius*2;

	//OUTPUT - Outputs the inputs and the Area and Circumference
	cout <<"CIRCLE OBJECT" << endl << setw(9)<< right;
	cout << "Area:" << setw(18) << "Circumference:";
	cout << endl << setw(9) << carea << setw(18) <<ccircumference;
	cout << endl << endl << endl << endl << endl;

	return 0;
}
