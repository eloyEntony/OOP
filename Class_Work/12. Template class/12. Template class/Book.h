#pragma once
#include <iostream>
#include <string>
using namespace std;

class Book
{

	string name;
	string publishing;
	string avtor;
	int price;
	bool new_book;

public:
	Book();	
	void Show_book();
	~Book();
};

