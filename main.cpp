#include "fraction.h"

int main ()
{
	Fraction fraction1;
	Fraction fraction2;

	std::cin >> fraction1 >> fraction2;

	Fraction res(0, 1);

	res = fraction1 + fraction2;
	std::cout << res;

	return 0;
}