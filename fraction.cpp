#include "fraction.h"
#include <cmath>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <utility>

Fraction::Fraction (int numerator, int denominator = 1)
{
	if (denominator * numerator > 0) {
		m_numerator = abs(numerator);
		m_denominator = abs(denominator);
	} else {
		m_numerator = -abs(numerator);
		m_denominator = abs(denominator);
	}
}

std::pair<int, int> decimal_to_common (double decimal_fraction)
{
	int numerator = 1;
	int denominator = 1;

	for (int i = 0; i < 1000; i++) {
		double tmp = (double)numerator / (double)denominator;
		if (decimal_fraction == tmp)
			return {numerator, denominator};
		else if (decimal_fraction < tmp)
			denominator++;
		else 
			numerator++;
	}
	return {numerator, denominator};
}

Fraction::Fraction (double decimal_fraction)
{
	int sign = 1;
	if (decimal_fraction < 0) {
		decimal_fraction = -decimal_fraction;
		sign = -1;
	}

	int whole = trunc(decimal_fraction);
	decimal_fraction -= whole;

	std::pair<int, int> fraction = decimal_to_common(decimal_fraction);
	m_numerator = (fraction.first + (fraction.second * whole)) * sign;
	m_denominator = fraction.second;
}

Fraction::Fraction (std::string str)
{
	int sign = 1;
	if (str[0] == '-') {
		str.erase(0, 1);
		sign = -1;
	}

	int i = 0;
	while (str[i++] != '.');
	std::string tmp = str;
	tmp.erase(i - 1, str.length() - i + 1);
	str.erase(0, i - 1);
	str.insert(0, "0");
	std::stringstream ss;
	ss << tmp;
	// std::cout << "whole part is " << ss.str() << '\n';
	int whole;
	ss >> whole;
	ss = std::stringstream();
	ss << str;
	// std::cout << "fraction part is " << ss.str() << '\n';
	double decimal_fraction;
	ss >> decimal_fraction;
	// std::cout << tmp << ' ' << str << '\n';
	// std::cout << std::fixed << std::setprecision(10) << whole << ' ' << decimal_fraction;
	std::pair<int, int> fraction = decimal_to_common(decimal_fraction);
	// std::cout << '\n' << fraction.first << ' ' << fraction.second;

	m_numerator = (fraction.first + (fraction.second * whole)) * sign;
	m_denominator = fraction.second;
}

void Fraction::print ()
{
	std::cout << m_numerator << '/' << m_denominator;
}