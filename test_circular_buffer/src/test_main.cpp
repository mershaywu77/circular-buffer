/*
 * test_main.cpp
 *
 *  Created on: 25 Oct 2016
 *      Author: 224474
 */
#include "gtest/gtest.h"
#include "../../circular_buffer.h"

GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from gtest_main.cc\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(CircularBuffer_test, Positive)
{
	CircularBuffer<int> int_ring_buffer;
	int count = 0;
	int_ring_buffer.push_back(0);
	int_ring_buffer.push_back(1);
	count = 2;
	for (int i = 0; i <4000; i++)
	{
		int_ring_buffer.push_back(count);
		EXPECT_EQ(count-2,int_ring_buffer.front());
		int_ring_buffer.pop_front();
		count++;
	}
}


