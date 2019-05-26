#include "TScanTable.h"
#include "TRecord.h"
#include <string>
#include <iostream>
#include <locale>

using namespace std;

int main()
{
  setlocale (LC_ALL, "Russian");
  TRecord<int> e1("A", 35), e2("B", 17), e3("C", 45), e4(e1), e5;
  TScanTable<int> t1(10);
	cout << "��������� ��� ������" << endl;
  t1.Insert(e1);
  t1.Insert(e2);
	cout << "���� ����������� ������  " << t1.Find("A") << endl;
	cout << "������� ��������� ������" << endl;
	t1.Delete("A");
	cout << "���� �������� ������  " << t1.Find("A") << endl;
	return 0;
}
