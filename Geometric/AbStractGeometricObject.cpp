#include "AbStractGeometricObject.h"
GeometricObject::GeometricObject()
{
	color = "white";
	filled = false;
}
GeometricObject::GeometricObject(string color, bool filled)
{
	this->color = color;
	this->filled = filled;
}
string GeometricObject::getColor()
{
	return this->color;
}
void GeometricObject::setColor(string color)
{
	this->color = color;
}
bool GeometricObject::isFilled()
{
	return this->filled;
}
void GeometricObject::setFilled(bool filled)
{
	this->filled = filled;
}
string GeometricObject::toString()
{
	return "Geometric object color: " + color + " filled: " + ((filled) ? "true" : "false");
}