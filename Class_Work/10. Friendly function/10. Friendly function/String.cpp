#include "String.h"



String::String()
{
}

String::String(string str)
{
	this->str = str;
}

void String::Show_string()
{
	cout << " [String] => " << this->str;
}

void String::Set_string(string str)
{
	this->str = str;
}

string String::Get_string()
{
	return str;
}


String::~String()
{
}
