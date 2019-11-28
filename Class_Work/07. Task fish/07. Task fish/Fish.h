#pragma once

#include<iostream>
#include<string>
using namespace std;

class Fish
{
	int x;
	int y;
	int fishID;
	unsigned short health;
	static char sea[10][10]  {'. '};
	static int live_fish;



public:
	Fish();
	void Moving();
	void Show_fish_info();
	static void Show_sea();
	~Fish();
};

