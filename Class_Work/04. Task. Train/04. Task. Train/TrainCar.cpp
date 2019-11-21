#include "TrainCar.h"



TrainCar::TrainCar()
{
}

TrainCar::TrainCar(int type, short passenger)
{
	this->type = type;
	this->passenger = passenger;
}


void TrainCar::Show_info()
{
	cout << " Type train-car: "<< type << endl;
	cout << " Passengers: " << passenger << endl;
}

void TrainCar::Add_passenger()
{
	this->passenger = rand() % 99 + 10;
}

int TrainCar::Get_passenger()
{
	return passenger;
}



int TrainCar::Get_type()
{
	return type;
}

void TrainCar::Set_type(int type)
{
	this->type = type;
}


TrainCar::~TrainCar()
{
}

