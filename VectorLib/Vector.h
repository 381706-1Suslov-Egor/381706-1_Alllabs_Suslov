#pragma once
#include "ExceptionLib.h"

template <class T>
class TVector
{
protected:
  T *pvector;     //��������� �� ������ 
  int size;       // ������ �������
public:
  TVector(int s = 0);
  TVector(const TVector &v);                
  virtual ~TVector();

  int GetSize() const;                      // ������ �������
  virtual T& operator[](int pos);           // �������� ����������
  
  bool operator==(const TVector &v) const;      // ���������
  bool operator!=(const TVector &v) const;      // ���������
  virtual TVector& operator=(const TVector &v); // ������������

  TVector operator+(const T &val);   // ��������� ������
  TVector operator-(const T &val);   // ������� ������
  TVector operator*(const T &val);   // �������� �� ������

  TVector operator+(const TVector &v);     // ��������
  TVector operator-(const TVector &v);     // ���������
  T operator*(const TVector &v);           // ��������� ������������

  template <class Type>
  friend istream& operator>>(istream &in, TVector<Type>& v);
  template <class Type>
  friend ostream& operator<<(ostream &out, const TVector<Type>& v);
}; 

template <class T>
TVector<T>::TVector(int s)
{
	if (s < 0)
		throw MyException("������ �������");
  else
    if (s == 0) 
    {
      size = s;
	  pvector = NULL;
    }
    else 
    {
      size = s;
	  pvector = new T[size];
      for (int i = 0; i < size; i++)
		  pvector[i] = 0;
    }
} 

template <class T> 
TVector<T>::TVector(const TVector<T> &V) 
{
  size = V.size;
  if (size == 0)
	  pvector = NULL;
  else 
  {
	  pvector = new T[size];
    for (int i = 0; i < size; i++)
		pvector[i] = V.pvector[i];
  }
} 

template<class T>
TVector<T>::~TVector() 
{
  if (size > 0)
  {
    size = 0;
    delete[] pvector;
	pvector = NULL;
  }
} 

template <class T>
int TVector<T>::GetSize() const
{ 
  return size; 
}

template <class T> 
T& TVector<T>::operator[](int pos)
{
	if (pos >= 0 && pos < size)
		return pvector[pos];
	else
		throw MyException("������ ����������");
} 

template <class T>
bool TVector<T>::operator==(const TVector &v) const
{
	if (size != v.size)
		return 0;
	else
		for (int i = 0; i < size; i++)
			if (pvector[i] != v.pvector[i])
			{
        return 0;
			}
	return 1;
} 

template <class T> 
bool TVector<T>::operator!=(const TVector &v) const
{
  return !(*this == v);
} 

template <class T> 
TVector<T>& TVector<T>::operator=(const TVector &v)
{
	if (this != &v)
	{
		delete[] pvector;
		size = v.size;
		pvector = new T[size];
		for (int i = 0; i < size; i++)
			pvector[i] = v.pvector[i];
	}
	return *this;
} 

template <class T>
TVector<T> TVector<T>::operator+(const T &val)
{
	TVector<T> res(*this);
	for (int i = 0; i < size; i++)
		res.pvector[i] += val;
	return res;
}

template <class T>
TVector<T> TVector<T>::operator-(const T &val)
{
	TVector<T> res(*this);
	for (int i = 0; i < size; i++)
		res.pvector[i] -= val;
	return res;
}

template <class T>
TVector<T> TVector<T>::operator*(const T &val)
{
	TVector<T> res(*this);
	for (int i = 0; i < size; i++)
		res.pvector[i] = res.pvector[i] * val;
	return res;
} 

template <class T>
TVector<T> TVector<T>::operator+(const TVector<T> &v)
{
  if (size != v.size)
    throw MyException("������ ������ ��������");
  TVector<T> rez(*this);
  for (int i = 0; i < size; i++)
    rez[i] = (*this)[i] + v.pvector[i];
  return rez;
} 

template <class T>
TVector<T> TVector<T>::operator-(const TVector<T> &v)
{
  if (size != v.size)
    throw MyException("������ ������ ��������");
  TVector<T> rez(*this);
  for (int i = 0; i < size; i++)
    rez[i] = (*this)[i] - v.pvector[i];
  return rez;
}

template <class T> 
T TVector<T>::operator*(const TVector<T> &v)
{
  if (size != v.size)
    throw MyException("������ ������ ��������");
  int temp = 0;
  for (int i = 0; i < size; i++)
    temp += pvector[i] * v.pvector[i];
  return temp;
} 

template <class T>
istream& operator>>(istream &in, TVector<T> &v)
{
	for (int i = 0; i < v.size; i++)
		in >> v.pvector[i];
	return in;
}

template <class T>
ostream& operator<<(ostream &out, const TVector<T> &v)
{
	for (int i = 0; i < v.size; i++)
		out << v.pvector[i] << ' ';
	return out;
}

