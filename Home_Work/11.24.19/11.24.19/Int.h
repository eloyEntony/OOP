#pragma once
#include<iostream>
using namespace std;
class Int
{
	int a=0;

public:
	Int();
	Int(int a);
	Int(Int &other);// copy metod
	int Get_int();
	void Set_int(int a);
	void Show_info();
	int Sum(Int b);
	int Sub(Int b);
	int Mul(Int b);
	int Div(Int b);
	int Get_value();


	~Int();
};

