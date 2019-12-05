#include "Audio.h"



Audio::Audio()
{
}

Audio::Audio(string name, int prise)
{
	this->name = name;
	this->prise = prise;
	//this->count++;
}

void Audio::Show_audio()
{
	cout << "\t Name: " << this->name << "\n\t Prise: " << this->prise << endl;
}

void Audio::Buy()
{
	cout << " Enter name to buy: ";
	cin >> this->name;
	cout << " Enter prise: ";
	cin >> this->prise;
}


Audio::~Audio()
{
}
