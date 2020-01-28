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



	void Show() {
		cout << "\n---------------------------------" << endl;
		cout << " ROOM : " << this->rooms << endl;
		cout << " S    : " << this->s << endl;
		cout << " OVER : " << this->over << endl;
		cout << " AREA : " << this->area << endl;
		cout << "---------------------------------" << endl;
	}

	~Apartments() {};

	int Get_room() {
		return this->rooms;
	}

	int Get_over() {
		return this->over;
	}

	float Get_s() {
		return this->s;
	}

	
};


void Serch(vector<Apartments> first , vector<Apartments> second) {	

	for (int i = 0; i < first.size(); i++) {

		float temp = first[i].Get_s()*0.10;

		if ((first[i].Get_room() == second[i].Get_room()) && (first[i].Get_over() == second[i].Get_over()) && (second[i].Get_s() >= (first[i].Get_s() - temp) && second[i].Get_s() <= (first[i].Get_s() + temp))) {
			first[i].Show();
		}
		else
			cout << "NOO" << endl;
	}

}

int main() {

	int room;
	int over;
	float s;

	vector<Apartments> cartoteka;
		
	vector<Apartments>my_cartoteca;


	cout << "\n---------------- CREATE -----------------" << endl;

	cartoteka.push_back(Apartments());
	
	cout << "\n---------------- SEARCH -----------------" << endl;

	my_cartoteca.push_back(Apartments());

	/*cout << " Enter search room : ";
	cin >> room;
	cout << " Enter search over : ";
	cin >> over;
	cout << " Enter search S : ";
	cin >> s;*/
	
	for (int i = 0; i < cartoteka.size(); i++) {

		Serch(cartoteka, my_cartoteca);
	}


	system("pause");
	return 0;
}