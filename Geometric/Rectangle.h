#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "GeometricObject.h"
class Rectangle:public GeometricObject
{
public:
	Rectangle();
	Rectangle(double width,double height);
	Rectangle(double width,double height,string color,bool filled);
	double getWidth();
	double getHeight();
	void setWidth(double width);
	void setHeight(double height);
	double getArea();
private:
	double width;
	double height;
};
#endif