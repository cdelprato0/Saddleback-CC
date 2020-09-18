/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #8:Abstract Classes
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/

#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

class Shape {
public:

	/***************************
	 * CONSTRUCTOR * DESTRUCTOR*
	 ***************************/
	Shape();
	virtual ~Shape();

	/*************
	 * ACCESSORS *
	 *************/
	virtual double calcPerimeter() = 0;
	virtual double calcArea() = 0;

};

#endif /* SHAPE_H_ */
