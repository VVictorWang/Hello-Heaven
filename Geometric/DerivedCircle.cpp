#include "DerivedCircle.h"
Circle::Circle()
{
	radius = 1;
}
Circle::Circle(double radius)
{
	this->radius = radius;
}
Circle::Circle(double radius, string color, bool filled)
	:GeometricObject(color,filled)
{
	this->radius = radius;
}
double Circle::getRadius()
{
	return radius;
}
void Circle::setRadius(double radius)
{
	this->radius = radius;
}
double Circle::getArea()
{
	return 3.14*radius*radius;
}
double Circle::getPerimeter()
{
	return 2*3.14*radius;
}
double Circle::getDiameter()
{
	return 2*radius;
}