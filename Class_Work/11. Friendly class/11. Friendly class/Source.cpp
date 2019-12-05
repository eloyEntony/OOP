#include<iostream>
#include<string>
#include"Shop.h"
using namespace std;

int main()
{
	Shop shop("Veselka", 1000);

	//Book book("Azbuka", 15);
	//Megazine meg("Forbs", 20);
	//Audio audio("Skay", 15);

	Book *book;


	shop.Show_shop();

	//shop.Show_product(book, audio, meg);

	shop.Buy_product();

	system("pause");
	return 0;
}