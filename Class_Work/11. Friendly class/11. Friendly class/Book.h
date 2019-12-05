#pragma once
#include<string>
#include<iostream>
using namespace std;

class Book
{
	string name;
	int prise;
	//static int count;
	//int bookID;
	

public:
	Book();
	Book(int size);
	void Show_book();
	void Buy();
	~Book();
};

