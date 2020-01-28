	/*1. Написати програму обліку заявок на обмін квартир і пошуку варіантів обміну.
	Кожна заявка містить дані про дві квартири : необхідної(шуканої) і наявної.

	Дані про кожну квартиру містять : кількість кімнат, площу, поверх, район.

	Програма повинна забезпечувати вибір за допомогою меню і виконання однієї
	наступних функцій :
		 введення заявки на обмін;
		 пошук у картотеці потрібного варіанта :

		при співпадінні вимог і	пропозицій : 
			при співпадінні по кількості кімнат і поверховості і
			розходженні по показнику «площа» у межах 10 % виводиться відповідна
			картка і видаляється зі списку, 
			
			у противному випадку заявка, що
			надійшла, включається до картотеки;

		 вивід усієї картотеки.

	Для збереження даних картотеки використовувати контейнерний клас vector.*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Apartments {

	int rooms;		// кімнати
	float s;		//площа
	int over;		//поверх
	string area;    // район

public:

	Apartments() {	
		Exchange_request();
	};


	void Exchange_request() { //заявкa на обмін

		cout << "Create request >>> " << endl;
		cout << " Enter room : ";
		cin >> this->rooms;
		cout << " Enter S : ";
		cin >> this->s;
		cout << " Enter over : ";
		cin >> this->over;
		cout << " Enter area : ";
		cin.ignore();
		getline(cin, this->area);

	}

	void Serch(int room, int over, float s) {

		if ((this->rooms = room) && (this->over = over) && ( this->s * 0.1 > s * 0.1 || this->s * 0.1 < s * 0.1)) {

			Show();
		}


	}

	void Show() {
		cout << "\n---------------------------------" << endl;
		cout << " ROOM : " << this->rooms << endl;
		cout << " S    : " << this->s << endl;
		cout << " OVER : " << this->over << endl;
		cout << " AREA : " << this->area << endl;
		cout << "---------------------------------" << endl;
	}

	~Apartments() {};

};

int main() {

	int room;
	int over;
	float s;

	vector<Apartments> cartoteka;
		
	/*cartoteka.push_back(Apartments());
	
	cout << "\n---------------- SEARCH -----------------" << endl;

	cout << " Enter search room : ";
	cin >> room;
	cout << " Enter search over : ";
	cin >> over;
	cout << " Enter search S : ";
	cin >> s;


	for (int i = 0; i < cartoteka.size(); i++) {

		cartoteka[i].Serch(room, over, s);
	}*/


	float a ;
	float b ;

	cin >> a >> b;

	float f = a * 0.1;
	float g = b * 0.1;

	if (f==g) {
		cout << "Good" << endl;
	}


	system("pause");
	return 0;
}