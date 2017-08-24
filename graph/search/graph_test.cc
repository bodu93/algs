#include "graph.h"
#include "gtest/gtest.h"

#include <fstream>
#include <iostream>

TEST(graph_test, test_bfs) {
	std::ifstream in("tinyG.txt");

	ASSERT_TRUE(in);

	graph g(in);
    EXPECT_EQ(8, g.V());
	EXPECT_EQ(9, g.E());

	g.bfs(2);

	//const vertex &n = g.node(0);
	//EXPECT_EQ(n.color, Color::eBlack);
	//EXPECT_EQ(n.d, 2);
	//EXPECT_EQ(n.p, 1);
	std::cout << std::endl << g << std::endl;
}

TEST(graph_test, test_dfs) {
	std::ifstream in("tinyG.txt");
	ASSERT_TRUE(in);

	graph g(in);

	g.dfs(2);
	std::cout << std::endl << g << std::endl;
}
