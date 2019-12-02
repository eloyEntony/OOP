#include "XString.h"



XString::XString()
{
}

XString::XString(char str[])
{
	for (int i = 0; i < 80; i++) {
		this->str[i] = str[i];
	}

	my_row = this->str;

}

XString::XString(XString & other)
{
	this->str[80] = other.str[80];
	this->my_row = other.my_row;
}

void XString::Show_string()
{
	cout << "You row : " << str << endl;	
}


XString::~XString()
{
}
