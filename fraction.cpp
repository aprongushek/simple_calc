#include "fraction.h"
#include <cmath>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <utility>
#include <cstdlib>

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

int get_gcd(int a, int b)
{
	if (a == b) {
		return a;
	} else {
		int diff = abs(a - b);
		if (a < b) 
			return get_gcd(diff, a);
		else
			return get_gcd(diff, b);
	}
}

Fraction::Fraction () : m_numerator(0), m_denominator(1) { }

Fraction::Fraction (int numerator) : m_numerator(numerator), m_denominator(1) { }

Fraction::Fraction (int numerator, int denominator = 1)
{
	if (denominator * numerator > 0) {
		m_numerator = abs(numerator);
		m_denominator = abs(denominator);
	} else {
		m_numerator = -abs(numerator);
		m_denominator = abs(denominator);
	}
	if (m_numerator != 0) {
		int gcd = get_gcd(abs(m_numerator), m_denominator);
		m_numerator /= gcd;
		m_denominator /= gcd;
	}
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
	while ((str[i++] != '.') && (i < str.length()));

	if (i < str.length()) {
		std::string tmp = str;
		tmp.erase(i - 1, str.length() - i + 1);
		std::stringstream ss;
		ss << tmp;
		// std::cout << "whole part is " << ss.str() << '\n';
		int whole;
		ss >> whole;

		str.erase(0, i - 1);
		str.insert(0, "0");
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
	} else {
		std::stringstream ss;
		ss << str;
		// std::cout << "whole part is " << ss.str() << '\n';
		int whole;
		ss >> whole;

		m_numerator = whole * sign;
		m_denominator = 1;
	}
}

Fraction Fraction::operator- ()
{
	return Fraction(-m_numerator, m_denominator);
}

Fraction Fraction::operator+ (const Fraction &a)
{
	int numerator = m_numerator * a.m_denominator + a.m_numerator * m_denominator;
	int denominator = m_denominator * a.m_denominator;
	if (numerator != 0) {
		int gcd = get_gcd(abs(numerator), denominator);
		numerator /= gcd;
		denominator /= gcd;
	}
	return Fraction(numerator, denominator);
}

Fraction Fraction::operator- (const Fraction &a)
{
	int numerator = m_numerator * a.m_denominator - a.m_numerator * m_denominator;
	int denominator = m_denominator * a.m_denominator;
	if (numerator != 0) {
		int gcd = get_gcd(abs(numerator), denominator);
		numerator /= gcd;
		denominator /= gcd;
	}
	return Fraction(numerator, denominator);
}

Fraction Fraction::operator* (const Fraction &a)
{
	return Fraction(m_numerator * a.m_numerator, m_denominator * a.m_denominator);
}

Fraction Fraction::operator/ (const Fraction &a)
{
	if (a.m_numerator == 0) {
		std::cout << "ERROR: division by zero" << std::endl;
		return Fraction(0, 1);
	} else {
		return Fraction(m_numerator * a.m_denominator, m_denominator * a.m_numerator);
	}
}

Fraction Fraction::operator= (const Fraction &a)
{
	m_numerator = a.m_numerator;
	m_denominator = a.m_denominator;
	return *this;
}


std::ostream &operator<< (std::ostream &output, const Fraction &a)
{
	return output << a.m_numerator << '/' << a.m_denominator;
}

std::istream &operator>> (std::istream &input, Fraction &a)
{
	std::string str;
	input >> str;
	a = Fraction(str);
	return input;
}

void Fraction::print ()
{
	std::cout << m_numerator << '/' << m_denominator;
}