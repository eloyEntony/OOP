#pragma once
#include<iostream>
#include<string>
using namespace std;

class XString
{
	char str[80];
	string my_row;
	
public:
	XString();
	XString(char str[]);	
	XString(XString &other);
	void Show_string();

	~XString();
};

