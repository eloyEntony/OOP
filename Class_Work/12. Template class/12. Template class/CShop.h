#pragma once
#include<iostream>
#include<string>
#include"Book.h"

using namespace std;

template<typename  T>
class CShop
{
	int SIZE;
	T Array[SIZE];

	T *type;


	Book book[2];

public:
	 CShop();
	 CShop(int size);
	 void Show();
	 ~CShop();
};

