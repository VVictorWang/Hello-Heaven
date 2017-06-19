#include "Rectangle.h"
Rectangle::Rectangle()
{
	width = 1;
	height = 1;
}
Rectangle::Rectangle(double width,double height)
{
	this->width = width;
	this->height = height;
}
Rectangle::Rectangle(double width,double height,string color,bool filled)
	:GeometricObject(color,filled)
{
	this->width = width;
	this->height = height;
}
double Rectangle::getWidth()
{
	return this->width;
}
double Rectangle::getHeight()
{
	return this->height;
}
void Rectangle::setWidth(double width)
{
	this->width = width;
}
void Rectangle::setHeight(double height)
{
	this->height = height;
}
double Rectangle::getArea()
{
	return width*height;
}