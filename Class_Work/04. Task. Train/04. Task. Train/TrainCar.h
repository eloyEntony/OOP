#pragma once
#include<iostream>
#include<string>

using namespace std;

class TrainCar
{
	int type=0;
	unsigned short passenger = 0;

public:
	TrainCar();

	TrainCar(int type, short passenger);

	void Show_info();

	void Add_passenger();

	void Type_car();

	int Get_type();

	void Set_type(int type);

	int Get_passenger();

	

	~TrainCar();
};

