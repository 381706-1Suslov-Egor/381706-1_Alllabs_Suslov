#include "Polynom.h"

int main() 
{
	setlocale(LC_ALL, "rus");
  int mas1[] = { 1, 2, 3 };
  int mas2[] = { 4, 5, 6 };
  int mas3[] = { 7, 8, 9 };
  int mas4[] = { 9, 8, 7 };
  int mas5[] = { 6, 5, 4 };
  int mas6[] = { 3, 2, 1 };

  try
  {
    TMonom A(3, mas1, 1);
    TMonom B(3, mas2, 2);
    TMonom C(3, mas3, 3);
    TMonom D(3, mas4, 3);
    TMonom E(3, mas5, 2);
    TMonom F(3, mas6, 1);

    cout << "Monom A: " << A << endl;
    cout << "Monom B: " << B << endl;
    cout << "Monom C: " << C << endl;
    cout << "Monom D: " << D << endl;
    cout << "Monom E: " << E << endl;
    cout << "Monom F: " << F << endl;


    TPolynom p1(3);
    p1 += A;
    p1 += B;
    p1 += C;
    cout << "\nПервый полином = A + B + C = " << p1 << endl;

    TPolynom p2(3);
    p2 += D;
    p2 += E;
    p2 += F;
    cout << "\nВторой полином = D + E + F = " << p2 << endl;

    TPolynom pol1(3);

    pol1 = p1 + p2;
    cout << "\nРезультат первый + второй = " << pol1 << endl;

    pol1 = p1 - p2;
    cout << "Результат первый - второй = " << pol1 << endl;

    pol1 = p1 * p2;
    cout << "Результат первый * второй = " << pol1 << endl;
  }

  catch (MyException exp)
  {
    exp.Print();
  }


 return 0;
}
