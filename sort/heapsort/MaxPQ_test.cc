#include "utility/MaxPQ.h"
#include "gtest/gtest.h"

TEST(MaxPQtest, test1) {
	toys::utility::MaxPQ<int> mm;

	mm.insert(1);
	mm.insert(-1);
	mm.insert(4);
	mm.insert(2);

	EXPECT_EQ(4, mm.delMax());
	EXPECT_EQ(2, mm.delMax());
	EXPECT_EQ(1, mm.delMax());
	EXPECT_EQ(-1, mm.delMax());
	EXPECT_EQ(0, mm.delMax());
}
