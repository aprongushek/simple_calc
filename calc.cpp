#include "calc.h"

void fill_node (Node *node, char oper, int pos, std::string str);
void fill_node (Node *node, Fraction value);

Node *create_tree (std::string str)
{
	Node *node = new Node;

	for (int pass = 1; pass <= 3; pass++)
		for (int i = str.length(); i >= 0; i--) {
			switch (pass) {
				case 1:
					switch (str[i]) {
						case '+':
							fill_node(node, '+', i, str);
						return node;
						case '-':
							fill_node(node, '-', i, str);
						return node;
						case ')':
							while (str[--i] != '(');
						break;
					}
				break;
				case 2:
					switch (str[i]) {
						case '*':
							fill_node(node, '*', i, str);
						return node;
						case '/':
							fill_node(node, '/', i, str);
						return node;
						case ')':
							while (str[--i] != '(');
						break;
					}
				break;
				case 3:
					if (str[0] == '(') {
						str.erase(0, 1);
						str.erase(str.length() - 1, 1);
						delete node;
						return create_tree(str);
					} else {
						fill_node(node, Fraction(str));
						return node;
					}
				break;
			}
		}
	return nullptr;
}

void destroy_tree (Node *node)
{
	if (node->left != nullptr)
		destroy_tree(node->left);
	if (node->right != nullptr)
		destroy_tree(node->right);
	// if (node->oper != 0) {
	// 	std::cout << node->oper << ' ';
	// } else {
	// 	std::cout << node->value << ' ';
	// }
	delete node;
}

Fraction compute(Node *node)
{
	if (node->oper == 0) 
		return node->value;
	else 
		switch (node->oper) {
			case '+':
			return compute(node->left) + compute(node->right);
			case '-':
			return compute(node->left) - compute(node->right);
			case '*':
			return compute(node->left) * compute(node->right);
			case '/':
			return compute(node->left) / compute(node->right);
		}
	return Fraction(0);
}

void fill_node (Node *node, char oper, int pos, std::string str)
{
	node->oper = oper;
	node->value = Fraction(0);

	std::string l_str = str;
	l_str.erase(pos, l_str.length() - pos);
	if (l_str.length() == 0 && (oper == '+' || oper == '-')) {
		node->left = new Node;
		fill_node(node->left, Fraction(0));
	} else {
		node->left = create_tree(l_str);
	}

	str.erase(0, pos + 1);
	node->right = create_tree(str);

	// std::cout << l_str << ' ' << str << '\n';
}

void fill_node (Node *node, Fraction value)
{
	node->left = nullptr;
	node->right = nullptr;
	node->value = value;
	node->oper = 0;

	// std::cout << value << '\n';
}