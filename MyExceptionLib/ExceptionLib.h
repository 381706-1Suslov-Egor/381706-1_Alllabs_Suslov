#pragma once
#include <iostream>
#include <string>
using namespace std;

class MyException 
{
private:
  string str;
public:
  MyException(string _str) : str(_str) {}
  void Print() 
  { 
	  setlocale(LC_ALL, "Russian");
	  cout << "\n\n Ошибка! \nПроблема: " << str << endl; 
  }
};
