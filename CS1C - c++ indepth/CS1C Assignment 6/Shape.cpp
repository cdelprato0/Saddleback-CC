/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #8:Abstract Classes
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/

#include "Shape.h"

//DEFALUT CONSTRUCTOR
Shape::Shape()
		{	}

//DE-CONSTRUCTOR
Shape::~Shape()
		{	}

//Pure virtual methods are used to call the derived classes methods
double Shape::calcPerimeter()
	{return -1.0;}

//Pure virtual methods are used to call the derived classes methods
double Shape::calcArea()
	{return -1.0;}
