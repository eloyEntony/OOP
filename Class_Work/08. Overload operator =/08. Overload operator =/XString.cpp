#include "XString.h"



XString::XString()
{
}

XString::XString(XString & other)
{
	this->str[80] = other.str[80];	
}

void XString::Create_row()
{
	cout << " Enter you str: ";
	cin >> this->str;
}

void XString::Show_row()
{
	cout << " You row : " << this->str << endl;	
}

void XString::Show_new_string(int size)
{
	for (int i = 0; i < size; i++) {
		cout << new_string[i];
	}
}

XString XString::operator*=(const XString & other)
{
	n = 0;
	for (int i = 0; i < strlen(str); i++){
		for (int j = 0; j < strlen(other.str); j++)	{
			if (this->str[i] == other.str[j])	{
				new_string[n] = this->str[i];
				n++;
			}
		}
	}
	cout << "\n [*] ---> ";	
	Show_new_string(n);
	return *this;
}

XString XString::operator/=(const XString & other)
{
	n = 0;
	for (int i = 0; i < strlen(str); i++)	{
		m = 0;
		for (int j = 0; j < strlen(other.str); j++)	{
			if (this->str[i] != other.str[j])	{
				m++;
			}				
		}
		if (m == strlen(other.str))	{
			new_string[n] = str[i];
			n++;
		}
	}
	cout << "\n\n [/] ---> ";
	Show_new_string(n);
	return *this;
}

XString XString::operator+=(const XString & other)
{
	n = 0;	
	m = 0;

	for (int i = 0; i < strlen(str)+strlen(other.str); i++)	{
		if (i < strlen(str))	{
			new_string[i] = this->str[i];
		}
		else	{
			new_string[i] = other.str[n];
			n++;
		}
		m++;
	}
	cout << "\n\n [+] ---> ";	
	Show_new_string(m);
	return *this;
}

XString::~XString()
{
}
