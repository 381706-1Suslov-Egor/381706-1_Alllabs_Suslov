#include <gtest.h>
#include "ArrList.h"

TEST(ArrList, can_create_list_by_default)
{
  ASSERT_NO_THROW(TArrList <int> L());
}

TEST(ArrList, can_create_list_int_with_specified_size)
{
  ASSERT_NO_THROW(TArrList <int> L(5));
}
TEST(ArrList, can_create_double_list_with_specified_size)
{
	TArrList <double> L(5);
	ASSERT_NO_THROW(TArrList <double> L(5));
}


TEST(ArrList, can_create_copy_list)
{
  TArrList <int> L1;
  L1.PutStart(1);
  TArrList <int> L2(L1);
  ASSERT_EQ(L1.GetStart(), L2.GetStart());
}



TEST(ArrList, throws_when_create_list_with_zero_size)
{
  ASSERT_ANY_THROW(TArrList <int> L(0));
}

TEST(ArrList, throws_when_create_list_with_negative_size)
{
  ASSERT_ANY_THROW(TArrList <int> L(-1));
}


TEST(ArrList, can_get_and_put_start)
{
  TArrList <int> L(2);
  L.PutStart(1);
  L.PutStart(2);
  ASSERT_EQ(2, L.GetStart());
  ASSERT_EQ(1, L.GetStart());
}

TEST(ArrList, can_put_and_get_end)
{
  TArrList <int> L(2);
  L.PutEnd(1);
  L.PutEnd(2);
  ASSERT_EQ(2, L.GetEnd());
  ASSERT_EQ(1, L.GetEnd());
}

TEST(ArrList, can_use_check_full_false)
{
  TArrList <int> L(1);
  ASSERT_FALSE(L.IsFull());
}

TEST(ArrList, can_use_check_full_true)
{
  TArrList <int> L(1);
  L.PutStart(1);
  ASSERT_TRUE(L.IsFull());
}

TEST(ArrList, can_use_check_empty_false)
{
  TArrList <int> L(1);
  L.PutStart(1);
  ASSERT_FALSE(L.IsEmpty());
}

TEST(ArrList, can_use_check_empty_true)
{
  TArrList <int> L(1);
  ASSERT_TRUE(L.IsEmpty());
}

TEST(ArrList, throws_when_in_full_list_put_start_elem)
{
  TArrList <int> L(1);
  L.PutStart(1);
  ASSERT_ANY_THROW(L.PutStart(2));
}


TEST(ArrList, throws_when_in_full_list_put_end_elem)
{
  TArrList <int> L(1);
  L.PutEnd(1);
  ASSERT_ANY_THROW(L.PutEnd(2));
}

TEST(ArrList, throws_when_in_empty_list_get_start_elem)
{
  TArrList <int> L(1);
  ASSERT_ANY_THROW(L.GetStart());
}

TEST(ArrList, throws_when_in_empty_list_get_end_elem)
{
  TArrList <int> L(1);
  ASSERT_ANY_THROW(L.GetEnd());
}

/*TEST(ArrList, true_the_sequence_of_output_after_put_end_zapolneniya)
{
	TArrList <int> L(4);
	L.PutStart(1);
	L.PutStart(2);
	L.PutStart(3);
	L.PutStart(4); //  4 3 2 1 
	ASSERT_EQ(1, L.GetEnd());
	ASSERT_EQ(2, L.GetEnd());
	ASSERT_EQ(3, L.GetEnd());
	ASSERT_EQ(4, L.GetEnd());
}*/
TEST(ArrList, true_the_sequence_of_output_after_put_start_zapolneniya)
{
	TArrList <int> L(4);
	L.PutEnd(4);
	L.PutEnd(3);
	L.PutEnd(2);
	L.PutEnd(1); //  4 3 2 1 
	ASSERT_EQ(1, L.GetEnd());     
	ASSERT_EQ(2, L.GetEnd());     
	ASSERT_EQ(3, L.GetEnd());
	ASSERT_EQ(4, L.GetEnd());     
}
TEST(ArrList, true_the_sequence_of_output_after_put_start_and_end_zapolneniya)
{
	TArrList <int> L(4);
	L.PutStart(1); 
	L.PutEnd(2);   
	L.PutStart(3); 
	L.PutEnd(4);   // 3 1 2 4
	   
	ASSERT_EQ(3, L.GetStart());   // 1 2 4
	ASSERT_EQ(4, L.GetEnd());     // 1 2
	ASSERT_EQ(1, L.GetStart());   // 2
	ASSERT_EQ(2, L.GetEnd());     // empty
}
TEST(ArrList, throws_when_in_empty_list_get_elem)
{
  TArrList <int> L(3);
  ASSERT_ANY_THROW(L.Get(2));
}

TEST(ArrList, throws_when_in_full_list_put_elem)
{
  TArrList <int> L(3);
  L.PutEnd(1);
  L.PutEnd(40);
  L.PutEnd(3);

  ASSERT_ANY_THROW(L.Put(2, 2));
}

TEST(ArrList, throws_when_incurrent_index_when_list_put_elem)
{
  TArrList <int> L(4);
  L.PutEnd(1);
  L.PutEnd(1);
  L.PutEnd(1);

  ASSERT_ANY_THROW(L.Put(3,3 ));
}
TEST(ArrList, can_get_elem)
{
	TArrList <int> L(3);
	L.PutEnd(1);
	L.PutEnd(2);
	L.PutEnd(3);

	ASSERT_EQ(L.Get(1), 2);
}

TEST(ArrList, can_put_elem)
{
	TArrList <int> L(4);
	L.PutEnd(1);
	L.PutEnd(2);
	L.PutEnd(3);
	L.Put(2, 10);

	ASSERT_EQ(L.Get(1), 2);
	ASSERT_EQ(L.Get(1), 10);
}
TEST(ArrList, throws_when_incurrent_index_when_list_get_elem)
{
  TArrList <int> L(3);
  L.PutEnd(1);
  L.PutEnd(1);
  L.PutEnd(1);

  ASSERT_ANY_THROW(L.Get(10));
}

