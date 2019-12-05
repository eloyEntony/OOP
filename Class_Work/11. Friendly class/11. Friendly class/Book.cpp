#include "Book.h"



Book::Book()
{
}

Book::Book(int size)
{
	this->name = name;
	this->prise = prise;
	//this->count++;
	//this->bookID = count;
	 

}

void Book::Show_book()
{
	cout << "\t Name: " << this->name << "\n\t Prise: " << this->prise << endl;
}

void Book::Buy()
{
	cout << " Enter name to buy: ";
	cin >> this->name;
	cout << " Enter prise: ";
	cin >> this->prise;
}


Book::~Book()
{
}
