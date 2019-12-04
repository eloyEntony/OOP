#include "Var.h"



Var::Var()
{
}

Var::Var(int digit)
{
	type = t_int;
	integ = digit;
}

Var::Var(double big_digit)
{
	type = t_double;
	doub = big_digit;
}

Var::Var(string str)
{
	type = t_string;
	stroka = str;
}

void Var::Show_info()
{
	if (type == t_int)
		cout << "\n Type: " << type << " Int => " << integ;
	else if (type == t_double)
		cout << "\n Type: " << type << " Double=> " << doub;
	else if (type == t_string)
		cout << "\n Type: " << type << " String=> " << stroka;
}


Var::~Var()
{
}
