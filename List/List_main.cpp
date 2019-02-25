#include "List.h"
int main()
{
  try
  {
	  setlocale(LC_ALL, "Russian");
    TList<int> list;
	int n = 5, k = 5;
    
    for (int i = 1; i <= n; i++)
      list.PutBegin(i);
    
    for (int i = 1; i <= k; i++)
      list.PutEnd(i);

    cout << "\n\nСписок:\n";
    list.Print();
	cout << "\n\nПервый вывод крайних элементов списка";
    cout << "\n\nElement first of the List: " << list.GetBegin();
    cout << "\nElement last of the List: " << list.GetEnd();
	cout << "\n\nВторой вывод крайних элементов списка";
	cout << "\n\nElement first of the List: " << list.GetBegin();
	cout << "\nElement last of the List: " << list.GetEnd();
    cout << "\n\nThe List is after:\n";
    list.Print();
  }

  catch (MyException exp)
  {
    exp.Print();
  }

  return 0;
}

