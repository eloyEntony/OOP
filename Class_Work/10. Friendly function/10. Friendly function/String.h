#pragma once
#include<string>
#include<iostream>

using namespace std;

class String
{
	string str;

public:
	String();
	String(string str);
	void Show_string();
	void Set_string(string str);
	string Get_string();
	~String();
};

