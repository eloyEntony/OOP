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

// code by V1tos https://github.com/V1tos/ClassWork-OOP/blob/master/Lesson%2023%20-%20Control%20task%20(Exchanging%20tickets)/Lesson%2023%20-%20Control%20task%20(Exchanging%20tickets)/Source.cpp


#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <fstream>
#include <algorithm>

using namespace std;

class Flat
{
	unsigned short rooms_count;  //kilkist kimnat
	unsigned short flat_square;  //ploscha
	unsigned short floor;        //poverh  
	string district;             //rayon
	float price;		//price

public:
	Flat(unsigned short rooms_count = 0, unsigned short flat_square = 0, unsigned short floor = 0, string district = nullptr, float price = 0) { //констуктор
		this->rooms_count = rooms_count;
		this->flat_square = flat_square;
		this->floor = floor;
		this->district = district;
		this->price = price;
	}
	void ShowInfo() { //показ 
		cout << "\n\t Room's count    :    " << rooms_count <<
		    	"\n\t Square          :    " << flat_square << 
			    "\n\t Floor           :    " << floor << 
			    "\n\t District        :    " << district << 
			    "\n\t Price           :    " << price << "\n";
	}

	bool operator==(Flat &other) //перегружений оператор
	{
		bool checkDif = false;
		double difference = 0;

		if (this->flat_square > other.flat_square){ //якщо площа цієї більша за прощу іншої
			difference = this->flat_square - other.flat_square;
			if (difference <= double(this->flat_square*0.1))
			{
				checkDif = true;
			}

		}
		else{//в іншому випадку
			difference = other.flat_square - this->flat_square;

			if (difference <= double(this->flat_square*0.1))
			{
				checkDif = true;
			}
		};
		if (this->rooms_count == other.rooms_count && checkDif && this->floor == other.floor){
			return true;
		}
		else
		{
			false;
		}
	}
	~Flat() {};

	string Get_district() {
		return this->district;
	}

	float Get_price() {
		return this->price;
	}

	friend void WriteFileFind(vector <Flat> &finding_flat);
	friend void WriteFileExchange(vector <Flat> &exchanging_flat);
	friend void ReadFileFind(vector <Flat> &finding_flat);
	friend void ReadFileExchange(vector <Flat> &exchanging_flat);

};

void ShowData(vector <Flat> &finding_flat, vector <Flat> &exchanging_flat ) { //показ 
	int i = 0;
	while (i < exchanging_flat.size()){
		cout << "\n Data N" << i + 1 << endl;
		cout << " Finding parameters :\n";
		finding_flat.at(i).ShowInfo();
		cout << "\n Exchanging parameters :\n";
		exchanging_flat.at(i).ShowInfo();
		cout << "\n";
		i++;
	}
}

void AddFlat(vector <Flat> &finding_flat, vector <Flat> &exchanging_flat) {

	unsigned short rooms_count;
	unsigned short flat_square;
	unsigned short floor;
	string district;



	cout << " Enter finding flat's parameters:\n";              //Yaku hoche kvartyru
	cout << " Enter room's count: ";
	cin >> rooms_count;
	cout << " Enter flat's square: ";
	cin >> flat_square;
	cout << " Enter flat's floor: ";
	cin >> floor;
	cout << " Enter flat's district: ";
	cin >> district;


	Flat find(rooms_count, flat_square, floor, district);
	cout << " Ready.\n";
	system("pause");
	system("cls");


	cout << " Enter exchanging flat's parameters:\n";           //Yaku maye kvartyru
	cout << " Enter room's count: ";
	cin >> rooms_count;
	cout << " Enter flat's square: ";
	cin >> flat_square;
	cout << " Enter flat's floor: ";
	cin >> floor;
	cout << " Enter flat's district: ";
	cin >> district;

	Flat exchange(rooms_count, flat_square, floor, district);
	cout << " Ready.\n";
	system("pause");
	system("cls");
	   	  


	int i = 0;
	bool check = false;


	while (i < exchanging_flat.size())
	{
		if (find.operator==(exchanging_flat.at(i)) == true && exchange.operator==(finding_flat.at(i)) == true)
		{
			system("cls");
			char choice;
			cout << " Similar parameters have been found to exchange : \n";
			cout << " Data N " << i + 1 << endl;
			cout << "\n Finding parameters of client:\n";
			finding_flat.at(i).ShowInfo();
			cout << endl;

			cout << "\n Exchanging parameters of client:\n";
			exchanging_flat.at(i).ShowInfo();
			cout << endl;
			cout << "\n\n Do you want to exchange? (y/n): ";
			cin >> choice;
			switch (choice)
			{
			case 'y':
				system("cls");
				finding_flat.erase(finding_flat.begin() + i);
				exchanging_flat.erase(exchanging_flat.begin() + i);
				cout << "\n Exchanged!!\n";
				i = exchanging_flat.size() + 1;
				check = true;
				break;
			case 'n':
				check = false;
				break;
			default:
				cout << " Wrong choice!!";
				break;
			}
		}
		i++;
	}

	if (!check){
		finding_flat.push_back(find);
		exchanging_flat.push_back(exchange);
		cout << " Added new data\n";
	}
}

