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

XString XString::operator*=(const XString & other)
{
	int n = 0;
	char new_string[80] = {};

	for (int i = 0; i < strlen(str); i++){
		for (int j = 0; j < strlen(other.str); j++)	{
			if (this->str[i] == other.str[j])	{
				new_string[n] = this->str[i];
				n++;
			}
		}
	}
	cout << "String of common characters  >> ";
	for (int i = 0; i < strlen(new_string); i++)	{
		cout<< new_string[i];
	}
	cout << endl;

	return *this;
}

XString XString::operator/=(const XString & other)
{
	char new_string[80] = {};
	int n = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		int m = 0;
		for (int j = 0; j < strlen(other.str); j++)
		{
			if (this->str[i] != other.str[j])
			{
				m++;
			}
				
		}
		if (m == strlen(other.str))
		{
			new_string[n] = str[i];
			n++;
		}
	}

	cout << "\n\n///";

	for (int i = 0; i < n; i++)
	{
		cout << new_string[i];
	}

	return *this;
}

XString XString::operator+=(const XString & other)
{
	int n = 0;
	char new_string[80] = {};

	for (int i = 0; i < strlen(str)+strlen(other.str); i++)
	{
		if (i < strlen(str))	{
			new_string[i] = this->str[i];
		}
		else	{
			new_string[i] = other.str[n];
			n++;
		}
	}
	cout << " +++ ";
	for (int i = 0; i < strlen(str) + strlen(other.str); i++)	{
		cout << new_string[i];
	}

	return *this;
}





XString::~XString()
{
}
