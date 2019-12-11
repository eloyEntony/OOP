#include<iostream>
#include<string>

using namespace std;


/* Задание №4 Напишите шаблон функции, которая возвращает минимум из двух переданных параметров.  */

//template<typename T1, typename T2>
//void Return_min(T1 a, T2 b)
//{
//	if (a < b)
//		cout << " " << a << " < " << b << endl;
//	else if (a > b)
//		cout << " " << a << " > " << b << endl;
//	else
//		cout << " " << a << " = " << b << endl;
//}
//
//
//int main()
//{	
//	Return_min(2, 5);
//	Return_min(5.5, 2.1);
//	Return_min(5, 5);
//
//	system("pause");
//	return 0;
//}

/* Задание 1 Создайте класс Circle (окружность): 
■ Реализуйте через перегруженные операторы; 
■ Проверка на равенство радиусов двух окружностей (операция ==); 
■ Сравнения длин двух окружностей (операция >). Пропорциональное изменение размеров окружности, путем изменения ее радиуса (операция += и -=) */


//class Circle {
//
//	float radius;
//	float const pi = 3.14;
//	float circuit;
//
//
//public:
//	Circle() {};
//
//	Circle(float radius)
//	{
//		this->radius = radius;
//	}
//
//	Circle &operator==(const Circle &other) {
//		if (this->radius == other.radius){
//			cout <<this->radius <<" == " <<other.radius<< endl;
//		}
//		else
//			cout << this->radius << " != " << other.radius << endl;
//
//		return *this;
//	}
//
//	Circle &operator+=(const float p)	{
//		this->radius += p;
//		cout << " RADIUS : " << radius << endl;
//		return *this;
//	}
//
//	Circle &operator-=(const float p)	{
//		if (p > this->radius) {
//			cout << " No. Too large variable   ";
//			cout << " RADIUS : " << radius << endl;
//			return *this;
//		}
//		else {
//			this->radius -= p;
//			cout << " RADIUS : " << radius << endl;
//			return *this;
//		}
//	}
//
//	Circle &operator>(const Circle &other) {
//		if (this->circuit > other.circuit)
//		{
//			cout << " " << this->circuit << " > " << other.circuit << endl;
//		}
//		else
//			cout << " The comparison is incorrect " << endl;
//	}
//
//	void C(float radius){
//		circuit = 2 * pi*radius;
//		cout << " Circuit : " << circuit << endl;
//	}
//};
//
//
//int main()
//{	
//	Circle a(2.2);
//	Circle b(2.3);
//
//	a == b;
//
//	a.C(2.2);
//
//	a += 3;
//	a -= 10;
//
//	a > b;
//
//	system("pause");
//	return 0;
//}

/*
Задание 2 Создать класс Airplane (самолет) С помощью перегрузки операторов реализовать: 
■ Проверка на равенство типов самолетов (операция ==) 
■ Увеличение и уменьшение пассажиров в салоне самолета (операции ++ и -- в префиксной форме) 
■ Сравнение двух самолетов по максимально возможному количеству пассажиров на борту (операция >)   */

class Airplane
{
	string type;
	int count_passenger;
	int max_passenger;

public:	

	Airplane()
	{
		cout << " Enter airplane type [string]         : ";
		cin >> this->type;
		cout << " Enter airplane max passengrs [int]   : ";
		cin >> this->max_passenger;
		cout << " Enter airplane passenger NOW [int]   : ";
		cin >> this->count_passenger;
		if (this->count_passenger > this->max_passenger)
			this->count_passenger = this->max_passenger;	
		cout << endl;
	}

	void Show_info() {

		cout << "  Airplane type           :: " << this->type<<endl;
		cout << "  Airplane MAX passengers :: " << this->max_passenger << endl;
		cout << "  Airplane passengers NOW :: " << this->count_passenger << endl;
		cout << endl;
	}

	bool operator==(Airplane&other)
	{
		return this->type == other.type;
	}

	Airplane &operator++()
	{
		++this->count_passenger;

		if (this->count_passenger > this->max_passenger) {
			this->count_passenger = this->max_passenger;
			cout << " Count passenger can't be more MAX : " << this->count_passenger << endl;
		}
			
		else
		cout << " Count passenger : " << this->count_passenger << endl;
		return *this;
	}

	Airplane &operator--()
	{
		--this->count_passenger;
		cout << " Count passenger : " << this->count_passenger << endl;
		return *this;
	}

	bool operator>(Airplane&other)
	{
		return this->max_passenger > other.max_passenger;
	}
};

int main()
{
	Airplane A1;
	Airplane A2;
	cout << "========================================\n" << endl;
	A1.Show_info();
	A2.Show_info();

	if (A1 == A2)
		cout << " Airplane 1 and 2 have the same type   " << endl;
	else
		cout << " Planes have different types " << endl;

	++A1;
	--A2;

	if (A1 > A2)
		cout << " Airplane 1 is bigest " << endl;
	else
		cout << " Airplane 2 is bigest " << endl;


	cout << "========================================\n" << endl;
	A1.Show_info();
	A2.Show_info();

	system("pause");
	return 0;
}