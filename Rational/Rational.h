#ifndef RATIONAL_H
#define RATIONAL_H
#include <string>
#include <iostream>
using namespace std;
class Rational
{
public:
	Rational();
	Rational(long numerator, long denominator);
	long getNumerator();
	long getDenominator();
	Rational add(Rational &secondRational);
	Rational subtract(Rational &secondRational);
	Rational multiply(Rational &secondRational);
	Rational divide(Rational &secondRational);
	int compareTo(Rational &secondRational);
	bool equals(Rational &secondRational);
	int intValue();
	double doubleValue();
	bool operator<(Rational &secondRational);
	bool operator>(Rational &secondRational);
	bool operator<=(Rational &secondRational);
	bool operator>=(Rational &secondRational);
	bool operator==(Rational &secondRational);
	bool operator!=(Rational &secondRational);

	Rational operator+(Rational &secondRational);
	Rational operator-(Rational &secondRational);
	Rational operator*(Rational &secondRational);
	Rational operator/(Rational &secondRational);

	Rational operator+=(Rational &secondRational);
	Rational operator-=(Rational &secondRational);
	Rational operator*=(Rational &secondRational);
	Rational operator/=(Rational &secondRational);

	long& operator[](const int &index);

	Rational operator++();
	Rational operator--();

	Rational operator++(int dummy);
	Rational operator--(int dummy);

	Rational operator-();

	friend ostream &operator<<(ostream &stream, Rational &rational1);
	friend istream &operator >> (istream &stream, Rational &rational);

	operator double();


private:
	long numerator;
	long denominator;
	static long gcd(long n, long d);
};
#endif // !RATIONAL_H