void FindExchangeFlat(vector <Flat> &finding_flat, vector <Flat> &exchanging_flat) {

	int i = 0;
	bool check = false;
	int index;

	ShowData(finding_flat, exchanging_flat);
	cout << " Choose data to exchange.\n";
	cout << " Data N";
	cin >> index;

	
	while (i < exchanging_flat.size())
	{
		if (finding_flat.at(index - 1).operator==(exchanging_flat.at(i)) == true && exchanging_flat.at(index - 1).operator==(finding_flat.at(i)) == true && i != index - 1)
		{
			check = true;
			system("cls");
			char choice;
			cout << " Similar parameters have been found to exchange:\n";
			cout << " Data N" << i + 1 << endl;
			cout << "\n Finding parameters of client:\n";
			finding_flat.at(i).ShowInfo();
			cout << endl;

			cout << "\n Exchanging parameters of client:\n";
			exchanging_flat.at(i).ShowInfo();
			cout << endl;
			cout << "\n\n Do you want to exchange? (y/n): ";
			cin >> choice;
			switch (choice)
			{
			case 'y':
				system("cls");
				finding_flat.erase(finding_flat.begin() + i);
				exchanging_flat.erase(exchanging_flat.begin() + i);
				cout << " Exchanged!!\n";
				i = exchanging_flat.size();
				check = true;
				break;
			case 'n':
				i = exchanging_flat.size();
				break;
			default:
				cout << " Wrong choice!!";
				i = exchanging_flat.size();
				break;
			}
		}
		i++;
	}

	if (!check){
		cout << " Didn't find similar parameters!\n";

	}
}

void WriteFileFind(vector <Flat> &finding_flat) { //запис у файл, знайдених
	
	
	ofstream writeFile("Find.txt");
	/*if (!writeFile.is_open()) {
		cout << " Can't open file!\n";
	}
	else{
		int size = finding_flat.size();
		writeFile.write((const char*)&size, 4);
		writeFile.write((const char*)&finding_flat[0], size * sizeof(Flat));
	}
	writeFile.close();*/
		

	if (!writeFile.is_open()) {
		cout << "Can't open file" << endl;
	}
	else {
		writeFile << finding_flat.size() << endl;
		for (int i = 0; i < finding_flat.size(); i++) {
			writeFile << finding_flat[i].rooms_count << endl;
			writeFile << finding_flat[i].flat_square << endl;
			writeFile << finding_flat[i].floor << endl;
			writeFile << finding_flat[i].district << endl;
			writeFile << finding_flat[i].price << endl;
		}
	}
	writeFile.close();
}

void WriteFileExchange(vector <Flat> &exchanging_flat) { //запис у файл, на обмін

	/*ofstream writeFile("Exchange.txt");
	if (!writeFile.is_open()) {
		cout << " Can't open file!\n";
	}
	else
	{
		int size = exchanging_flat.size();
		writeFile.write((const char*)&size, 4);
		writeFile.write((const char*)&exchanging_flat[0], size * sizeof(Flat));
	}

	writeFile.close();*/	
	ofstream writeFile("Exchange.txt");
	if (!writeFile.is_open()) {
		cout << "Can't open file" << endl;
	}
	else {
		writeFile << exchanging_flat.size() << endl;
		for (int i = 0; i < exchanging_flat.size(); i++) {
			writeFile << exchanging_flat[i].rooms_count << endl;
			writeFile << exchanging_flat[i].flat_square << endl;
			writeFile << exchanging_flat[i].floor << endl;
			writeFile << exchanging_flat[i].district << endl;
			writeFile << exchanging_flat[i].price << endl;
		}
	}
	writeFile.close();
}

void ReadFileFind(vector <Flat> &finding_flat) { //читання з файлу найдених
			
	ifstream readFile;
	char temp[255];
	int rooms_count;
	float flat_square;
	int floor;
	string district;
	float price;

	readFile.open("Find.txt");

	if (!readFile.is_open()) {
		cout << "Can't open file!\n";
	}
	else{
		int size = 0, i = 0;
		readFile.getline(temp, 255);
		size = atoi(temp);

		while (i < size){
			readFile.getline(temp, 255);
			rooms_count = atoi(temp);
			readFile.getline(temp, 255);
			flat_square = atoi(temp);
			readFile.getline(temp, 255);
			floor = atoi(temp);
			readFile.getline(temp, 255);
			district = temp;
			readFile.getline(temp, 255);
			price = atoi(temp);

			finding_flat.push_back(Flat(rooms_count, flat_square, floor, district, price));
			i++;
		}
	}
	readFile.close();
}

