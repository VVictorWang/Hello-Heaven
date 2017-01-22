#include <iostream>
#include "StackOfInt.h"
using namespace std;
StackOfInt::StackOfInt()
{
	size = 0;

}
bool StackOfInt::empty()
{
	if(size == 0)
		return true;
	return false;
}
int StackOfInt::peek()
{
	if(!empty())
		return elements[size-1];
	return -65535;
}
void StackOfInt::push(int x)
{
	if(size>=100)
		cout<<"The Stack is full!";
	else
	{
		elements[size] = x;
		size++;
	}
}
int StackOfInt::pop()
{
	if(!empty())
	{
		size--;
		return elements[size];
	}
}
int StackOfInt::getSize()
{
	return size;
}
