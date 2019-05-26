#include "TPlex.h"
#include "TPoint.h"
#include "TSection.h"
#include <iostream>
#include <locale>

using namespace std;

int main()
{
	setlocale (LC_ALL, "Russian");

	int a = 0, b = 0;
	TPoint A, B(7,4), C(0,15), D(3,17), E;
	cout<<"�����:\n";
	cout<<"������� �����:\n";
	cin>>a>>b;
	cout<<"�� ����� ����� � � ������������:\n";
	A.SetX(a);
	A.SetY(b);
	A.show();
	cout<<"����� ���� ����� � � � � ������������:\n";
	B.show();
	C.show();
	cout<<"\n\n\n";
	
	cout<<"�������:\n";
	TSection AB(A, B);
	cout<<"������� �� ����� ���������:\n";
	AB.show();
	cout<<"\n\n\n";

	cout<<"������:\n";
	TPlex P, P1(&A, &B);
	TPlex P2(P1);
	cout<<"��� ������ ����� �� ����� � � �...\n";
	cout<<"� ����� ��������� ����� (0, 15)...\n";
	P2.Add(&A, &C);
	cout<<"� ����� ��������� ����� (3, 17)...\n";
	P2.Add(&C, &D);
	
	cout<<"������� �����:\n";
	cin>>a>>b;
	cout<<"� ����� ��������� ��������� �����... \n";
	E.SetX(a);
	E.SetY(b);
	P2.Add(&B,&E);
	cout<<"��������� �����: \n";
	P2.show();
	cout<<"\n\n\n";
  return 0;
}
