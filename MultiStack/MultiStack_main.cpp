#include "MultiStack.h"
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "\tСоздаем мультистек из 2-х стеков по 6 элементов в каждом:" << endl;
	int m = 1;
	try
	{
		TMStack<int> mst(2, 12);
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 6; j++)
			{
				mst.Set(i, m);
				cout << " >" << m++ << "< кладем " << i + 1 << " стек" << endl;
			}

		mst.PrintMStack();
		cout << "\n\n";

		for (int i = 0; i < 3; i++)
			cout << "берем элемент " << mst.Get(i) << " из " << i + 1 << " стека" << endl;

		mst.PrintMStack();

		cout << "\n\nкладем  '5' во 2-ой стек" << endl;
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