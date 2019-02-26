#include "Monom.h"

TMonom::TMonom()
{
  next = NULL;
  power = NULL;
  coef = 0;
  n = 0;
}

TMonom::TMonom(int _n, int* _power, double _c)
{
  if (_n < 0)
    throw MyException("Negative size");
  else if (_n == 0)
  {
    power = NULL;
    n = _n;
    coef = _c;
    next = NULL;
  }
  else
  {
    n = _n;
    coef = _c;
    next = NULL;
    power = new int[_n];
    for (int i = 0; i < _n; i++)
    {
      if (_power[i] >= 0)
        power[i] = _power[i];
      else
        throw MyException("Negative power");
    }
  }
}

TMonom::TMonom(const TMonom &A)
{
  n = A.n;
  coef = A.coef;
  next = A.next;
  power = new int[n];
  for (int i = 0; i < n; i++)
  {
    power[i] = A.power[i];
  }
}

TMonom::~TMonom()
{
  if (power != 0)
    delete[]power;
  n = 0;
  coef = 0;
  next = 0;
}

TMonom* TMonom::GetNext()
{
  return next;
}

int* TMonom::GetPower()
{
  return power;
}

double TMonom::GetC()
{
  return coef;
}

int TMonom::GetN()
{
  return n;
}

void TMonom::SetNext(TMonom* _next)
{
  next = _next;
}

void TMonom::SetPower(int* _power)
{
  for (int i = 0; i < n; i++)
  {
    if (_power[i] >= 0)
      power[i] = _power[i];
    else
      throw MyException("Negative power");
  }
}

void TMonom::SetC(double _c)
{
  coef = _c;
}

void TMonom::SetN(int _n)
{
  if (_n < 0)
    throw MyException("Negative size");
  else if (_n == 0)
  {
    if (power != 0)
      delete[] power;
    power = 0;
    n = 0;
  }
  else
  {
    int *tmp = new int[n];
    for (int i = 0; i < n; i++)
      tmp[i] = power[i];
    delete[]power;
    power = new int[_n];
    int i = 0;
    if (n < _n)
    {
      for (; i < n; i++)
        power[i] = tmp[i];
      for (; i < _n; i++)
        power[i] = 0;
    }
    if (_n < n)
      for (; i < _n; i++)
        power[i] = tmp[i];
    n = _n;
  }
}

TMonom& TMonom::operator=(const TMonom& A)
{
  if (n != A.n)
    throw MyException("Error size eq");
  coef = A.coef;
  n = A.n;
  next = A.next;
  delete[] power;
  power = new int[n];
  for (int i = 0; i < n; i++)
    power[i] = A.power[i];
  return *this;
}

TMonom TMonom::operator+(TMonom& A)
{
  TMonom tmp(A);
  if (n != A.n)
    throw MyException("Different n");
  if (!(*this == A))
    throw MyException("Different power");
  tmp.coef = coef + A.coef;
  return tmp;
}

TMonom TMonom::operator+=(TMonom & A)
{
  if (n != A.n)
    throw MyException("Different n");
  if (!(*this == A))
    throw MyException("Different power");
  coef += A.coef;
  return *this;
}

TMonom TMonom::operator-(TMonom& A)
{
  TMonom tmp(A);
  if (n != A.n)
    throw MyException("Different n");
  if (!(*this == A))
    throw MyException("Different power");
  tmp.coef = coef - A.coef;
  return tmp;
}

TMonom TMonom::operator-=(TMonom & A)
{
  if (n != A.n)
    throw MyException("Different n");
  if (!(*this == A))
    throw MyException("Different power");
  coef -= A.coef;
  return *this;
}

TMonom TMonom::operator*(const TMonom& A) const
{
  if (n != A.n)
    throw MyException("Different n");
  TMonom tmp(A);
  tmp.coef = coef * A.coef;
  for (int i = 0; i < n; i++)
    tmp.power[i] = power[i] + A.power[i];
  return tmp;
}

TMonom TMonom::operator*=(TMonom& A)
{
  if (n != A.n)
    throw MyException("Different n");
  coef = coef * A.coef;
  for (int i = 0; i < n; i++)
    power[i] += A.power[i];
  return *this;
}

bool TMonom::operator==(TMonom& A)
{
  if (n != A.n)
    throw MyException("Different size");
  for (int i = 0; i < n; i++)
    if (power[i] != A.power[i])
      return false;
  return true;
}// ---------------------------------------------------------------------------

bool TMonom::operator>(TMonom& A)
{
  if (n != A.n)
    throw MyException("Different n");
  if (*this == A)
    throw MyException("Monoms eq");
  for (int i = 0; i < n; i++)
  {
    if (power[i] == A.power[i])
      continue;
    else if (power[i] > A.power[i])
      return true;
    else
      return false;
  }
  return true;
}

bool TMonom::operator<(TMonom& A)
{
  if (n != A.n)
    throw MyException("Different n");
  if (*this == A)
    throw MyException("Monoms eq");
  for (int i = 0; i < n; i++)
  {
    if (power[i] == A.power[i])
      continue;
    else if (power[i] < A.power[i])
      return true;
    else
      return false;
  }
  if (coef > A.coef)
    return false;
  return true;
}

istream& operator>>(istream& istr, TMonom& A)
{
  istr >> A.coef;
  for (int i = 0; i < A.n; i++)
    istr >> A.power[i];
  return istr;
}

ostream& operator<<(ostream& ostr, TMonom& A)
{
  ostr << A.coef;
  if (A.coef != 0)
  {
    for (int i = 0; i < A.n; i++)
      if (A.power[i] != 0)
      {
        ostr << "*x" << i;
        if (A.power[i] != 1)
          ostr << "^" << A.power[i];
      }
  }
  return ostr;
}
