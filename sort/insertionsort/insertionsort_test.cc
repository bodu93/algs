#include "gtest/gtest.h"
#include "insertionsort.h"

#include <vector>

TEST(insertionsort_test, test1) {
	std::vector<int> vec{ 5, 4, 3, 2, 1 };

	std::vector<int> result{ 1, 2, 3, 4, 5 };
	//insertionsort_(&vec[0], 0, vec.size());
	insertionsort_improved(&vec[0], 0, vec.size());
	EXPECT_EQ(vec, result);
}

TEST(insertionsort_test, test2) {
	std::vector<int> vec{ 2, 4, 3, 1, 0, 5 };
	std::vector<int> result{ 0, 1, 2, 3, 4, 5 };
	insertionsort_improved(&vec[0], 0, vec.size());
	EXPECT_EQ(vec, result);
}
