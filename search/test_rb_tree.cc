#include "rb_tree.h"
#include <string>

#include <iostream>

int main() {
    rb_tree<int, char> rbt;

    std::string s("searchexample");
    for (size_t i = 0; i != s.size(); ++i)
        rbt.insert(static_cast<int>(i), s[i]);

		rb_tree<int, char> rbt_copy(rbt);
		rbt.erase(2);
		rbt_copy.LevelPrint();

		rb_tree<int, char> rbt_assign(rbt);
		rbt_assign.erase(0);
		rbt_assign.LevelPrint();

    return 0;
}
