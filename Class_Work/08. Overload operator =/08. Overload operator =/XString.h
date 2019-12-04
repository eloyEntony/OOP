#pragma once
#include<iostream>
#include<string>
#include <stdio.h>
using namespace std;

class XString
{
	char str[80];
	char new_string[80] = {};
	int n;
	int m;
	
public:
	XString();
	XString(XString &other);
	void Create_row();
	void Show_row();
	void Show_new_string(int size);
	XString operator*=(const XString &other);
	XString operator/=(const XString &other);
	XString operator+=(const XString &other);

	~XString();
};

