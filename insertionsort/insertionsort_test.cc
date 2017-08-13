#include "gtest/gtest.h"
#include "insertionsort.h"

#include <vector>

TEST(insertionsort_test, test1) {
	std::vector<int> vec{ 5, 4, 3, 2, 1 };

	std::vector<int> result{ 1, 2, 3, 4, 5 };
	insertionsort_(&vec[0], 0, vec.size());
	EXPECT_EQ(vec, result);
}
