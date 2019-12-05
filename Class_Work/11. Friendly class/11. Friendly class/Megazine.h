#pragma once
#include<iostream>
#include<string>
using namespace std;
class Megazine
{
	string name;
	int prise;
	int count;

public:
	Megazine();
	Megazine(string name, int prise);
	void Show_magazine();
	void Buy();
	~Megazine();
};

