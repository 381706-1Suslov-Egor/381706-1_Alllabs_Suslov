#include "List.h"
#include <gtest.h>
TEST(Elem, can_create_elem)
{
	ASSERT_NO_THROW(TElem<int> elem);
}
TEST(Elem, can_create_elem_by_default)
{
	TElem<int> elem;

	ASSERT_EQ(elem.GetData(), 0);
}

TEST(Elem, can_copy_elem)
{
	TElem<int> elem1(1, 0);
	TElem<int> elem2(elem1);

	ASSERT_EQ(elem1.GetNext(), elem2.GetNext());
	ASSERT_EQ(elem1.GetData(), elem2.GetData());
}
TEST(Elem, can_get_data)
{
  TElem<int> elem(1, 0);
  ASSERT_EQ(elem.GetData(), 1);
}

TEST(Elem, can_get_next)
{
  TElem<int>* a = 0;
  TElem<int> elem(1, a);

  ASSERT_EQ(elem.GetNext(), a);
}

TEST(Elem, can_set_data)
{
  TElem<int> elem;
  elem.SetData(1);
  ASSERT_EQ(elem.GetData(), 1);
}

TEST(Elem, can_set_next_last)
{
  TElem<int>* a = 0;
  TElem<int> elem;
  elem.SetNext(a);

  ASSERT_EQ(elem.GetNext(), a);
}
TEST(Elem, can_set_next_not_the_last)
{
	TElem<int>* a = 0;
	TElem<int> elem1;
	elem1.SetNext(a);
	TElem<int> elem2;
	elem2.SetNext(&elem1);

	ASSERT_EQ(elem2.GetNext(), &elem1);
}//------------------------------------------

TEST(List, can_create_list)
{
	ASSERT_NO_THROW(TList<int> list);
}


TEST(List, can_check_empty_true)
{
  TList<int> list;

  ASSERT_TRUE(list.IsEmpty());
}

TEST(List, can_check_empty_false)
{
  TList<int> list;
  list.PutBegin(1);

  ASSERT_FALSE(list.IsEmpty());
}

TEST(List, can_check_full)
{
  TList<int> list;
  ASSERT_FALSE(list.IsFull());
}

TEST(List, can_get_and_put_begin)
{
  TList<int> list;
  list.PutBegin(1);
  list.PutBegin(2);
  list.PutBegin(3);

  ASSERT_EQ(list.GetBegin(), 3);
  ASSERT_EQ(list.GetBegin(), 2);
  ASSERT_EQ(list.GetBegin(), 1);
}

TEST(List, can_get_end)
{
  TList<int> list;
  list.PutBegin(1);
  list.PutBegin(2);
  list.PutBegin(3);

  ASSERT_EQ(list.GetEnd(), 1);
}


TEST(List, can_copy_empty_list)
{
  TList<int> list1;

  ASSERT_NO_THROW(TList<int> list2(list1));
}

TEST(List, can_copy_list)
{
	TList<int> list1;
	list1.PutEnd(1);
	list1.PutEnd(2);
	list1.PutEnd(3);
	TList<int> list2(list1);

	ASSERT_EQ(list1.GetBegin(), list2.GetBegin());
	ASSERT_EQ(list1.GetBegin(), list2.GetBegin());
	ASSERT_EQ(list1.GetBegin(), list2.GetBegin());
}

TEST(List, can_put_in_end)
{
  TList<int> list;
  list.PutEnd(1);
  list.PutEnd(2);
  list.PutEnd(3);

  ASSERT_EQ(list.GetBegin(), 1);
  ASSERT_EQ(list.GetBegin(), 2);
  ASSERT_EQ(list.GetBegin(), 3);
}

TEST(List, can_get_size)
{
  TList<int> list;
  list.PutBegin(1);
  list.PutBegin(2);
  list.PutBegin(3);

  ASSERT_EQ(list.GetSize(), 3);
}

TEST(List, can_get_zero_size)
{
  TList<int> list;

  ASSERT_EQ(list.GetSize(), 0);
}

TEST(List, throw_get_elem_to_index_when_list_is_empty)
{
  TList<int> list;

  ASSERT_ANY_THROW(list.Get(1));
}

TEST(List, throw_get_elem_to_incorrent_index)
{
  TList<int> list;
  list.PutBegin(1);

  ASSERT_ANY_THROW(list.Get(2));
}

TEST(List, can_get_elem_to_index)
{
  TList<int> list;
  list.PutBegin(1);
  list.PutBegin(2);
  list.PutBegin(3);

  ASSERT_EQ(list.Get(1), 2);
}

TEST(List, throw_put_elem_to_incorrent_index)
{
  TList<int> list;
  list.PutBegin(1);
  list.PutBegin(1);
  list.PutBegin(1);

  ASSERT_ANY_THROW(list.Put(0, 1));
  ASSERT_ANY_THROW(list.Put(3, 1));
}

TEST(List, can_put_elem_to_index)
{
  TList<int> list;
  list.PutEnd(1);
  list.PutEnd(2);
  list.PutEnd(3);
  list.Put(1, 10);

  ASSERT_EQ(list.Get(1), 10);
  ASSERT_EQ(list.Get(1), 2);
}

TEST(List, throw_get_begin_when_list_is_empty)
{
	TList<int> list;

	ASSERT_ANY_THROW(list.GetBegin());
	ASSERT_ANY_THROW(list.GetEnd());
}

TEST(List, throw_get_end_when_list_is_empty)
{
	TList<int> list;

	ASSERT_ANY_THROW(list.GetEnd());
}





