#include "Megazine.h"



Megazine::Megazine()
{
}

Megazine::Megazine(string name, int prise)
{
	this->name = name;
	this->prise = prise;
	//this->count++;
}

void Megazine::Show_magazine()
{
	cout << "\t Name: " << this->name << "\n\t Prise: " << this->prise << endl;
}

void Megazine::Buy()
{
	cout << " Enter name to buy: ";
	cin >> this->name;
	cout << " Enter prise: ";
	cin >> this->prise;
}


Megazine::~Megazine()
{
}
