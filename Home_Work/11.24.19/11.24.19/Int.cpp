#include "Int.h"



Int::Int()
{	
}

Int::Int(int a){
	this->a = a;
}

int Int::Get_int(){
	return this->a;
}

void Int::Set_int(int a){
	this->a = a;
}

void Int::Show_info(){
	cout << " >>> " << this->a << endl;
}

int Int::Sum(Int b){
	this->a = a + b.Get_int();	
	return a;
}

int Int::Sub(Int b){
	this->a = a - b.Get_int();
	return a;
}

int Int::Mul(Int b){
	this->a = a * b.Get_int();
	return a;
}

int Int::Div(Int b)
{
	if (b.Get_int() == 0)	{
		cout << " Nooo" << endl;
		return 0;
	}
	else {
		this->a = a / b.Get_int();
		return a;
	}
}


int Int::Get_value(){
	return a;
}


Int::~Int()
{
}
