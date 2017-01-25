#include <iostream>
#include "GeometricObject.h"
#include "DerivedCircle.h"
#include "Rectangle.h"
#include <string>
using namespace std;
int main()
{
	GeometricObject shape;
	shape.setColor("red");
	shape.setFilled(true);
	cout<<shape.toString()<<endl;
	Circle circle(5);
	circle.setColor("black");
	circle.setFilled(false);
	cout<<"Circle radius : "<<circle.getRadius()<<" area : "<<circle.getArea()<<" perimeter: " <<circle.getPerimeter()<<endl;
	cout<<circle.toString()<<endl;
	Rectangle rectangle(3,2,"orange",true);
	cout<<"Rectangle width: "<<rectangle.getWidth()<<" height: "<<rectangle.getHeight()<<" area: "<<rectangle.getArea()<<endl;
	cout<<rectangle.toString()<<endl;
	return 0;
}