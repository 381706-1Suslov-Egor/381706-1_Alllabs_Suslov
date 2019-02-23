#include "Stack.h"


int main()
{
 
	try
	{
		TStack<int> st(5);
		for (int i = 0; i < 5; i++)
		{
			
			st.Put(i);
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