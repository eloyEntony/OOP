#pragma once
#include <iostream>
#include <string>

using namespace std;


template <typename T>
class CShop
{	
	int size;
	T *arr;

public:
	CShop() {};

	CShop(int size)
	{
		this->size = size;
		this->arr = new T[this->size];
		for (int i = 0; i < this->size; i++)
		{
			arr[i];
		}
	};

	void Show_info()
	{
		for (int i = 0; i < this->size; i++)
		{
			arr[i].Show_info();
		}

		cout << endl;
	};

	void Most_expensive()
	{
		int max = this->arr[0].Get_price();

		for (int i = 0; i < this->size; i++)
		{
			if (arr[i].Get_price() > max) {
				max = arr[i].Get_price();
			}
		}

		for (int i = 0; i < this->size; i++)
		{
			if (arr[i].Get_price() == max)
			{
				cout << " Most expensive : ";
					this->arr[i].Show_info();
			}
		}		
	}

	void Cheapest_product() 
	{
		int min = this->arr[0].Get_price();

		for (int i = 0; i < this->size; i++)
		{
			if (arr[i].Get_price() < min) {
				min = arr[i].Get_price();
			}
		}

		for (int i = 0; i < this->size; i++)
		{
			if (arr[i].Get_price() == min)
			{
				cout << " Cheapest_product : ";
				this->arr[i].Show_info();
			}
		}
	}

	void Average_price() 
	{
		float average_price=0;
		int suma = 0;

		for (int i = 0; i < this->size; i++)
		{
			suma += arr[i].Get_price();
		}

		average_price = suma / this->size;

		cout << " Average price : " << average_price << endl;

	}

	~CShop()
	{
		arr = nullptr;
		delete[] arr;
	};
};

