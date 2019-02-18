#include "Stack.h"
#include <gtest.h>

TEST(Stack, throws_when_create_stack_with_negative_size)
{
  ASSERT_ANY_THROW(TStack <int> S(-1));
}

TEST(Stack, can_put_and_get)
{
  TStack <int> S(2);
  S.Put(2);
  ASSERT_EQ(2, S.Get());
}

TEST(Stack, can_checking_is_full_false)
{
  TStack <int> S(1);
  ASSERT_FALSE(S.IsFull());
}

TEST(Stack, can_checking_is_full_true)
{
  TStack <int> S(1);
  S.Put(5);
  ASSERT_TRUE(S.IsFull());
}

TEST(Stack, can_checking_is_empty_false)
{
  TStack <int> S(1);
  S.Put(5);
  ASSERT_FALSE(S.IsEmpty());
}

TEST(Stack, can_checking_is_empty_true)
{
  TStack <int> S(1);
  ASSERT_TRUE(S.IsEmpty());
}

TEST(Stack, throws_stack_overflow)
{
  TStack <int> S(1);
  S.Put(2);
  ASSERT_ANY_THROW(S.Put(5));
}

TEST(Stack, throws_taking_an_item_from_an_empty_stack)
{
  TStack <int> S(1);
  ASSERT_ANY_THROW(S.Get());
}

TEST(Stack, compare_true)
{
  TStack <int> S1(1), S2(1);
  S1.Put(1);
  S2.Put(1);
  ASSERT_TRUE(S1 == S2);
}

TEST(Stack, compare_false)
{
  TStack <int> S1(1), S2(1);
  S1.Put(1);
  S2.Put(2);
  ASSERT_FALSE(S1 == S2);
}

TEST(Stack, compare_when_different_size)
{
  TStack <int> S1(1), S2(2);
  ASSERT_FALSE(S1 == S2);
}

TEST(Stack, compare_false_when_different_top_and_element)
{
  TStack <int> S1(3), S2(3);
  S1.Put(1);
  S2.Put(1), S2.Put(2);
  ASSERT_FALSE(S1 == S2);
}

TEST(Stack, uncompare_false)
{
  TStack <int> S1(1), S2(1);
  S1.Put(1);
  S2.Put(1);
  ASSERT_FALSE(S1 != S2);
}

TEST(Stack, uncompare_true)
{
  TStack <int> S1(1), S2(1);
  S1.Put(1);
  S2.Put(2);
  ASSERT_TRUE(S1 != S2);
}

TEST(Stack, uncompare_when_different_size)
{
  TStack <int> S1(1), S2(3);
  ASSERT_TRUE(S1 != S2);
}

TEST(Stack, uncompare_when_dif_top__top_and_element_false)
{
  TStack <int> S1(3), S2(3);
  S1.Put(1);
  S2.Put(1), S2.Put(2);
  ASSERT_TRUE(S1 != S2);
}

TEST(Stack, assignment)
{
  TStack <int> S1(1), S2(2);
  S2.Put(1), S2.Put(2);
  S1 = S2;
  ASSERT_TRUE(S2 == S1);
}

TEST(Stack, Order_output)
{
  TStack <int> S(3);
  S.Put(3), S.Put(2), S.Put(1);
  ASSERT_EQ(S.Get(), 1);
  ASSERT_EQ(S.Get(), 2);
  ASSERT_EQ(S.Get(), 3);
}
