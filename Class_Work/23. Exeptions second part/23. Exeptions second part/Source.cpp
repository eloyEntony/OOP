#include <iostream>
#include<string>
#include<fstream>
using namespace std;

/*
Написати програму, яка дозволяє записувати в файл інформацію про результати сесії (оцінки) певної групи студентів. 
Організувати зчитування даної інформації з файлу та підрахунок середнього балу в групі.
Використайте, розроблені в уроці 6 класи Group ("Група") та Student ("Студент"). 
Додати методи Save() та Read() для запису та зчитування обєктів в/з файла.

Додаткове необов'язкове завдання (додаткових 12 балів)
Написати програму, яка виводить статистику по вказаному користувачем файлу в наступному вигляді:
кількість коротких слів (який складається максимум з 10 символів);
кількість великих слів;
кількість цифр;
кількість символів пунктуації, наприклад, (!), (,), (.), (-).
Крім того, у відповідь на написанення довільної клавіши або на певний пункт меню, здійснити заміну всіх цифр в файлі на символи (*), а додатково (на 12 балів) зробити видалення всіх символів пунктуації.
*/

class Group {

	string group_name;
	double average_malrk_group;
	

	class Student {

		string student_name;
		int arr[5];
		double average_mark = 0;

	public:

		Student() {};
		void Fill_student() {
			cout << " Enter name : ";
			cin.ignore();
			getline(cin, this->student_name);
			cout << " Enter Student mark : " << endl;;
			for (int i = 0; i < 5; i++) {
				cout << i + 1 << " : ";
				cin >> arr[i];
			}
		}

		void Show_info_student() {
			cout << " Name : " << this->student_name << endl;
			cout << " Mark : ";
			for (int i = 0; i < 5; i++) {
				cout <<  this->arr[i] << " | ";
			}
			cout << "\n______________________________" << endl;
		}

		double Average_mark() {
			double sum = 0;
			for (int i = 0; i < 5; i++) {	sum += arr[i];	}			
			this->average_mark = sum / 5;
			//cout << " Average mark -> " << this->average_mark << endl;
			return this->average_mark;
		}

		void Write(int size, string path) {
			ofstream writeFile;
			writeFile.open(path, ofstream::app);
			writeFile << size << endl;
			writeFile << this->student_name<<endl;
			for (int i = 0; i < 5; i++) {
				writeFile << this->arr[i] << endl;
			}			
			writeFile << this->average_mark << endl;
			writeFile.close();

		}

		void Set_name(string name) { this->student_name = name; }
		void Set_mark(int mark[]) {
			for (int i = 0; i < 5; i++) {
				this->arr[i] = mark[i];
			}
		}
		void Set_average_mark(double average) { this->average_mark = average; }

	};

	Student *student;

public:

	Group() {};

	void Create_group(int size) {	
		student = new Student[size];

		for (int i = 0; i < size; i++) {
			student[i].Fill_student();
		}
	}	
	void Show_group(int size) {

		cout << "\n Show group : \n" << endl;
		for (int i = 0; i < size; i++) {
			student[i].Show_info_student();
		}
	}

	void Average_mark_of_group(int size) {
		double sum = 0;
		for (int i = 0; i < size; i++){		sum += student[i].Average_mark();	}
		this->average_malrk_group = sum/size;
		cout << " Average mark of group : " << this->average_malrk_group << endl;
	}

	void Save(int size, string path) {		
		ofstream writeFile;
		writeFile.open(path);		
		for (int i = 0; i < size; i++) {
			student[i].Write(size, path);
		}
		writeFile.close();
	}

	void Read(int size, string path) {

		path = "data.txt";
		int Size = 0;
		string name;
		double average;
		int mark[5];

		ifstream myFile;
		myFile.exceptions(ifstream::badbit | ifstream::failbit);  // Only for ifstream (Demo)

		try {
			myFile.open(path);
			cout << "\n ->>> Successfuly open and close file \n" << endl;
			myFile >> Size;

			student = new Student[Size];
		

			myFile.close();
		}
		catch (...) {
			//cout << error.what() << endl;
			cout << "\n ->>> Error open file.\n" << endl;
		}
	}

	
	
};

int main()
{
	string path = "data.txt";
	int size;
	cout << " Enter size of group : ";
	cin >> size;

	Group mygroup;

	/*mygroup.Create_group(size);

	mygroup.Average_mark_of_group(size);

	mygroup.Save(size, path);*/

	mygroup.Read(size, path);

	system("pause");
	return 0;
}