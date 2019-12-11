#include<iostream>
#include"Var.h"


/*
	Реалізувати клас Var («Універсальна змінна»). Об’єкти цього класу можуть зберігати в
собі значення наступних типів: 
int,
double,
String(рядок; клас, який був створений раніше ).

	Наприклад:
void main()
{
	Var a = 15;
	Var b = "Hello";
	Var c = 7.8;
	Var d = "50";

	b = a + d;
	cout << b; //отримаємо 65
	if (a == b)
	cout << "Equal" << endl;
	else
	cout << "Not Equal" << endl;

}
Для класу Var необхідно перевантажити:
o арифметичні оператори: +, -, *, /, +=, -=, *=, /=
o оператори порівняння: <, >, <=, >=, ==, !=
o оператори << >>;
Додати також до класу Var приведення до типу: int, double, char*.

	Основні моменти:

o В змінній типу Var в довільний момент часу може знаходитись лише одне
значення( або int, або double, або String).
o Тип значення зберігається у додатковому приватному полі(enum або char)
наприклад: char type; // 'i' -- int, 'd' -- double, 'і' -- String, '\0' -- непроініціалізований об'єкт 

	При перевантаженні операторів слід врахувати наступне: 

o якщо при виконанні операції типи значень двох операндів типу Var різні, тоді
необхідно приводити (конвертувати) значення другого операнду до типу значення
першого операнду і тільки після цього виконувати операцію.
o При цьому значення і тип другого операнду в самому об’єкті Var не змінюється. 

	Наприклад:
	Var a(10), b = "120", c, d = "str";

	c = a + b;
	cout << c; //отримаємо 130
	c = a + d;
	cout << c; //отримаємо 10, оскільки приведення 'str' до int дає 0
	c = b + a;
	cout << c; //отримаємо "12010"
	*/

int main()
{
	Var a=117;
	a.Show_info();
	cout << "\n\n";

	Var a1 = 3;

	Var b=5.5;
	b.Show_info();
	cout << "\n\n";

	Var c ("Hello");
	c.Show_info();
	cout << "\n\n";

	Var c1("12Anton");

	Var d("50");
	d.Show_info();
	cout << "\n\n";

	//a + c1;
	/*a += a1;
	cout << endl;

	a -= a1;
	cout << endl;

	a *= a1;
	cout << endl;

	a /= a1;
	cout << endl;

	if (a == a1)
		cout << " Equal" << endl;
	else
		cout << " Not Equal" << endl;*/
	

	/*c += c1;
	cout << endl;
	c.Show_info();*/

	/*a + a1;
	cout << endl;
	a + b;
	cout << endl;
	b + a;
	cout << endl;
	a + d;
	cout << endl;
	b + d;
	cout << endl;
	d + a;
	cout << endl;
	d + b;
	cout << endl;
	c + d;
	cout << endl;
	d + c;*/

	cout << "\n\n";
	
	

	system("pause");
	return 0;
}

