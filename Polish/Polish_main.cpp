#include "Polish.h"
#include <conio.h>
int  main()
{
  try
  {
	  setlocale(LC_ALL, "rus");
    cout << "������� ������ � ���������������� �����������: ";
    TString s;
    cin >> s;
    cout << s << " -> ";
    TQueue<char> B;
    B = ConvertToPol(s);
	cout << "��� ������ � �������� �������� ������: ";
    B.Print();
    cout << " = " << Rez(B) << endl;
	getch();
  }
  
  catch (MyException exp)
  {
    exp.Print();
  }
  return 0;
}
