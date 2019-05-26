#include <iostream>
#include "TPlex.h"

using namespace std;

void TPlex::SetL(TPoint* _l)
{
	l = _l;
}
//-------------------------------------------------------------------------------------------------
void TPlex::SetR(TPoint* _r)
{
	r = _r;
}
//-------------------------------------------------------------------------------------------------
TPoint* TPlex::GetL()
{
	return l;
}
//-------------------------------------------------------------------------------------------------
TPoint* TPlex::GetR()
{
	return r;
}
//-------------------------------------------------------------------------------------------------
TPlex::TPlex()
{
	l = NULL;
	r = NULL;
}
//-------------------------------------------------------------------------------------------------
TPlex::TPlex(TPoint *_l, TPoint *_r)
{
	l = _l;
	r = _r;
}
//-------------------------------------------------------------------------------------------------

TPlex::TPlex(TPlex& P)
{
	TPlex *pl, *pr;
	pl = dynamic_cast <TPlex*> (P.l);
	pr = dynamic_cast <TPlex*> (P.r);
	if (pl != 0)
		l = new TPlex(*pl);
	else
		l = new TPoint(*(P.GetL()));
	if (pr != 0)
		r = new TPlex(*pr);
	else
		r = new TPoint(*(P.GetR()));
}
//-------------------------------------------------------------------------------------------------
TPoint* TPlex::Search(TPoint *A)
{
	TPlex *pl, *pr;
	TPoint* res;
	pl = dynamic_cast <TPlex*> (l);
	pr = dynamic_cast <TPlex*> (r);
	if (*l == *A)
		return l;
	else if (pl != NULL)
	{
		res = pl->Search(A);
		if (res != NULL)
			return res;
	}
	if (*r == *A)
		return r;
	else if (pr != NULL)
	{
		pr->Search(A);
		if (res != NULL)
			return res;
	}
	if ((pr == NULL) && (pl == NULL))
		return NULL;
}
//-------------------------------------------------------------------------------------------------
void TPlex::Add(TPoint* A, TPoint* B)
{

	TPlex *pl, *pr;
	TPoint* res;
	pl = dynamic_cast <TPlex*> (l);
	pr = dynamic_cast <TPlex*> (r);
	try
	{
		if ((pl == 0) && ((*l == *A) || (*l == *B)))
		{
			l = new TPlex(A, B);
		}
		else if ((pr == 0) && ((*r == *A) || (*r == *B)))
		{
			r = new TPlex(A, B);
		}
		else if (pl != 0)
		{
			pl->Add(A, B);
		}
		else if (pr != 0)
		{
			pr->Add(A, B);
		}
		else
			throw - 1;
	}
	catch (...)
	{
		cout << "� ������ ��� ����� �����!!\n";
	}

}
//-------------------------------------------------------------------------------------------------
void TPlex::show()
{
	TPlex *pl, *pr;
	cout << "�������\n";
	pl = dynamic_cast <TPlex*> (l);
	pr = dynamic_cast <TPlex*> (r);
	if (pl != 0)
	{
		cout << "����� ";
		pl->show();
	}
	else if (pl == 0)
	{
		cout << "����� T����:\n";
		l->show();
	}
	if (pr != 0)
	{
		cout << "������ ";
		pr->show();
	}
	else if (pr == 0)
	{
		cout << "������ T����:\n";
		r->show();
	}
}