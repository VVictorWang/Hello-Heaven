#ifndef DERIVEDCIRCLE_H
#define  DERIVEDCIRCLE_H
#include "GeometricObject.h"
class Circle:public GeometricObject
{
public:
	Circle();
	Circle(double radius);
	Circle(double radius,string color,bool filled);
	double getRadius();
	void setRadius(double radius);
	double getArea();
	double getPerimeter();
	double getDiameter();
private:
	double radius;
};
#endif

