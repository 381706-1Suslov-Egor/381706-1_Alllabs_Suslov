#include "gtest.h"
#include "StackList.h"

TEST(TStackList, can_create_stack_by_default)
{
  ASSERT_NO_THROW(TStackList<int> A);
}

TEST(TStackList, can_create_create_with_specified_size)
{
  ASSERT_NO_THROW(TStackList<int> A(3));
}

TEST(TStackList, can_create_create_with_negative_size)
{
  ASSERT_ANY_THROW(TStackList<int> A(-1));
}

TEST(TStackList, can_create_copy)
{
  TStackList<int> S(1);
  ASSERT_NO_THROW(TStackList<int> A(S));
}

TEST(TStackList, can_get_max_size)
{
  TStackList<int> S(40);
  ASSERT_EQ(S.GetMaxSize(), 40);
}

TEST(TStackList, can_get_size)
{
  TStackList<int> S(3);
  S.Put(1);
  S.Put(2);
  ASSERT_EQ(S.GetSize(), 2);
}

TEST(TStackList, can_put)
{
  TStackList<int> A;

  ASSERT_NO_THROW(A.PutBegin(100));
}

TEST(TStackList, throws_when_in_full_stack_put_elem)
{
  TStackList<int> S(1);
  S.Put(2);
  ASSERT_ANY_THROW(S.Put(5));
}

TEST(TStackList, can_get_elem)
{
  TStackList<int> A;
  A.Put(4);
  EXPECT_EQ(4, A.Get());
}

TEST(TStackList, throws_when_from_empty_stack_get_elem)
{
  TStackList <int> S(5);
  ASSERT_ANY_THROW(S.Get());
}

TEST(TStackList, can_check_empty_true)
{
  TStackList<int> S(4);
  ASSERT_TRUE(S.IsEmpty());
}
TEST(TStackList, can_check_empty_false)
{
	TStackList<int> S(1);
	S.Put(4);
	ASSERT_FALSE(S.IsEmpty());
}

TEST(TStackList, can_print_empty)
{
  TStackList<int> S(4);
  ASSERT_ANY_THROW(S.Print());
}



TEST(TStackList, true_the_sequence_of_output_after_put_zapolneniya)
{
  TStackList<int> S(3);
  S.Put(1), S.Put(2), S.Put(3);
  ASSERT_EQ(S.Get(), 3);
  ASSERT_EQ(S.Get(), 2);
  ASSERT_EQ(S.Get(), 1);
}
TEST(StackList, throws_when_create_stack_with_negative_size)
{
	ASSERT_ANY_THROW(TStackList <int> S(-1));
}


TEST(StackList, can_put_and_get)
{
	TStackList <int> S(2);
	S.Put(2);
	ASSERT_EQ(2, S.Get());
}

TEST(StackList, can_checking_is_full_false)
{
	TStackList <int> S(1);
	ASSERT_FALSE(S.IsFull());
}

TEST(StackList, can_checking_is_full_true)
{
	TStackList <int> S(1);
	S.Put(5);
	ASSERT_TRUE(S.IsFull());
}

TEST(StackList, can_checking_is_empty_false)
{
	TStackList <int> S(1);
	S.Put(5);
	ASSERT_FALSE(S.IsEmpty());
}

TEST(StackList, can_checking_is_empty_true)
{
	TStackList <int> S(1);
	ASSERT_TRUE(S.IsEmpty());
}

TEST(Stack, throws_stack_overflow)
{
	TStackList <int> S(1);
	S.Put(2);
	ASSERT_ANY_THROW(S.Put(5));
}

TEST(StackList, throws_taking_an_item_from_an_empty_stack)
{
	TStackList <int> S(1);
	ASSERT_ANY_THROW(S.Get());
}