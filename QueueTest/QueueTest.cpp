#include "Queue.h"
#include <gtest.h>

TEST(Queue, throws_when_create_queue_with_negative_size)
{
  ASSERT_ANY_THROW(TQueue<int> V(-1));
}

TEST(Queue, can_put_and_get)
{
  TQueue <int> Q(1);
  Q.Put(3);
  ASSERT_EQ(3, Q.Get());
}

TEST(Queue, can_use_full_check_false)
{
  TQueue <int> Q(1);
  ASSERT_FALSE(Q.IsFull());
}

TEST(Queue, can_use_full_check_true)
{
  TQueue <int> Q(1);
  Q.Put(2);
  ASSERT_TRUE(Q.IsFull());
}

TEST(Queue, can_use_empty_check_false)
{
  TQueue <int> Q(1);
  Q.Put(3);
  ASSERT_FALSE(Q.IsEmpty());
}

TEST(Queue, can_use_empty_check_true)
{
  TQueue <int> Q(1);
  ASSERT_TRUE(Q.IsEmpty());
}

TEST(Queue, throw_get_when_is_empty)
{
  TQueue <int> Q(1);
  ASSERT_ANY_THROW(Q.Get());
}

TEST(Queue, throw_put_when_is_full)
{
  TQueue <int> Q(1);
  Q.Put(1);
  ASSERT_ANY_THROW(Q.Put(2));
}

TEST(tqueue, cant_put_element_in_full_queue)
{
	TQueue <int>  q(5);
	for (int i = 0; i < 5; i++)
		q.Put(i);

	ASSERT_ANY_THROW(q.Put(6));
}

TEST(Queue, Order_output)
{
  TQueue<int> S(2);
  S.Put(1), S.Put(2);
  ASSERT_EQ(S.Get(), 1);
  ASSERT_EQ(S.Get(), 2);
  
}


