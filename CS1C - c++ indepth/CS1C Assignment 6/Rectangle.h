/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #8:Abstract Classes
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/
#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

class Rectangle: public Shape {

public:

	/***************************
	 * CONSTRUCTOR * DESTRUCTOR*
	 ***************************/
	Rectangle();
	virtual ~Rectangle();

	/*************
	 * ACCESSORS *
	 *************/
	void SetLength(double l);
	void SetWidth(double w);

	double calcPerimeter();
	double calcArea();

private:

	double length; //length of the rectangle
	double width;	//width of the rectangle
};

#endif /* RECTANGLE_H_ */
