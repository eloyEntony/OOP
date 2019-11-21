#include "Train.h"
#include "TrainCar.h"



Train::Train()
{
}

void Train::Add_train_car(int train_size, int type)
{	
	for (int i = 0; i < train_size; i++)
	{
		car[i].Get_passenger();		
		car[i].Get_type();
	}
	
}

int Train::GetSize()
{
	return train_size;
}

void Train::Set_name(string name_train)
{
	this->name_train = name_train;
}

void Train::SetSize(int size_train)
{
	this->train_size = size_train;
}

Train::Train(int number_train, string name_train)
{
	this->number_train = number_train;
	this->name_train = name_train;
}

void Train::Show_info(int size_train)
{
	Train_number();
	cout << "\n------------------------------------------------------" << endl;
	cout << " Train number: " << number_train << endl;
	cout << " Train name: " << name_train << endl;
	cout << " Tain size (number train-car): " << train_size << endl;
	cout << " Train-car: ";

	for (int i = 0; i < size_train; i++) {		

		cout<<"\n [ "<<i+1<<" ] "<<"Car"<<endl;
		car[i].Show_info();
	
	}
}

void Train::Set_passenger(int passenger)
{
	this->passenger = passenger;
}

int Train::Get_passenger()
{
	return passenger;
}


void Train::Train_number()
{
	number_train = rand() % 99 + 10;
}




Train::~Train()
{
}
