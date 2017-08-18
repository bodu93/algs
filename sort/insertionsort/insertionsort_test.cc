#include "gtest/gtest.h"
#include "insertionsort.h"
#include "../include/utility.h"
#include <vector>

TEST(insertionsort_test, test1) {
	std::vector<int> vec{ 5, 4, 3, 2, 1 };
	//insertionsort_(&vec[0], 0, vec.size());
	insertionsort_improved(&vec[0], 0, vec.size());

	EXPECT_TRUE(isSorted(&vec[0], vec.size()));
}

TEST(insertionsort_test, test2) {
	std::vector<int> vec{ 2, 4, 3, 1, 0, 5 };
	insertionsort_improved(&vec[0], 0, vec.size());

	EXPECT_TRUE(isSorted(&vec[0], vec.size()));
}
