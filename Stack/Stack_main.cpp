#include "Stack.h"


int main()
{
 
	try
	{
		TStack<int> st(5);
		for (int i = 0; i < 5; i++)
		{
			cout << i;
			cout << " number in stack ";
			int l;
			cin >> l;
			cout << endl;
			st.Put(l);
		}
		cout << endl;
		st.PrintStack();
		cout << endl;
		
	}
  catch (MyException exp)
  {
    exp.Print();
  }
  return 0;
}