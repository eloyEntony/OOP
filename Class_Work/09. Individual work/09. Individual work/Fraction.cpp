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
	if (y < 0 || y == 0) {
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

void Fraction::Reducing_fraction()
{
	int nod = 0;
	nod = NOD(x, y);
	cout << " NOD " << nod << endl;

	this->x = this->x / nod;
	this->y = this->y / nod;

	Show_fraction();
}

void Fraction::Multiplication_of_fractions(Fraction &other)
{
	int newX = 0;
	int newY = 0;

	newX = this->x * other.x;
	newY = this->y * other.y;

	int nod = NOD(newX, newY);
	cout << " Multiplication fractions :::> " << newX / nod << "/" << newY / nod << endl;
}

void Fraction::Fraction_division(Fraction & other)
{
	int newX = 0;
	int newY = 0;

	newX = this->x * other.y;
	newY = this->y * other.x;

	int nod = NOD(newX, newY);
	cout << " Division fractions :::> " << newX / nod << "/" << newY / nod << endl;
}

void Fraction::Plus_Plus()
{
	this->x++;
	this->y++;
}

void Fraction::operator>(Fraction & other)
{
	if (this->y == other.y)
	{
		cout << "y=y" << endl;
		if (this->x > other.x)
			cout << "f1 > f2" << endl;
		else
			cout << "f1 < f2" << endl;
	}

	else if (this->x == other.x)
	{
		float  res1 = float(x) / float(y);
		float  res2 = float(other.x) / float(other.y);		

		cout << "x=x" << endl;
		if (res1 > res2) 			
			cout << "f1 > f2" << endl;		
		else 
			cout << "f1 < f2" << endl;
	}

	else {

		int newX1;
		int newX2;
		int newY1;
		int newY2;

		int nod = NOD(this->y, other.y);
		//cout << nod << endl;

		int nok2 = this->y / nod; //додатковий множник для дробу
		int nok1 = other.y / nod;

		//cout << nok1 << " " << nok2 << endl;

		newX1= this->x*nok1; 
		newY1 = this->y*nok1;

		newX2 = other.x*nok2;
		newY2 = other.y*nok2;

		cout << newX1 << " / " << newY1 << "   " << newX2 << " / " << newY2 << endl;
		
		if (newX1 > newX2)	{
			cout << "f1 > f2" << endl;
		}
		else
			cout << "f1 < f2" << endl;
	}
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
