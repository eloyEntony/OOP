#include<iostream>
#include<string>
#include<fstream>
#include <vector>

using namespace std;

/*
Скласти програму, що забезпечує створення щоденного та тижневого звіту 
продажів для деякого магазину у форматі текстового файлу та html-файлу. 
Використати патерн Міст.
*/

class Store {
protected:
	int product;
public:
	Store(int str):product(str){}
	virtual string Get_product() const = 0;
};

class Report {
public:
	virtual string Get_report() const = 0;
};

class Week_report : public Report {
public:	
	string Get_report() const {
		
		string path = "report_week.html";
		ofstream inFile;

		inFile.open(path);
			inFile << "produkt" << endl;
		
		inFile.close();

		return "OK week report";
	}
};

class Day_report : public Report {
public:
	string Get_report() const {

		string path = "report_day.html";
		ofstream inFile;

		inFile.open(path);
		inFile << "produkt" << endl;

		inFile.close();

		return "OK day report";
	}
};

class My_store : public Store {
protected:
	Report *report;
public:
	My_store(Report* report, int str = 0) : Store(str), report(report) {	};
	string Get_product() const {
		return "My store " + report->Get_report();
	}
};


int main() {

	Report *report = new Week_report();
	Report *report1 = new Day_report();

	vector<Store*>store;

	int product;
	cout << " Enter produnkt id day : ";
	cin >> product;

	store.push_back(new My_store(report, product));
	store.push_back(new My_store(report1, product));
	

	for (auto el : store)
	{
		cout << el->Get_product() << endl;
		delete el;
	}

	system("pause");
	return 0;
}