#include "Shop.h"



Shop::Shop()
{
}

Shop::Shop(string name, int money)
{
	this->name = name;
	this->money = money;
}

void Shop::Show_shop()
{
	cout << "\t SHOP: " << "\n===Name: " << this->name << "\n===Money: " << this->money << endl;
}


void Shop::Show_product(Book & book, Audio &audio, Megazine &megazine)
{
	cout << "\n >>> BOOK : " << endl;
	book.Show_book();

	cout << "\n >>> AUDIO : " << endl;
	audio.Show_audio();

	cout << "\n >>> MEGAZINE : " << endl;
	megazine.Show_magazine();

	cout << "\n\n";
}

void Shop::Buy_product()
{
	cout << " Enter what you want to buy: ";
	Book newBook;
	Megazine newMeg;
	Audio newAudio;

	int choise;
	bool exit = false;

	while (!exit)
	{
		cout << "\n [1] Book \n [2] Megazine\n [3] Audio\n [0] Exit" << endl;
		cin >> choise;

		switch (choise)
		{
		case 1:
			cout << " You buy book";			
			newBook.Buy();
			break;

		case 2:
			cout << " You buy megazine";
			
			newMeg.Buy();
			break;

		case 3:
			cout << " You buy audio";
			
			newAudio.Buy();
			break;

		case 0:
			exit = true;
		default:
			break;
		}
	}


}

void Shop::Sell_product()
{
	cout << " Enter what you want to sell: ";
	

	int choise;
	bool exit = false;

	while (!exit)
	{
		cout << "\n [1] Book \n [2] Megazine\n [3] Audio\n [0] Exit" << endl;
		cin >> choise;

		switch (choise)
		{
		case 1:
			cout << " You sell book";
			
			break;

		case 2:
			cout << " You sell megazine";

			
			break;

		case 3:
			cout << " You sell audio";

			
			break;

		case 0:
			exit = true;
		default:
			break;
		}
	}

}

Shop::~Shop()
{
}
