/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :382108
 * Assignment #8:Abstract Classes
 * CLASS	    :CS1C
 * SECTION	    :M/W 2:00 PM
 *************************************************************************/

#include "Triangle.h"

//DEFAULT CONSTRUCTOR
Triangle::Triangle()
{
	sideOne = 0.0;
	sideTwo = 0.0;
	sideThree = 0.0;

}//End METHOD

//DE-CONSTRUCTOR
Triangle::~Triangle()
		{	}//End METHOD

/*************************************************************************
 * METHOD SetOneSide
 * ________________________________________________________________________
 * This method sets the one side of the triangle
 *
 * _______________________________________________________________________
 *
 ************************************************************************/
void Triangle::SetSideOne(double s1)
{
	sideOne = s1;
}//End METHOD

/*************************************************************************
 * METHOD SetSideTwo
 * ________________________________________________________________________
 * This method sets the one side of the triangle
 *
 * _______________________________________________________________________
 *
 ************************************************************************/
void Triangle::SetSideTwo(double s2)
{
	sideTwo = s2;
}//End METHOD

/*************************************************************************
 * METHOD SetSideThree
 * ________________________________________________________________________
 * This method sets the one side of the triangle
 *
 * _______________________________________________________________________
 *
 ************************************************************************/
void Triangle::SetSideThree(double s3)
{
	sideThree = s3;
}//End METHOD

/*************************************************************************
 * METHOD calcPerimeter
 * ________________________________________________________________________
 * This method calculates the perimeter of the Triangle.
 * Pure virtual functions are used.
 *
 * _______________________________________________________________________
 *
 ************************************************************************/
double Triangle::calcPerimeter()
{
	double perimeter; //Holds the value of the variable

	//Calculates the perimeter of the triangle
	perimeter = sideOne + sideTwo + sideThree;

	return perimeter;

}//End METHOD

/*************************************************************************
 * METHOD calcArea
 * ________________________________________________________________________
 * This method calculates the area of the Triangle.
 * Pure virtual functions are used.
 *
 * _______________________________________________________________________
 *
 ************************************************************************/
double Triangle::calcArea()
{
	double area; //Holds the value for area
	double s;	//Holds the value of s

	//Calculates the area of the the triangles
	s =(sideOne + sideTwo + sideThree)/2;
	area = sqrt(s*(s-sideOne)*(s-sideTwo)*(s-sideThree));

	return area;
}//End METHOD
