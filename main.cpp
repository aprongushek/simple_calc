#include "fraction.h"
#include "calc.h"
#include <iostream>
#include <string>

int main ()
{
	// Fraction fraction1(1, -5);
	// Fraction fraction2(0);

	// // std::cin >> fraction1 >> fraction2;

	// Fraction res(0, 1);

	// res = fraction1 / fraction2;
	// std::cout << res;

	std::string str;
	std::cin >> str;
	Node *root = create_tree(str);

	destroy_tree(root);

	return 0;
}