#include "gtest/gtest.h"
#include "selectionsort.h"

#include <vector>
TEST(selectionsort_test, test1) {
	std::vector<int> vec{ 5, 4, 3, 2, 1 }; 	

	std::vector<int> result { 1, 2, 3, 4, 5 };
	selectionsort(&vec[0], vec.size());

	EXPECT_EQ(vec, result);
}
