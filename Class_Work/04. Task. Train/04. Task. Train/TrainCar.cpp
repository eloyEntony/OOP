#include "TrainCar.h"



TrainCar::TrainCar(){}

TrainCar::TrainCar(int type, short passenger){
	this->type = type;
	this->passenger = passenger;
}


void TrainCar::Show_info(){	
	cout << "[" << this->carID << "]"<<endl;
	cout << " Type train-car: "<< type << endl;
	cout << " Passengers: " << passenger << endl;
}

int TrainCar::Get_passenger(){
	return passenger;
}

void TrainCar::Fillcar(){	
	this->passenger = rand() % 99 + 1;
	this->type = rand() % 3 + 1;
	count++;
	this->carID = this->count;
}

int TrainCar::Get_type(){
	return type;
}

void TrainCar::Set_type(int type){
	this->type = type;
}

TrainCar::~TrainCar(){}

