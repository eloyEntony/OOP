#pragma once
#include<iostream>
#include<string>
#include"String.h"

using namespace std;
//class String;
class Var
{
	enum { t_int, t_double, t_string } type;
	union {
		int integ;
		double doub;
		string stroka;
	};

	

public:
	Var();
	Var(int digit);
	Var(double big_digit);
	Var(string stroka);

	void Show_info();


	~Var();
};

