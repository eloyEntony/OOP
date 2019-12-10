#include "Book.h"



Book::Book()
{
	cout << " Enter name book  : ";
	cin >> this->name;
	cout << " Enter publishing : ";
	cin >> this->publishing;
	cout << " Enter avtor      : ";
	cin >> this->avtor;
	cout << " Enter price      : ";
	cin >> this->price;
	//cout << " New book ? [1/0] : ";
	//cin >> this->new_book;

	cout << "\n|||||||||||||||||||||||||||||||||||\n" << endl;
}



void Book::Show_info()
{
	cout << endl;
	cout << "---------------------------------------------" << endl;
	cout << " NAME        : " << this->name << endl;
	cout << " PUBLISHING  : " << this->publishing << endl;
	cout << " AVTOR       : " << this->avtor << endl;
	cout << " PRICE       : " << this->price << endl;
	//cout << " NEW BOOK ?  : " << this->new_book << endl;
}

int Book::Get_price()
{
	return this->price;
}

Book::~Book(){}
