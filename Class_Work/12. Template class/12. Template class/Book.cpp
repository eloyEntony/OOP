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
	cout << " New book ? [1/0] : ";
	cin >> this->new_book;
}



void Book::Show_book()
{
	cout << endl;
	cout << " NAME        : " << this->name;
	cout << " PUBLISHING  : " << this->publishing;
	cout << " AVTOR       : " << this->avtor;
	cout << " PRICE       : " << this->price;
	cout << " NEW BOOK ?  : " << this->new_book;
}

Book::~Book(){}
