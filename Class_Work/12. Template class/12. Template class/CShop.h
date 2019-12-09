#pragma once
#include <iostream>
#include <string>
using namespace std;
//#include"Book.h"

template <typename T>
class CShop
{
	//friend Book;
	int size;
	T *arr;

public:
	CShop();
	CShop(int size);
	void Show_info();
	~CShop();
};

