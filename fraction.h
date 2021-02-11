#pragma once
#include <string>

class Fraction
{
	private:

	int m_numerator;
	int m_denominator;

	public:

	Fraction ();
	Fraction (int numerator, int denominator);
	Fraction (double decimal_fraction);
	Fraction (std::string str);

	Fraction operator- ();
	Fraction operator+ (const Fraction a);
	Fraction operator- (const Fraction a);
	Fraction operator* (const Fraction a);
	Fraction operator/ (const Fraction a);
	Fraction operator= (const Fraction a);
	
	// std::string operator<< ();
	// Fraction operator>> ();

	void print();
};