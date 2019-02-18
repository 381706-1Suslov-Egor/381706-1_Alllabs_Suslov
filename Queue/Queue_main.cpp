#include "Queue.h"

int main()
{
  setlocale(LC_ALL, "Russian");
  int n;
  cin >> n;
  try
  {
	  TQueue<int> q(n);
	  for (int i = 0; i < n; i++)
	  {
		  q.Put(i);
		  cout << "Put " << i << endl;
	  }

  }
  catch (MyException exp)
  {
    exp.Print();
  }
    return 0;
  }
