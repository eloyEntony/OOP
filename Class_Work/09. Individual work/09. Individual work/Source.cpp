#include<iostream>
#include"Fraction.h"
/*
Визначити клас Дріб(чисельник та знаменник - цілі).
Визначити для класу:
	o конструктор за замовчуванням( дріб 0/1 )
	o конструктор з 1 параметром (знаменник = 1)
	o конструктор з 2 параметрами( передбачити валідацію для знаменника)
	o методи доступу до полів класу
	o метод виводу дробу на екран у вигляді чисельник / знаменник
	o метод скорочення дробу
Операції
	o додавання(+) двох дробів(глобальна функція)
	o віднімання(-) двох дробів(дружня глобальна функція)
	o множення(*) двох дробів(метод класу)
	o ділення(/) двох дробів(метод класу)
	o (++) 2 форми, збільшення дробу на 1(методи класу)
	o (--) 2 форми, зменшення дробу на 1(глобальні функції)
	o порівняння дробів (==, !=) (глобальні функції)
	o порівняння дробів(>, <) (методи класу)
	o перетворення до типу int, що повертає цілу частину дробу, наприклад, для дробу
10/4 ціла частина рівна 2
	o перетворення до типу double, що повертає десятковий дріб, наприклад, звичайному
дробу 10/4 відповідає десятковий дріб 2.5

Валідація: знаменник не повинен дорівнювати нулю, знаменник не повинен бути
від’ємним(тобто дріб 1/ -2 перетворювати у -1/ 2)
Перевірити роботу класу

*/
void Adding_fractions(int x, int y, Fraction & f1, Fraction & f2) {

	int y1 = f1.Get_y();
	int y2 = f2.Get_y();	

	int newX = 0;
	int newY = 0;

	if (y1 == y2) {
		x = f1.Get_x() + f2.Get_x();
		cout << " Adding fractions :::> " << x << "/" << y << endl;
	}
	else {
		newX = (f1.Get_x() * f2.Get_y()) + (f2.Get_x() * f1.Get_y());
		newY = (f1.Get_y() * f2.Get_y());

		int nod = f1.NOD(newX, newY);
		cout << " Adding fractions :::> " << newX/nod << "/" << newY/nod << endl;
	}
}

void Subtraction_of_fractions(Fraction &f1, Fraction &f2)
{
	int newX = 0;
	int newY = 0;

	if (f1.y == f2.y){
		newX = f1.x - f2.x;
		newY = f1.y;
		cout << " Subtraction fractions :::> " << newX << "/" << newY << endl;
	}
	else{
		newX = (f2.y*f1.x) - (f1.y*f2.x);
		newY = (f1.y*f2.y);

		int nod = f1.NOD(newX, newY);
		cout << " Subtraction fractions :::> " << newX/nod << "/" << newY/nod  << endl;
	}
}

void Minus_Minus(Fraction &f1) {

	int newX = f1.Get_x();
	int newY = f1.Get_y();

	newX--;
	newY--;

	f1.Set_x(newX);
	f1.Set_y(newY);

	f1.Show_fraction();
}

void operator==(Fraction &f1, Fraction &f2) {

	if (f1.Get_x() == f2.Get_x() && f1.Get_y() == f2.Get_y())	{
		cout << " f1 == f2" << endl;
	}
	else {
		cout << "f1 != f2" << endl;
	}
}

int main()
{
	int x = 0;
	int y = 0;
	

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


	//f1.Reducing_fraction();	
	//Adding_fractions(x, y, f1, f2);
	//Subtraction_of_fractions(f1, f2);
	//f1.Multiplication_of_fractions(f2);
	//f1.Fraction_division(f2);
	//f1.Plus_Plus(); 	f1.Show_fraction();
	//Minus_Minus(f1);
	//f1 == f2;

	f1.operator>(f2);

	system("pause");
	return 0;
}