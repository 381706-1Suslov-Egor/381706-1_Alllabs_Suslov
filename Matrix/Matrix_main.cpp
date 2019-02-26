#include "Matrix.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	TMatrix <int> M1(3), M2(3), M3(3);
	
	cout << "Первая матрица  " << endl << M1 << endl << endl;
	cout << "Вторая матрица  " << endl << M2 << endl << endl;
	cout << "Вторая матрица * Первая матрица  " << endl  << M1 * M2 << endl << endl;
  cout << "Creating matrix\n\n";
  try
  {
    TMatrix<int> M1(3), M2(3), M3(3);
    int k = 1;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3 - i; j++)
        M1[i][j] = k++;

	M1[0][0] = 1; M1[0][1] = 2; M1[0][2] = 3;
	M1[1][0] = 4; M1[1][1] = 5;
	M1[2][0] = 6;

	M2[0][0] = 2; M2[0][1] = 3; M2[0][2] = 4;
	M2[1][0] = 5; M2[1][1] = 6;
	M2[2][0] = 7;
	cout << "Первая матрица  " << endl << M1 << endl << endl;
	cout << "Вторая матрица  " << endl << M2 << endl << endl;
    

    cout << "Арифметика: \n\n";
    M3 = M1 + M2;
    cout << "Результат M1 + M2:" << endl << M3 << endl;

	M3 = M1 - M2;
    cout << "Результат M1 - M2:" << endl << M3 << endl;

	M3 = M1 * M2;
    cout << "Результат M1 * M2:" << endl << M3 << endl;

	M3 = M1 / M2;
    cout << "Результат M1 / M2:" << endl << M3 << endl;

	
  }

  catch (MyException exp)
  {
    exp.Print();
  }

  return 0;
}
