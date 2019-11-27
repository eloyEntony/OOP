#pragma once
#include<iostream>
#include<string>

using namespace std;

class TrainCar
{
	int type=0;
	unsigned short passenger = 0;
	int carID;
	static int count;

public:
	TrainCar();
	TrainCar(int type, short passenger);
	void Show_info();
	int Get_type();
	void Set_type(int type);
	int Get_passenger();
	void Fillcar();
	~TrainCar();
};

