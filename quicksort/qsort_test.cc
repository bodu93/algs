#include "quicksort.h"
#include "gtest/gtest.h"

TEST(qsort_test, test1) {
	std::vector<int> vec{ 5, 4, 3, 2, 1 };
	
	qsort_(&vec[0], vec.size());
	std::vector<int> results{ 1, 2, 3, 4, 5 };
	EXPECT_EQ(vec, results);
}
