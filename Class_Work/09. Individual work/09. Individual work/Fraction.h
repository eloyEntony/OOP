#pragma once
#include<iostream>
using namespace std;

class Fraction
{
	int x;
	int y;
	int abbreviation1;
	int abbreviation2;


public:
	Fraction();
	Fraction(int x);
	Fraction(int x, int y);
	int NOD(int x, int y);
	void Set_x(int x);
	void Set_y(int y);

	int Get_x();
	int Get_y();


	void Show_fraction();
	~Fraction();
};

