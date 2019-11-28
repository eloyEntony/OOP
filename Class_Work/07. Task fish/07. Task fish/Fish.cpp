#include "Fish.h"



Fish::Fish()
{
	this->live_fish++;
	this->fishID = live_fish;
}

void Fish::Moving()
{
	this->x = rand() % 10 + 0;
	this->y = rand() % 10 + 0;
}

void Fish::Show_fish_info()
{
	cout << "ID " << this->fishID << endl;
	cout << " Coordinates " << endl;
	cout << "[X] -> " << this->x << endl;
	cout << "[Y] -> " << this->y << endl;
}

void Fish::Show_sea()
{
	

	cout << "\n\n" << endl;
	for (int i = 0; i < 10; i++){
		
		for (int j = 0; j < 10; j++) {			

			//if (i != 0 && i != (10 - 1) && j != 0 && j != (10 - 1)) {
				/*
				if (this->x == i && this->y == j) {
					cout << "> ";
				}
				else*/
			cout << sea[i][j];
			//}
						 
		}
		cout << "\n";
	}
	cout << "\n\n" << endl;
}


Fish::~Fish()
{
}
