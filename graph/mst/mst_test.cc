#include "graph.h"
#include "kruskal.h"
#include "prim.h"
#include "gtest/gtest.h"
#include <fstream>

TEST(mst_test, kruskal_test) {
	std::fstream in("../data/mst.txt");
	if (!in.fail()) {
		kruskal k{in};
		for (auto i : k.mst())
			std::cout << i << std::endl;
	}
}

TEST(mst_test, prim_test) {
	std::fstream in("../data/mst.txt");
	if (!in.fail()) {
		graph g{in};

		//for (size_t i = 0; i != g.V(); ++i) {
		//	for (size_t j = 0; j != g.V(); ++j) {
		//		if (g.weight(i, j) != std::numeric_limits<double>::max())
		//			std::cout << g.weight(i, j) << " ";
		//		else
		//			std::cout << 0 << " ";
		//	}
		//	std::cout << std::endl;
		//}

		prim p{g};
		p.mst(0);
		for (auto i : p.mst(0))
			std::cout << i << std::endl;
	}
}
