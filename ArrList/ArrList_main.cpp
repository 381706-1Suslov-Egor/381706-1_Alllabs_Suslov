#include "ArrList.h"

int main()
{
  cout << "An example of using the ArrList will be implemented here" << endl;
  cout << "Enter size list: ";
  int n;
  cin >> n;
  cout << endl;
  try
  {
    TArrList<int> List(n);
    int i;
    for (i = 1; i <= n / 2; i++)
    {
      cout << "Put start: " << i << endl;
      List.PutStart(i);
    }
    for (i; i <= n; i++)
    {
      cout << "Put end: " << i << endl;
      List.PutEnd(i);
    }

    cout << "\n\nList create" << endl;
    List.Print();
    cout << "\n\n";


    for (i = 1; i <= n / 2; i++)
      cout << "Get start: " << List.GetStart() << endl;
    for (i; i <= n; i++)
      cout << "Get end: " << List.GetEnd() << endl;
  }

  catch (MyException exp)
  {
    exp.Print();
  }

  return 0;
}
