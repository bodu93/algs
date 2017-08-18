#include "mergesort.h"
#include "../include/utility.h"
#include "gtest/gtest.h"
#include <vector>

TEST(mergersorttest, test1) {
	std::vector<int> vec { 1, 4, 3, 0, 9, 9, -9 };
	mergesort(&vec[0], vec.size());
	
	EXPECT_TRUE(isSorted(&vec[0], vec.size()));
}
