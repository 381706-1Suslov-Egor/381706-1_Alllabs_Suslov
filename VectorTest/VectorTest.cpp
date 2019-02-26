#include "Vector.h"
#include <gtest.h>

TEST(Vector, throw_negative_size)
{
  ASSERT_ANY_THROW(TVector<int> V(-1));
}

TEST(Vector, check_copy_at_creation)
{
  TVector <int> V1(3);
  for (int i = 0; i < 3; i++)
  {
	  V1[i] = i;
 }
  TVector <int> V2(V1);
  ASSERT_TRUE(V2 == V1);
}
TEST(Vector, check_copy_through_equally_and_with_different_size_vector)
{
	TVector <int> V1(3), V2(4);
	for (int i = 0; i < 4; i++)
	{
		V2[i] = i;
	}
	V1 = V2;
	ASSERT_TRUE(V1 == V2);
}

TEST(Vector, can_get_size)
{
  TVector <int> V(4);
  ASSERT_EQ(4, V.GetSize());
}

TEST(Vector, thorws_index_argument_is_negative)
{
  TVector <int> V(3);
  ASSERT_ANY_THROW(V[-4]);
}

TEST(Vector, thorws_index_argument_many_sizes)
{
  TVector <int> V(3);
  ASSERT_ANY_THROW(V[100]);
}

TEST(Vector, can_use_index_operator)
{
  TVector <int> V(3);
  V[0] = 2;
  int temp = V[0] + 5;
  ASSERT_EQ(7, temp);
}

TEST(Vector, can_compare_vectors_true)
{
  TVector <int> V1(3), V2(3);
  for (int i = 0; i < 3; i++) {
    V1[i] = i;
    V2[i] = i;
  }
  ASSERT_TRUE(V1 == V2);
}

TEST(Vector, can_compare_vectors_false)
{
  TVector <int> V1(3), V2(3);
  for (int i = 0; i < 3; i++) {
    V1[i] = i;
    V2[i] = i+1;
  }
  ASSERT_FALSE(V1 == V2);
}

TEST(Vector, can_compare_vectors_with_various_size_false)
{
  TVector <int> V1(2), V2(3);
  ASSERT_EQ(0, V1 == V2);
}

TEST(Vector, can_use_the_denial_of_equality_for_vectors_with_equal_values)
{
  TVector <int> V1(3), V2(3);
  for (int i = 0; i < V1.GetSize(); i++) {
    V1[i] = i;
    V2[i] = i;
  }
  ASSERT_FALSE(V1 != V2);
}

TEST(Vector, can_use_the_denial_of_equality_for_vectors_with_different_values)
{
  TVector <int> V1(3), V2(3);
  for (int i = 0; i < 3; i++) {
    V1[i] = i;
    V2[i] = i + 1;
  }
  ASSERT_TRUE(V1 != V2);
}

TEST(Vector, can_use_the_denial_of_equality_for_vectors_with_different_size)
{
  TVector <int> V1(3), V2(4);
  ASSERT_TRUE(V1 != V2);
}



TEST(Vector, can_plus_number)
{
  TVector <int> V1(3), V2(3);
  V1 = V1 + 1;
  V2 = V1 + 2;
  ASSERT_FALSE(V1 == V2);
  V1 = V1 + 2;
  ASSERT_TRUE(V1 == V2);
}

TEST(Vector, can_minus_number)
{
  TVector <int> V1(3), V2(3);
  V1 = V1 - 1;
  V2 = V1 - 1;
  ASSERT_FALSE(V1 == V2);
  V1 = V1 - 1;
  ASSERT_TRUE(V1 == V2);
}

TEST(Vector, can_multiply_by_number)
{
  TVector <int> V1(3);
  V1 = V1 + 1;
  V1 = V1 * 2; 
  int temp = V1[0] + V1[1] + V1[2];
  ASSERT_TRUE(temp == 6);
}

TEST(Vector, can_summation_vectors)
{
  TVector <int> V1(3), V2(3), Temp(3);
  for (int i = 0; i < V1.GetSize(); i++) {
    V1[i] = i;
    V2[i] = i + 1;
    Temp[i] = V1[i] + V2[i];
  }
  ASSERT_TRUE(Temp == (V1 + V2));
}

TEST(Vector, thorws_when_summation_vectors_with_different_size)
{
  TVector <int> V1(2), V2(3);
  ASSERT_ANY_THROW(V1 + V2);
}

TEST(Vector, can_subtraction_vectors)
{
  TVector <int> V1(2), V2(2), Temp(2);
  for (int i = 0; i < V1.GetSize(); i++) {
    V1[i] = i;
    V2[i] = i + 1;
    Temp[i] = V2[i] - V1[i];
  }
  ASSERT_TRUE(Temp == (V2 - V1));
}

TEST(Vector, thorws_when_subtraction_vectors_with_different_size)
{
  TVector <int> V1(2), V2(3);
  ASSERT_ANY_THROW(V1 - V2);
}

TEST(Vector, can_multiplication_vectors)
{
  TVector <int> V1(3), V2(3);
  int temp = 0;
  for (int i = 0; i < 3; i++) {
    V1[i] = i;
    V2[i] = i + 1;
    temp += i * (i + 1);
  }
  ASSERT_EQ(temp, V1*V2);
}

TEST(Vector, throws_multiplication_vectors_with_different_size)
{
  TVector <int> V1(1), V2(3);
  ASSERT_ANY_THROW(V1*V2);
}
TEST(Vector, can_do_multiple_operations_at_once)
{
	TVector <int> V1(3), V2(3), Temp(3);
	V1 = V1 + 1;
	V2 = V2 + 2;
	Temp = (V1 + 1)*V2;
	ASSERT_EQ(Temp, (V1 + 1)*V2);
}