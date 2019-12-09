#include "CShop.h"


template <typename T>
CShop<T>::CShop()
{
}

template<typename T>
CShop<T>::CShop(int size)
{
	this->size = size;
	this->arr = new T[this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i];
	}
}

template<typename T>
void CShop<T>::Show_info()
{
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i].ShowInfo();
	}

	cout << endl;
}

template <typename T>
CShop<T>::~CShop(){}
