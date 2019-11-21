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
	Add_passenger();
	Type_car();

	cout << " Type train-car: "<< type << endl;
	cout << " Passengers: " << passenger << endl;
}

void TrainCar::Add_passenger()
{
	this->passenger = rand() % 99 + 1;
}

void TrainCar::Type_car()
{
	this->type = rand() % 3 + 1;

	/*cout << "\n===== Train-car type====\n [1] Sompartmen\n [2] Seat \n [3] Sleeping\n" << endl;
	cout << " Enter type train-car: ";
	cin >> this->type;*/
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

