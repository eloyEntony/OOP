#pragma once
#include<iostream>
#include<string>
#include <stdio.h>
using namespace std;

class XString
{
	char str[80];
	
public:
	XString();
	XString(XString &other);
	void Create_row();
	void Show_row();

	XString operator*=(const XString &other);
	XString operator/=(const XString &other);
	XString operator+=(const XString &other);



	~XString();
};

