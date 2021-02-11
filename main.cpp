#include "fraction.h"

int main ()
{
	Fraction fraction1(1, -5);
	Fraction fraction2(2, 3);

	// std::cin >> fraction1 >> fraction2;

	Fraction res(0, 1);

	res = fraction1 + fraction2;
	std::cout << fraction1;

	return 0;
}