#include "Train.h"
#include "TrainCar.h"



Train::Train()
{
}

int Train::GetSize()
{
	return train_size;
}

void Train::Set_name(string name_train)
{
	this->name_train = name_train;
}

void Train::SetSize(int train_size)
{
	this->train_size = train_size;
}

Train::Train(string name_train, int train_size)
{	
	cout << "CONSTRUCTOR" << endl;
	this->name_train = name_train;
	this->train_size = train_size;

	//this->car = new TrainCar[train_size];

	for (int i = 0; i < this->train_size; i++) {
		this->car[i].Fillcar();
	}
}

Train::Train(Train &other)
{
	this->number_train = other.number_train;
	this->name_train = other.name_train;
	this->train_size = other.train_size;

	for (int i = 0; i < other.train_size; i++) {
		this->car[i] = other.car[i];
	}

}

void Train::Show_info()
{	
	cout << "\n------------------------------------------------------" << endl;
	cout << " Train number: " << number_train << endl;
	cout << " Train name: " << name_train << endl;
	cout << " Tain size (number train-car): " << train_size << endl;
	cout << " Train-car: " << endl;

	for (int i = 0; i < this->train_size; i++) {

		cout<<"\n [ "<<i<<" ] "<<"Car"<<endl;
		car[i].Show_info();
	
	}
}

void Train::Train_number(){

	cout << " Enter number train: ";
	cin >> this->number_train;
	//this->number_train = rand() % 99 + 10;
}

void Train::Max_car()
{
	int max = 0;
	int tmp=0;

	for (int i = 0; i < this->train_size; i++)
	{
		if (car[i].Get_passenger() > max)
		{
			max = car[i].Get_passenger();
			tmp = i;
		}
	}


	cout << " Train-car for MAX passenger >>> " << tmp << endl;
}

void Train::Min_car()
{
	int min = car[0].Get_passenger();
	int tmp=0;

	for (int i = 0; i < this->train_size; i++)
	{
		if (car[i].Get_passenger() < min)
		{
			min = car[i].Get_passenger();
			tmp = i;
		}
	}

	cout << " Train-car for MIN passenger >>> " << tmp << endl;

}

void Train::All_passenger()
{
	int suma = 0;

	for (int i = 0; i < this->train_size; i++)
	{
		suma += car[i].Get_passenger();
	}
	
	cout << " All passenger in train "  <<suma<< endl;
}

void Train::Show_all_info()
{
	cout << "------------------------------------------------" << endl;
	All_passenger();
	cout << " All train-car : " << this->train_size << endl;
	Max_car();
	Min_car();
}






Train::~Train()
{
	delete[] car;
	cout << " DESTRUCTOR" << endl;
}
