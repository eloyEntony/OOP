#pragma once
#include <iostream>
#include <string>
using namespace std;

class Audio
{
	string name;
	string avtor;
	int music_count;
	int price;
	//bool new_audio;

public:
	Audio();	
	void Show_info();
	int Get_price();
	~Audio();
};

