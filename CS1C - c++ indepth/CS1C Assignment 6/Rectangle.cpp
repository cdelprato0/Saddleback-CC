/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #8:Abstract Classes
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/

#include "Rectangle.h"

//DEFAULT CONSTRUCTOR
Rectangle::Rectangle()
{
	length = 0.0;
	width = 0.0;
}//End METHOD

//DE-CONSTRUCTOR
Rectangle::~Rectangle()
		{	}//End METHOD

/*************************************************************************
 * METHOD SetLength
 * ________________________________________________________________________
 * This method sets the length of the Rectangle.
 *
 * _______________________________________________________________________
 *
 ************************************************************************/
void Rectangle::SetLength(double l)
{
	length = l;
}//End METHOD

/*************************************************************************
 * METHOD SetWidth
 * ________________________________________________________________________
 * This method sets the width of the Rectangle.
 *
 * _______________________________________________________________________
 *
 ************************************************************************/
void Rectangle::SetWidth(double w)
{
	width = w;
}//End METHOD

/*************************************************************************
 * METHOD calcPerimeter
 * ________________________________________________________________________
 * This method calculates the perimeter of the Rectangle.
 * Pure virtual functions are used.
 *
 * _______________________________________________________________________
 *
 ************************************************************************/
double Rectangle::calcPerimeter()
{
	double perimeter; //Holds the value of the perimeter

	//Calculates the perimeter
	perimeter = 2 * (length + width);

	return perimeter;

}//End METHOD

/*************************************************************************
 * METHOD calcArea
 * ________________________________________________________________________
 * This method calculates the area of the Rectangle.
 * Pure virtual functions are used.
 *
 * _______________________________________________________________________
 *
 ************************************************************************/
double Rectangle::calcArea()
{
	double area;  //holds the value for area

	//Calculates the area of the rectangle
	area = length * width;

	return area;

}//End METHOD
