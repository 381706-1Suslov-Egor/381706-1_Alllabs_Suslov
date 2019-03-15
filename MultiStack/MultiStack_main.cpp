#include "MultiStack.h"
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "\t������� ���������� �� 2-� ������ �� 6 ��������� � ������:" << endl;
	int m = 1;
	try
	{
		TMStack<int> mst(2, 12);
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 6; j++)
			{
				mst.Set(i, m);
				cout << " >" << m++ << "< ������ " << i + 1 << " ����" << endl;
			}

		mst.PrintMStack();
		cout << "\n\n";

		for (int i = 0; i < 3; i++)
			cout << "����� ������� " << mst.Get(i) << " �� " << i + 1 << " �����" << endl;

		mst.PrintMStack();

		cout << "\n\n������  '5' �� 2-�� ����" << endl;
		mst.Set(1, 5);

		mst.PrintMStack();
		cout << "\n\n" << endl;
	}

	catch (MyException exp)
	{
		exp.Print();
	}

	return 0;


  return 0;
}