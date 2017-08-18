#include "gtest/gtest.h"
#include "selectionsort.h"
#include "../include/utility.h"
#include <vector>

TEST(selectionsort_test, test1) {
	std::vector<int> vec{ 5, 4, 3, 2, 1 }; 	
	selectionsort(&vec[0], vec.size());

	EXPECT_TRUE(isSorted(&vec[0], vec.size()));
}
