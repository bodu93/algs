/*
 * Stack Permutation
 */

#include <stack>
#include <vector>
#include <iostream>

bool isStackPermutation(
		const std::vector<int>& input,
		const std::vector<int>& output) {
	std::stack<int> in_stack;
	for (std::vector<int>::const_reverse_iterator it = input.rbegin();
			 it != input.rend();
			 ++it) {
		in_stack.push(*it);
	}

	bool result = true;

	std::stack<int> relay_stack;
	size_t output_rank = 0;
	while (output_rank < output.size()) {
		if (relay_stack.empty() ||
				output[output_rank] != relay_stack.top()) {
			if (in_stack.empty()) {
				result = false;
				break;
			}
			relay_stack.push(in_stack.top());
			in_stack.pop();
		} else {
			++output_rank;
			relay_stack.pop();
		}
	}

	return result;
}

int main() {
	bool r = isStackPermutation({1, 2, 3}, {3, 2, 1});
	std::cout << r << std::endl;
	return 0;
}
