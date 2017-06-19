#ifndef STACK_H
#define STACK_H
class StackOfInt
{
public:
	StackOfInt();
	bool empty();
	int peek();
	void push(int x);
	int pop();
	int getSize();
private:
	int elements[100];
	int size;
};
#endif
