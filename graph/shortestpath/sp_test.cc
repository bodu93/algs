#include "weighted_dag.h"
#include "shortestpath.h"
#include "gtest/gtest.h"

#include <fstream>
#include <iostream>

TEST(sp_test, dijkstra) {	
	std::ifstream in("../data/sp.txt");
	if (!in.fail()) {
		weighted_dag g{in};

		ShortestPath sp(g);

		for (auto i : sp.dijkstra(0))
			std::cout << i << std::endl;
	}
}

TEST(sp_test, bellman_ford) {
	std::ifstream in("../data/sp.txt");
	if (!in.fail()) {
		weighted_dag g{in};

		ShortestPath sp(g);
		sp.bellman_ford(0);
		std::cout << sp << std::endl;
	}
}
