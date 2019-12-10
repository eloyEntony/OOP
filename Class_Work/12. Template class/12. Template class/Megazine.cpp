#include "Megazine.h"



Megazine::Megazine()
{
	cout << " Enter name megazine  : ";
	cin >> this->name;	
	cout << " Enter price          : ";
	cin >> this->price;
	//cout << " New megazine ? [1/0] : ";
	//cin >> this->new_megazine;
	cout << "\n|||||||||||||||||||||||||||||||||||\n" << endl;
}

void Megazine::Show_info()
{
	cout << endl;
	cout << "---------------------------------------------" << endl;
	cout << " NAME            : " << this->name << endl;
	cout << " PRICE           : " << this->price << endl;
	//cout << " NEW MEGAZINE ?  : " << this->new_megazine << endl;
}

int Megazine::Get_price()
{
	return this->price;
}


Megazine::~Megazine()
{
}
