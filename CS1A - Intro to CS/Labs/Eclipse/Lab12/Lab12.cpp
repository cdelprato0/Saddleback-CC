/*/**************************************************************************
 * PROGRAMMED BY: Jebus & BBC
 * CLASS		: CS1A
 * SECTION		: MW 9:30a
 * Lab #12		: Input & Output - Geometry
 *************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**************************************************************************
 * This program will calculate,store,and output the area of a triangle,
 * rectangle, and circle object.
 *************************************************************************/

int main() {
	//This is the header that will display in the output

	const char PROGRAMMER[30] = "Jebus & BBC";
	const char CLASS[5] = "CS1A";
	const char SECTION[25] = "MW: 9:30AM";
	const int LAB_NUM = 12;
	const char LAB_NAME[28] = "Output - Geometry";

	cout << left;
	cout << "***********************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB#" << setw(10) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n***********************************\n\n";
	cout << right;

	float pi = 3.14159;		//ASSIGN - value of pi
	float height;			//INPUT - User enters height
	float base;				//INPUT - User enters base
	float width;			//INPUT - User enters width
	float radius;			//INPUT - User enters radius
	float tarea;			//CALC & OUT - Area of a triangle
	float rarea;			//CALC & OUT - Area of a rectangle
	float carea;			//CALC & OUT - Area of a circle

	//INPUT - reads in two inputs from the user (height & base)
	cout << left << setw(35);
	cout << "Enter the height of the triangle:";
	cin >> height;
	cout << setw(35);
	cout << "Enter the base of the triangle:";
	cin >> base;
	cout << endl;

	//PROCESSING - Calculates the area of triangles
	tarea = height * base / 2;

	//INPUT - reads in two inputs from the user (height & width)
	cout << left << setw(35);
	cout << "Enter the width of the rectangle:  ";
	cin >> width;
	cout << setw(35);
	cout << "Enter the height of the rectangle: ";
	cin >> height;
	cout << endl;

	//PROCESSING - Calculates the area of rectangles
	rarea = width * height;

	//INPUT - read in one input from the user (radius)
	cout << left << setw(35);
	cout << "Enter the radius of the circle: ";
	cin >> radius;
	cout << endl << endl;

	//PROCESSING - Calculates the area of circles
	carea = pi * (radius * radius);

	//OUTPUT - Outputs the inputs and the Area and set this the numbers
	//		   to different precisions, fixed positions, or showpoints.
	cout << setw(18) << right << "Triangle Area";
	cout << setw(19) << "Rectangle Area" << setw(16) << "Circle Area";
	cout << endl;
	cout << setw(18) << tarea;
	cout << setw(19) << rarea;
	cout << setw(16) << carea;
	cout << endl << setprecision(3) << setw(18) << tarea << setw(19);
	cout << rarea << setw(16) << carea;
	cout << endl << setprecision(3) << showpoint << setw(18) << tarea;
	cout << setw(19) << rarea << setw(16) << carea;
	cout << endl << setprecision(3) << fixed << setw(18) << tarea;
	cout << setw(19) << rarea << setw(16) << carea;
	cout << endl << setprecision(5) << fixed << setw(18) << tarea;
	cout << setw(19) << rarea << setw(16) << carea;

	return 0;

}
