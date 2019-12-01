#pragma once

#include<iostream>
#include<string>
using namespace std;

class Fish
{
	int x;
	int y; 
	char ruba;
	int health = 100;
	static int xV;
	static int yV;	
	static int live_fish;
	static char sea[10][10];
	static char vodorosl_x[5];
	static char vodorosl_y[5];	
	static char more;
	static char vodorosl;

public:
	Fish();
	Fish(char ruba);
	int Get_health();
	void Deth();
	void Create();
	void Moving();
	void Show_fish_info();
	void Health();
	static void Show_sea();
	static void Live();
	static void Sea();	
	static void Vodorosli();

	 ~Fish();
};

