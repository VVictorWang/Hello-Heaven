#include <iostream>
#include "StackOfInt.h"
using namespace std;
int main()
{
	StackOfInt stack;
	int value;
	cout<<"输入数字（输入0结束）：";
	cin>>value;
	while(value!=0)
	{
		stack.push(value);
		cout<<"输入数字（输0结束）：";
		cin>>value;
	}
	while(!stack.empty())
		cout<<stack.pop()<<"  ";
	return 0;
}
