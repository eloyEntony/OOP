#include "Book.h"



Book::Book()
{
}

Book::Book( int size)
{
	
	
}

void Book::Show_book()
{
	cout << " NAME : " << this->name;
	cout << " publishing : " << this->publishing;
	cout << " AVTOR: " << this->avtor;
	cout << " PRICE : " << this->price;
	cout << " NEW BOOK ? " << this->new_book;
}


Book::~Book()
{
}
