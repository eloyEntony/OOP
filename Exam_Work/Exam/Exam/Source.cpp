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
	float s;		// площа
	int over;		// поверх
	string area;    // район

public:
	
	Apartments() {	//конструктор
		Exchange_request();
	};

	void Exchange_request() { //заявкa на обмін, заповнення екземпляру
		
		cout << "\n\t <<<Create request >>> \n" << endl;
		cout << " Enter room   : ";
		cin >> this->rooms;
		cout << " Enter S      : ";
		cin >> this->s;
		cout << " Enter over   : ";
		cin >> this->over;
		cout << " Enter area   : ";
		cin.ignore();
		getline(cin, this->area);
	}

	void Show() {
		cout << "---------------------------------" << endl;		
		cout << " ROOM  : " << this->rooms << endl;
		cout << " S     : " << this->s << endl;
		cout << " OVER  : " << this->over << endl;
		cout << " AREA  : " << this->area << endl;
		//cout << "---------------------------------" << endl;
	}

	int Get_room() { return this->rooms; }
	int Get_over() { return this->over; }
	float Get_s() { return this->s; }

	~Apartments() {};	
};


void Serch(vector<Apartments> &first) {
	Apartments my_card;
	bool exit = false;
	for (int i = 0; i < first.size(); i++) {
		float temp = first[i].Get_s() * 0.10;
		if ((first[i].Get_room() == my_card.Get_room()) && (first[i].Get_over() == my_card.Get_over()) && ((my_card.Get_s() >= (first[i].Get_s() - temp)) && (my_card.Get_s() <= (first[i].Get_s() + temp)))) 
		{													//пошук схожого екземпляра класу
			cout << " >>>[ DELETE ]<<< " << endl;			
			first.erase(first.begin()+i);					// якщо є схожий тоді з вектора видаляється
			exit = true;									// викідає з циклу якщо найшло зхожий
			break;
		}					
	}
	if (!exit) {
	cout << " >>>[ ADD ]<<< " << endl;
	first.push_back(my_card);		//якщо схожого немає, цей що шукали додається у вектор
	}
}


void Menu() {
	vector<Apartments> cartoteka;	
	int choise;
	bool exit = false;

	while (!exit) {

		cout << " ------------------- CARTOTEKA --------------------" << endl;
		cout << "\n ~[1] CREATE \n ~[2] SEARCH\n ~[3] SHOW\n ~[0] EXIT\n" << endl;
		cout << " Enter your choise : ";
		cin >> choise;
		
		switch (choise)
		{
			case 1:			
				cout << "\n ------------------- CREATE --------------------" << endl;
				cout << " Enter count : ";
				cin >> choise;
				for (int i = 0; i < choise; i++) { cartoteka.push_back(Apartments()); }	//створення відповідної кількості контейнерів вектора
				break;

			case 2:
				cout << "\n ------------------- SEARCH --------------------" << endl;				
				Serch(cartoteka);
				break;

			case 3:
				cout << "\n ------------------- SHOW --------------------" << endl;
				for (int i = 0; i < cartoteka.size(); i++) {
					cartoteka[i].Show();				//вивід вектора
				}
				break;

			case 0:
				exit = true;
				break;

			default:
				break;
		}
	}	
}

int main() {
	Menu();	
	return 0;
}