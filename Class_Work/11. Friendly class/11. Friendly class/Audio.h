#pragma once
#include<string>
#include"Shop.h"
using namespace std;
class Audio
{
	//friend class Shop;
	string name;
	int prise;
	int count;

public:
	Audio();
	Audio(string name, int prise);
	void Show_audio();
	void Buy();
	~Audio();
};

