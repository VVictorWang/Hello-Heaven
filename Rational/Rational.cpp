#include "Rational.h"
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
Rational::Rational()
{
	numerator = 0;
	denominator = 1;
}
Rational::Rational(long numerator, long denominator)
{
	long factor = gcd(numerator, denominator);
	this->numerator = ((denominator > 0) ? 1 : -1)*numerator / factor;
	this->denominator = abs(denominator) / factor;
}
long Rational::getDenominator()
{
	return this->denominator;
}
long Rational::getNumerator()
{
	return this->numerator;
}
Rational Rational::add(Rational &secondRational)
{
	long n = numerator*secondRational.getDenominator() + denominator*secondRational.getNumerator();
	long d = denominator*secondRational.getDenominator();
	return Rational(n, d);
}
Rational Rational::subtract(Rational &secondRational)
{
	long n = numerator*secondRational.getDenominator() - denominator*secondRational.getNumerator();
	long d = denominator*secondRational.getDenominator();
	return Rational(n, d);
}
Rational Rational::multiply(Rational &secondRational)
{
	long n = numerator * secondRational.getNumerator();
	long d = denominator * secondRational.getDenominator();
	return Rational(n, d);
}
Rational Rational::divide(Rational &secondRational)
{
	long n = numerator * secondRational.getDenominator();
	long d = denominator * secondRational.getNumerator();
	return Rational(n, d);
}
int Rational::compareTo(Rational &secondRational)
{
	Rational temp = this->subtract(secondRational);
	if (temp.getNumerator() > 0)
		return 1;
	if (temp.getNumerator() == 0)
		return 0;
	if (temp.getNumerator() < 0)
		return -1;
}
bool Rational::equals(Rational &secondRational)
{
	return (this->subtract(secondRational).getNumerator() == 0);
}
int Rational::intValue()
{
	return (int)(this->numerator / this->denominator);
}
double Rational::doubleValue()
{
	return (double)(this->numerator / this->denominator);
}
bool Rational::operator<(Rational & secondRational)
{
	if (this->compareTo(secondRational) < 0)
		return true;
	return false;
}
bool Rational::operator>(Rational & secondRational)
{
	if (this->compareTo(secondRational)> 0)
		return true;
	return false;
}
bool Rational::operator<=(Rational & secondRational)
{
	if (this->compareTo(secondRational) < 0 || this->compareTo(secondRational)==0)
		return true;
	return false;
}
bool Rational::operator>=(Rational & secondRational)
{
	if (this->compareTo(secondRational) > 0 || this->compareTo(secondRational) == 0)
		return true;
	return false;
}
bool Rational::operator==(Rational & secondRational)
{
	if (this->equals(secondRational))
		return true;
	return false;
}
bool Rational::operator!=(Rational & secondRational)
{
	if (!this->equals(secondRational))
		return true;
	return false;
}
Rational Rational::operator+(Rational & secondRational)
{
	return (this->add(secondRational));
}
Rational Rational::operator-(Rational & secondRational)
{
	return this->subtract(secondRational);
}
Rational Rational::operator*(Rational & secondRational)
{
	return this->multiply(secondRational);
}
Rational Rational::operator/(Rational & secondRational)
{
	return this->divide(secondRational);
}
Rational Rational::operator+=(Rational & secondRational)
{
	*this = this->add(secondRational);
	return (*this);
}
Rational Rational::operator-=(Rational & secondRational)
{
	*this = this->subtract(secondRational);
	return (*this);
}
Rational Rational::operator*=(Rational & secondRational)
{
	*this = this->multiply(secondRational);
	return (*this);
}
Rational Rational::operator/=(Rational & secondRational)
{
	*this = this->divide(secondRational);
	return (*this);
}
long & Rational::operator[](const int & index)
{
	if (index == 0)
		return numerator;
	if (index == 1)
		return denominator;
	else
	{
		cout << "error!";
		exit(0);
	}
	// TODO: 在此处插入 return 语句
}
Rational Rational::operator++()
{
	numerator += denominator;
	return *this;
}
Rational Rational::operator--()
{
	numerator -= denominator;
	return *this;
}
Rational Rational::operator++(int dummy)
{
	Rational temp = Rational(numerator, denominator);
	numerator += denominator;
	return temp;
}
Rational Rational::operator--(int dummy)
{
	Rational temp = Rational(numerator, denominator);
	numerator -= denominator;
	return temp;
}
Rational Rational::operator-()
{
	numerator *= (-1);
	return (*this);
}
Rational::operator double()
{
	return doubleValue();
}
long Rational::gcd(long n, long d)
{
	long n1 = abs(n);
	long n2 = abs(d);
	if (n1 < n2)
	{
		long temp = n1;
		n1 = n2;
		n2 = temp;
	}
	long m = n1%n2;
	while (m != 0)
	{
		n1 = n2;
		n2 = m;
		m = n1%n2;
	}
	return n2;
}

ostream & operator<<(ostream & stream, Rational & rational1)
{
	stream << rational1.numerator << "/" << rational1.denominator;
	return stream;
	// TODO: 在此处插入 return 语句
}

istream & operator >> (istream & stream, Rational & rational)
{
	cout << "Enter numerator";
	stream >> rational.numerator;
	cout << "Enter denometer";
	stream >> rational.denominator;
	return stream;
	// TODO: 在此处插入 return 语句
}
