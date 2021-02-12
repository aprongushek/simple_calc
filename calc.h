#pragma once

#include "fraction.h"
#include <string>

struct Node {
	Node *left;
	Node *right;

	char oper;
	Fraction value;
};

Node *create_tree (std::string str);
void destroy_tree (Node *node);