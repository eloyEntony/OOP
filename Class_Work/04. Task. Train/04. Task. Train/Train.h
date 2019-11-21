#pragma once
#include<iostream>
#include<string>
#include"TrainCar.h"

using namespace std;

class Train
{
	int number_train=0;
	string name_train;
	int train_size=0;	

	int passenger = 0;

	TrainCar *car = new TrainCar[train_size];

public:
	Train();

	void Add_train_car( int train_size, int type);

	int GetSize();

	void Set_name(string name_train);

	void SetSize(int size_train);

	Train(int number_train, string name_train);

	void Show_info(int size_train);

	void Set_passenger(int passenger);

	int Get_passenger();

	void Train_number();

	

	~Train();
};

