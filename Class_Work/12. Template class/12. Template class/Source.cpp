#include <iostream>
#include <string>
#include"CShop.h"
#include"Book.h"
#include"Audio.h"
#include"Megazine.h"
using namespace std;

int main() {
	

	CShop <Book> shop_b(3);
	shop_b.Show_info();
	cout << "\n=============================================" << endl;
	shop_b.Most_expensive();
	cout << "\n=============================================" << endl;
	shop_b.Cheapest_product();
	cout << "\n=============================================" << endl;
	shop_b.Average_price();

	/*CShop <Audio> shop_a(1);
	shop_a.Show_info();

	CShop <Megazine> shop_m(1);
	shop_m.Show_info();*/

	system("pause");
	return 0;
}