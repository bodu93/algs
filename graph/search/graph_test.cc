#include "graph.h"
//#include "gtest/gtest.h"

#include <fstream>
#include <iostream>

int main() {
	{
		std::ifstream in("../data/search.txt");
		if (!in.fail()) {
			graph g(in);
			g.bfs(2);
			std::cout << g << std::endl;
		}
	}
	endl(std::cout);
	endl(std::cout);
	{
		std::ifstream in("../data/search.txt");
		if (!in.fail()) {
			graph g(in);
			g.dfs(2);
			std::cout << g << std::endl;
		}
	}

	return 0;
}
