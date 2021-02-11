#pragma once
#include <string>
#include <iostream>

class Fraction
{
	private:

	int m_numerator;
	int m_denominator;

	void fraction_reduction();

	public:

	Fraction ();
	Fraction (int numerator);
	Fraction (int numerator, int denominator);
	Fraction (double decimal_fraction);
	Fraction (std::string str);

	Fraction operator- ();
	Fraction operator+ (const Fraction &a);
	Fraction operator- (const Fraction &a);
	Fraction operator* (const Fraction &a);
	Fraction operator/ (const Fraction &a);
	Fraction operator= (const Fraction &a);

	friend std::ostream &operator<< (std::ostream &output, const Fraction &a);
	friend std::istream &operator>> (std::istream &input, Fraction &a);

	void print();
};