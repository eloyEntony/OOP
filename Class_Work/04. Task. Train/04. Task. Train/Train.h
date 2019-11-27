#pragma once
#include<iostream>
#include<string>
#include"TrainCar.h"

using namespace std;

class Train
{
	int number_train = 0;
	string name_train;
	int train_size=0;	
	int suma;
	TrainCar *car;

public:	

	Train();
	Train(string name_train, int size_train, int number_train);
	Train(Train &other);
	int GetSize();
	void Set_name(string name_train);
	void SetSize(int size_train);	
	void Show_info();	
	void Max_car();
	void Min_car();
	void All_passenger();
	void Show_all_info();
	~Train();
};

