#pragma once
#include<iostream>
using namespace std;

class Fraction
{
	int x;
	int y;
	int abbreviation1;
	int abbreviation2;

	friend void Subtraction_of_fractions(Fraction &f1, Fraction &f2);

public:
	Fraction();
	Fraction(int x);
	Fraction(int x, int y);
	int NOD(int x, int y);
	void Reducing_fraction();
	void Multiplication_of_fractions(Fraction &other);
	void Fraction_division(Fraction &other);
	void Plus_Plus();
	void operator>(Fraction &other);
	void Set_x(int x);
	void Set_y(int y);
	int Get_x();
	int Get_y();


	void Show_fraction();
	~Fraction();
};

