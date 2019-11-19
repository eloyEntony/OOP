#pragma once
#include<string>
#include<iostream>
using namespace std;

class Card
{
	int Num_card = 1320682116;
	int Discont = 1;
	double All_prise=0;

public:

	Card();

	void Show_info();
	double Get_All_prise();
	void Set_All_prise(double buy);
	void Plus_Discont();
		

};

