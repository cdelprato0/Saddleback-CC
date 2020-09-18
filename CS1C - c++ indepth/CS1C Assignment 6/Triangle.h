/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #8:Abstract Classes
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Shape.h"

class Triangle: public Shape {

public:

	/***************************
	 * CONSTRUCTOR * DESTRUCTOR*
	 ***************************/
	Triangle();
	virtual ~Triangle();

	/*************
	 * ACCESSORS *
	 *************/
	void SetSideOne(double s1);
	void SetSideTwo(double s2);
	void SetSideThree(double s3);

	double calcPerimeter();
	double calcArea();

private:

	double sideOne; //one side of the triangle
	double sideTwo; //second side of the triangle
	double sideThree; //third side of the triangle
};

#endif /* TRIANGLE_H_ */
