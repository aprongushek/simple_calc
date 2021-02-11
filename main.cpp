#include "fraction.h"

int main ()
{
	Fraction fraction1("1");
	Fraction fraction2(2, 1);

	Fraction res(0, 1);

	res = fraction1 * fraction2;
	res.print();

	return 0;
}