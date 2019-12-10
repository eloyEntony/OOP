#include "Audio.h"



Audio::Audio()
{
	cout << " Enter name disk   : ";
	cin >> this->name;
	cout << " Enter avtor       : ";
	cin >> this->avtor;
	cout << " Enter music count : ";
	cin >> this->music_count;
	cout << " Enter price       : ";
	cin >> this->price;
	//cout << " New disk ? [1/0]  : ";
	//cin >> this->new_audio;
	cout << "\n|||||||||||||||||||||||||||||||||||\n" << endl;
}

void Audio::Show_info()
{
	cout << endl;
	cout << "---------------------------------------------" << endl;
	cout << " NAME        : " << this->name << endl;
	cout << " AVTOR       : " << this->avtor << endl;
	cout << " MUSIC COUNT : " << this->music_count << endl;
//	cout << " PRICE       : " << this->price << endl;
	//cout << " NEW DISK ?  : " << this->new_audio << endl;
}

int Audio::Get_price()
{
	return this->price;
}


Audio::~Audio()
{
}
