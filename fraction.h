#pragma once
#include <string>

class Fraction
{
	private:

	int m_numerator;
	int m_denominator;

	public:

	Fraction (int numerator, int denominator);
	Fraction (double decimal_fraction);
	Fraction (std::string str);

	void print();
};