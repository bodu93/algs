#include "scc.h"
#include <fstream>
#include <iostream>

int main() {
	std::ifstream in("../data/scc.txt");
	if (!in.fail()) {
		dag g{in};
		SCC scc{g};

		std::cout << scc.count() << std::endl;
		std::cout << scc.id(1) << std::endl;
		std::cout << scc.id(4) << std::endl;

		std::cout << scc.stronglyConnected(1, 4) << std::endl;
		std::cout << scc.stronglyConnected(0, 2) << std::endl;
	}

	return 0;
}
