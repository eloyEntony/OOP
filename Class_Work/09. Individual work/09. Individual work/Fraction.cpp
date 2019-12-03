#include "Fraction.h"



Fraction::Fraction()
{
	x = 0;
	y = 1;
}

Fraction::Fraction(int x)
{
	this->x = x;
	this->y = 1;
}

Fraction::Fraction(int x, int y)
{
	this->x = x;
	if (y <= 0) {
		cout << " Denominator cannot be less than 0. Denominator will be 1" << endl;
		this->y = 1;
	}
	else
	this->y = y;
}

int Fraction::NOD(int x, int y)
{	
	if (y == 0) return x;
	return NOD(y, x%y);
}

void Fraction::Set_x(int x)
{
	this->x = x;
}

void Fraction::Set_y(int y)
{
	this->y = y;
}

int Fraction::Get_x()
{
	return this->x;
}

int Fraction::Get_y()
{
	return this->y;
}

void Fraction::Show_fraction()
{
	cout <<" "<< x << "/" << y << endl;
}


Fraction::~Fraction()
{
}
