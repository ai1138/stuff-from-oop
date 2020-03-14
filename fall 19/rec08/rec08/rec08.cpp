/*
testRational.cpp
CS2124
Implement the class Rational, so that the following program works.
*/

#include <iostream>
using namespace std;
// If time allows use  separate compilation, otherwise just define the class below
//#include "Rational.h"
// If time allows after implementing separate compilation, then wrap the class in a namespace.
//using namespace CS2124
int greatestCommonDivisor(int x, int y);

class Rational
{
friend ostream& operator<<(ostream& os, const Rational& rat);
friend istream& operator>>(istream& is, Rational& rat);

public:
	Rational()
	{
		this->numerator = 0;
		this->denominator = 1;
		this->normalize();
	}
	
	Rational(int numer,int denom = 1)
	{
		this->numerator = numer;
		this->denominator = denom;
		this->normalize();
	}
	Rational& operator+=(Rational& rhs)
	{
		this->numerator = (this->numerator * rhs.denominator) + (rhs.numerator * this->denominator);
		this->denominator = (this->denominator * rhs.denominator);
		this->normalize();
		return *this;
	}

private:
	int numerator;
	int denominator;
	void normalize()
	{
		int divisor = greatestCommonDivisor(this->numerator, this->denominator);
		this->numerator = this->numerator / divisor;
		this->denominator = this->denominator / divisor;
	}
	

};
int main() 
{
	Rational twoThirds(-6, 4);
	cout << twoThirds << endl;
	
	Rational a, b;
	cout << "Input a rational number, e.g. 6/9.\n";
	cout << "a: ";
	cin >> a;
	cout << "Input a rational number, e.g. 6/9.\n";
	cout << "b: ";
	cin >> b;
	const Rational one = 1;
	
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "one = " << one << endl;
	cout << "a += b: " << (a += b) << endl;	// Implement as member
	cout << "a = " << a << endl;
	/*
	// Implement as non-member, but not a friend
	cout << "a + one: " << (a + one) << endl;
	cout << "a == one: " << boolalpha << (a == one) << endl;

	// How does this manage to work?
	// It does NOT require writing another == operator. 
	cout << "1 == one: " << boolalpha << (1 == one) << endl;

	// Do not implement as friend.
	cout << "a != one: " << boolalpha << (a != one) << endl;

	cout << "a = " << a << endl;
	cout << "++a = " << (++a) << endl;
	cout << "a = " << a << endl;
	cout << "a++ = " << (a++) << endl;
	cout << "a = " << a << endl;
	cout << "--a = " << (--a) << endl;
	cout << "a = " << a << endl;
	cout << "a-- = " << (a--) << endl;
	cout << "a = " << a << endl;

	cout << "++ ++a = " << (++ ++a) << endl;
	cout << "a = " << a << endl;
	cout << "-- --a = " << (-- --a) << endl;
	cout << "a = " << a << endl;

	cout << "a++ ++ = " << (a++ ++) << endl;
	cout << "a = " << a << endl;

	// Even though the above example, (a++ ++), compiled, the
	// following shouldn't.
	// But some compiler vendors might let it...  Is your compiler
	// doing the right thing?
	cout << "a-- -- = " << (a-- --) << endl;
	cout << "a = " << a << endl;


	// Should report that 1 is true
	if (Rational(1)) 
	{
		cout << "1 is true" << endl;
	}
	else 
	{
		cout << "1 is false" << endl;
	}

	// Should report that 0 is false
	if (Rational(0)) 
	{
		cout << "0 is true" << endl;
	}
	else 
	{
		cout << "0 is false" << endl;
	}
	*/
}

int greatestCommonDivisor(int x, int y)
{
	while (y != 0)
	{
		int temp = x % y;
		x = y;
		y = temp;
	}
	return x;
}

istream& operator>>(istream& is, Rational& rat)
{
	int numer;
	int denom;
	char skip;
	is >> numer;
	rat.numerator = numer;
	is >> skip;
	is >> denom;
	rat.denominator = denom;
	return is;
}
Rational& operator+(Rational& lhs , )
{

}
ostream& operator<<(ostream& os, const Rational& rat)
{
	os << rat.numerator << "/" << rat.denominator << endl;
	return os;
}
