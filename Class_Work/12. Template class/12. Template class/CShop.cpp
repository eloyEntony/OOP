#include "CShop.h"



CShop::CShop()
{
}

template<typename T>
CShop<T>::CShop(int size)
{
	for (int i = 0; i < 2; i++)
	{
		book[i].name = "Azbyka";
		book[i].avtor = "I am";
		book[i].publishing = "I am";
		book[i].price = 3;
		book[i].new_book = 1;
	}
}

template<typename T>
void CShop<T>::Show()
{
	for (int i = 0; i < 2; i++)
	{
		book[i].Show_book();
	}
}


CShop::~CShop()
{
}
