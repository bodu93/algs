#include "heapsort.h"
#include "gtest/gtest.h"
#include "../include/utility.h"
#include <vector>

TEST(heapsorttest, test1) {
	std::vector<int> vec{ -1, 1, 3, -9, 0, 11, -4, 1 };
	heapsort(&vec[0], vec.size());
	
	EXPECT_TRUE(isSorted(&vec[0], vec.size()));
}

TEST(heapsorttest, test2) {
	std::vector<int> vec{ 1 };
	heapsort(&vec[0], vec.size());

	EXPECT_TRUE(isSorted(&vec[0], vec.size()));
}
