#pragma once
#include <iostream>
#include <string>
using namespace std;
class Megazine
{
	string name;
	int price;
	//bool new_megazine;

public:
	Megazine();
	void Show_info();
	int Get_price();
	~Megazine();
};

