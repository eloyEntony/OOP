#include<iostream>
#include"Fraction.h"

void Adding_fractions(int x, int y, Fraction & f1, Fraction & f2) {

	int y1 = f1.Get_y();
	int y2 = f2.Get_y();

	int resX = 0;
	int resY = 0;

	if (y1==y2) {
		x = f1.Get_x() + f2.Get_x();
		cout << " Adding fractions :::> " << x << "/" << y << endl;
	}

	else {

		//window.edu.ru/catalog/pdf2txt/950/79950/60322?p_page=13

	}
}


int main()
{
	int x = 0;
	int y = 0;
	int nod = 0;

	cout << " Enter 1 x: ";
	cin >> x;
	cout << " Enter 1 y: ";
	cin >> y;
	
	Fraction f1(x, y);

	cout << " Enter 2 x: ";
	cin >> x;
	cout << " Enter 2 y: ";
	cin >> y;

	Fraction f2(x, y);

	f1.Show_fraction();
	f2.Show_fraction();



	/*nod=f1.NOD(x, y);
	cout << " NOD " << nod << endl;
	*/

	Adding_fractions(x, y, f1, f2);

	system("pause");
	return 0;
}