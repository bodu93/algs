#include "quicksort.h"
#include "gtest/gtest.h"
#include "../include/utility.h"

TEST(qsort_test, test1) {
	std::vector<int> vec{ 5, 4, 3, 2, 1 };
	qsort_(&vec[0], vec.size());
	
	EXPECT_TRUE(isSorted(&vec[0], vec.size()));
}
