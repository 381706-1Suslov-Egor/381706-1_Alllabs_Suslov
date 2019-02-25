#include "Polish.h"
#include <conio.h>
int  main()
{
  try
  {
	  setlocale(LC_ALL, "rus");
    cout << "¬ведите пример с математичесскими операторами: ";
    TString s;
    cin >> s;
    cout << s << " -> ";
    TQueue<char> B;
    B = ConvertToPol(s);
	cout << "¬аш пример в обратной польской записи: ";
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
