#include <gtest/gtest.h>
#include "Queue.h"

TEST(myQueue, can_create_empty_queue)
{
	MyQueue q;
	EXPECT_TRUE(q.empty());
}

TEST(myQueue, can_push_and_get_front_elem)
{
	MyQueue q;
	q.push(5);
	q.push(10);
	EXPECT_EQ(5, q.front());
}

TEST(myQueue, cannot_use_front_for_empty_queue)
{
	MyQueue q;
	EXPECT_ANY_THROW(q.front());
}

TEST(myQueue, can_push_and_get_back_elem)
{
	MyQueue q;
	q.push(5);
	q.push(10);
	EXPECT_EQ(10, q.back());
}

TEST(myQueue, cannot_use_back_for_empty_queue)
{
	MyQueue q;
	EXPECT_ANY_THROW(q.back());
}

TEST(myQueue, can_pop_and_empty_queue_test)
{
	MyQueue q;
	q.push(5);
	q.push(10);
	q.pop();
	q.pop();
	EXPECT_TRUE(q.empty());
}

TEST(myQueue, not_empty_queue_test)
{
	MyQueue q;
	q.push(5);
	q.push(10);
	q.pop();
	EXPECT_FALSE(q.empty());
}

TEST(myQueue, cannot_use_pop_for_empty_queue)
{
	MyQueue q;
	EXPECT_ANY_THROW(q.pop());
}

TEST(myQueue, correct_size)
{
	MyQueue q;
	q.push(5);
	q.push(10);
	EXPECT_EQ(2, q.size());
}

TEST(myQueue, correct_average_array_test_1)
{
	MyQueue q;
	const int w = 3;
	const int size = 5;
	int ar[size] = { 5,9,7,2,3 };
	float ex_ar[] = { 7,6,4 };

	float* res_ar = Avg_ar(w, ar, size);

	for (int i = 0; i < 3; ++i)
		EXPECT_EQ(res_ar[i], ex_ar[i]);
}

TEST(myQueue, correct_average_array_test_2)
{
	MyQueue q;
	const int w = 4;
	const int size = 7;
	int ar[size] = { 1,6,4,9,7,8,1 };
	float ex_ar[] = { 5, 6.5, 7, 6.25 };

	float* res_ar = Avg_ar(w, ar, size);

	for (int i = 0; i < 3; ++i)
		EXPECT_EQ(res_ar[i], ex_ar[i]);
}

TEST(myQueue, cannot_use_negative_window_size)
{
	MyQueue q;
	const int w = -1;
	const int size = 3;
	int ar[size] = { 1,2,3 };

	EXPECT_ANY_THROW(float* res_ar = Avg_ar(w, ar, size));
}

TEST(myQueue, cannot_use_zero_window_size)
{
	MyQueue q;
	const int w = 0;
	const int size = 3;
	int ar[size] = { 1,2,3 };

	EXPECT_ANY_THROW(float* res_ar = Avg_ar(w, ar, size));
}

TEST(myQueue, cannot_use_if_window_size_more_than_array_size)
{
	MyQueue q;
	const int w = 4;
	const int size = 3;
	int ar[size] = { 1,2,3 };

	EXPECT_ANY_THROW(float* res_ar = Avg_ar(w, ar, size));
}

int main(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}