
#include "Rational.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	Rational rational1(4, 2);
	Rational rational2(8, 3);
	cout << rational1 << " >" << rational2 << " is " << (rational1 > rational2) << endl;
	cout << rational1 << " <" << rational2 << " is " << (rational1 < rational2) << endl;
	cout << rational1 << " ==" << rational2 << " is " << (rational1 == rational2) << endl;
	cout << rational1 << " !=" << rational2 << " is " << (rational1 != rational2) << endl;

	cout << rational1 << " + " << rational2 << " = " << rational1 + rational2 << endl;
	/* 
	Rational r3;
	cin >> r3;
	cout << rational1 << " + " << r3 << " = " << rational1 + r3 << endl;
	*/
	rational2 += rational1;
	cout << rational2 << endl;
	rational2 = ++rational1;
	cout << rational2<<endl;
	rational2 = rational1++;
	cout << rational2 << endl;
	return 0;
}
