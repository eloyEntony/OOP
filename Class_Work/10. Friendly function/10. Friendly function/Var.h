#pragma once
#include<iostream>
#include<string>
#include"String.h"

using namespace std;

class String;
class Var
{
	enum { t_int, t_double, t_string } type;
	union {
		int integ;
		double doub;
		string stroka;
	};
	
	String str;
	
	

public:
	Var();
	Var(int digit);
	Var(double big_digit);
	Var(string stroka);
	

	void Show_info();

	Var operator+(Var &other);

	Var operator-(Var &other);

	Var operator*(Var &other);

	int  convert_from_string_to_int(string strin);

	string convert_from_int_to_string(int num);	

	string convert_from_double_to_string(double num);

	int convert_from_double_to_int(double num);

	~Var();
};

