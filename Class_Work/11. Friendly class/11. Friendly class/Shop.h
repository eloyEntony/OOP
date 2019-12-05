#pragma once
#include<iostream>
#include<string>

#include"Audio.h"
#include"Book.h"
#include"Megazine.h"

using namespace std;

class Shop
{
	friend class Audio;	
	friend class Book;
	friend class Megazine;

	string name;
	int money;	


public:
	Shop();
	Shop(string name, int money);
	void Show_shop();
	void Show_product(Book & book, Audio &audio, Megazine &megazine);

	void Buy_product();
	void Sell_product();
	~Shop();
};