void ReadFileExchange(vector <Flat> &exchanging_flat) {	
	//читання з файлу на обмін	

	ifstream readFile;
	char temp[255];
	int rooms_count;
	float flat_square;
	int floor;
	string district;
	float price;

	readFile.open("Exchange.txt");

	if (!readFile.is_open()) {
		cout << "Can't open file!\n";
	}
	else{
		int size = 0, i = 0;
		readFile.getline(temp, 255);
		size = atoi(temp);

		while (i < size){
			readFile.getline(temp, 255);
			rooms_count = atoi(temp);
			readFile.getline(temp, 255);
			flat_square = atoi(temp);
			readFile.getline(temp, 255);
			floor = atoi(temp);
			readFile.getline(temp, 255);
			district = temp;
			readFile.getline(temp, 255);
			price = atoi(temp);

			exchanging_flat.push_back(Flat(rooms_count, flat_square, floor, district, price));
			i++;
		}
	}
	readFile.close();
}

void Search_by_district(vector <Flat> finding_flat, vector <Flat> exchanging_flat) {// пошук по району 
	string search_district;

	ShowData(finding_flat, exchanging_flat);

	cout << "\n >>> Enter district for search : ";
	cin.ignore();
	getline(cin, search_district);
	cout << "\n--------------------------------------------------" << endl;

	for (int i = 0; i < finding_flat.size(); i++){
		if (search_district == finding_flat[i].Get_district()) {
			cout << "\n Finding flat : ";
			finding_flat[i].ShowInfo();
		}			
	}
	
	for (int i = 0; i < exchanging_flat.size(); i++){
		if (search_district == exchanging_flat[i].Get_district()) {
			cout << "\n Exechanging flat : ";
			exchanging_flat[i].ShowInfo();
		}			
	}
}

bool Sort_price(Flat &obj, Flat &other) {
	return obj.Get_price() < other.Get_price();
}

void Sort_by_price(vector <Flat> &finding_flat, vector <Flat> &exchanging_flat) {// сортування по ціні

	vector<Flat> all_cartoteka;
	for (int i = 0; i < finding_flat.size(); i++) { //створюю загальну картеку
		all_cartoteka.push_back(finding_flat[i]);
		all_cartoteka.push_back(exchanging_flat[i]);
	}

	sort(all_cartoteka.begin(), all_cartoteka.end(), Sort_price);

	for (int i = 0; i < all_cartoteka.size(); i++) { // вивід посортованої картотеки
		cout << " ~~~~~~~~~~~~~~~~~~~ " << endl;
		all_cartoteka[i].ShowInfo();
		cout << " ~~~~~~~~~~~~~~~~~~~ " << endl;
	}
}


void Menu() {	

	bool exit = false;
	short choice = 0;
	vector <Flat> finding_flat;
	vector <Flat> exchanging_flat;

	while (!exit)
	{
		system("cls");
		cout << "=*=*=*=*=*=*=DATABASE=*MENU=*=*=*=*=*=*=\n [1] - Add data\n [2] - Find possible exchanges\n [3] - Show data\n [4] - Search by district\n [5] - Sort by price\n " <<
			"[6] - Write to file\n [7] - Read from file\n [8] - Create standart database\n [0] - Exit\n\n >>>Your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("cls");
			AddFlat(finding_flat, exchanging_flat);
			system("pause");
			break;
		case 2:
			system("cls");
			FindExchangeFlat(finding_flat, exchanging_flat);
			system("pause");
			break;
		case 3:
			system("cls");
			ShowData(finding_flat, exchanging_flat);
			system("pause");
			break;

		case 4:
			system("cls");
			Search_by_district(finding_flat, exchanging_flat);
			system("pause");
			break;

		case 5:
			system("cls");
			Sort_by_price(finding_flat, exchanging_flat);
			system("pause");
			break;

		case 6:
			system("cls");
			WriteFileFind(finding_flat);
			WriteFileExchange(exchanging_flat);
			cout << "\n\n\t WRITE  TO  FILE >>> GOOD\n\n" << endl;
			system("pause");
			break;

		case 7:
			system("cls");
			ReadFileFind(finding_flat);
			ReadFileExchange(exchanging_flat);
			cout << "\n\n\t READ  FROM  FILE >>> GOOD\n\n" << endl;
			system("pause");
			break;

		case 8:
			system("cls");
			finding_flat.push_back(Flat(3, 87, 5, "Pivnichnuy", 3500));
			exchanging_flat.push_back(Flat(2, 60, 1, "Yubik", 4000));
			finding_flat.push_back(Flat(2, 65, 1, "Centr", 5000));
			exchanging_flat.push_back(Flat(3, 91, 5, "Basik", 2000));
			cout << "\n\n\t Create standart database >>> GOOD \n\n" << endl;
			system("pause");
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