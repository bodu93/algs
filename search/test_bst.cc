#include "bst.h"
#include <string>

#include <iostream>

int main() {
	std::string s("searchexample");
	bs_tree<int, char> bt;

	size_t i = 0;
	for (auto e : s)
		bt.insert(i++, e);

	bs_tree<int, char> bt1(bt);
	bs_tree<int, char> bt2;
	bt2 = bt;

	bt.erase(0);
	auto func = [](bs_tree<int, char>::iterator it) {
		std::cout << it->Key() << ": " << it->Value() << std::endl;
	};
	bt.levelTraverse(func);
	bt.inorder_traverse(func);

	bt1.erase(3);
	bt2.erase(2);

	bt2.insert(2, 'o');

	return 0;
}
