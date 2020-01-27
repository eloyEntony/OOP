#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;

/*int main(){

	vector<int> vArr;

	vArr.push_back(5);
	vArr.push_back(12);
	vArr.push_back(2);

	//vArr.pop_back();

	vArr.push_back(2);
	vArr.push_back(7);
	vArr.push_back(9);
	vArr.push_back(100);

	vArr.pop_back();

	//cout << "SiZE : " << vArr.size() << endl;

	//vArr.clear();

	//cout << "SiZE : " << vArr.size() << endl;

	//for (int i = 0; i < vArr.size(); i++) {
	//	//cout << vArr[i] << endl;
	//	cout << vArr.at(i) << endl;
	//}

	//vArr.clear();

	////vArr.reserve(50); //виділяє память
	//
	//vArr.push_back(2);
	//vArr.push_back(7);
	//vArr.push_back(9);
	//vArr.push_back(100);

	//vArr.at(10) = 100;


	cout << "SiZE : " << vArr.size() << endl;//Скільки наявних даних
	//cout << vArr.capacity() << endl;

	////////////////////////////////////////

	vector<int>::iterator i;

	i = vArr.begin();

	//i += 2;

	cout << " ITERATOR test : " << *i << endl;

	for (vector<int>::const_iterator i = vArr.begin(); i != vArr.end(); i++) {
		//*i = 10;
		vArr.at(1) = 200;

		cout << *i << endl;
	}
	cout << "-------------------------------" << endl;
	for (vector<int>::reverse_iterator i = vArr.rbegin(); i != vArr.rend(); i++) {
		//*i = 10;
		vArr.at(1) = 200;

		cout << *i << endl;
	}

	system("pause");
	return 0;
}*/


/*
👌 Описати клас Студент(ім’я, курс, оцінка у 100-бальній системі).
👌 Перевизначити для класу оператор виводу у потік.
👌 Визначити функцію заповнення вектору(деку) студентів довільними даними
👌 Визначити функцію виводу вмісту вектору(деку).
👌 Впорядкувати вектор(дек) за іменами студентів по зростанню.
👌 Відсортувати вектор(дек) за прізвищами студентів.
👌 Знайти кількість студентів, що добре навчаються(бал >=74)
👌 Cкопіювати студентів, що добре навчаються у інший контейнер(вектор, дек чи список)
Встановити у перші три елементи вектору(деку) студентів самих молодших курсів за зростанням(partial_sort_copy).
👌 Зберегти інформацію про студентів у текстовому файлі
👌 Почитати інформацію про студентів з файлу у контейнер
*/

class Student {

	string name;
	string surname;
	string course;
	int mark;	

public:

	Student() {};

	Student(int count) {
		cout << "\n-----------------------------" << endl;
		cout << " Enter name student : ";
		cin >> this->name;
		cout << " Enter surname      : ";
		cin >> this->surname;
		cout << " Enter course       : ";
		cin >> this->course;
		cout << " Enter mark [0-100] : ";
		cin >> this->mark;
		cout << "\n-----------------------------" << endl;
	};	

	void Show() {
		cout << "\n Name    : " << this->name << endl;
		cout << " Surname : " << this->surname << endl;
		cout << " Course  : " << this->course << endl;
		cout << " Mark    : " << this->mark << endl;
	}	

	string Getname()				{	return this->name;	}
	string Getsuname()				{	return this->surname;	}
	int Getmark()					{ return this->mark; }
	string Getcourse()				{ return this->course; }

	void Set_name(string name)		{	this->name = name;	}
	void Set_suname(string suname)	{	this->surname = suname;	}
	void Set_course(string course)	{	this->course = course;	}
	void Set_mark(int mark)			{	this->mark = mark;	}		

	friend void Write_to_file(vector<Student> group, int size);
	friend void Read_from_file();
	friend ostream &operator<<(ostream &stream, Student obj);
};

ostream &operator<<(ostream &stream, Student obj) {
	stream << obj.name << " | ";
	stream << obj.surname << " | ";
	stream << obj.course << " | ";
	stream << obj.mark << endl;
	return stream;           // Повертає посилання на параметр stream
}

bool sort_by_name(Student &obj, Student &other) {
	return obj.Getname() < other.Getname();
}

bool sort_by_surname(Student &obj, Student &other) {
	return obj.Getsuname() < other.Getsuname();
}

bool sort_by_course(Student &obj, Student &other) {
	return obj.Getcourse() < other.Getcourse();
}

void Write_to_file(vector<Student> group, int size) {

	ofstream writeFile;
	string path = "data.txt";
	writeFile.open(path);

	if (!writeFile.is_open()) {
		cout << "Can't open file" << endl;
	}
	else {
		writeFile << group.size() << endl;
		for (int i = 0; i < group.size(); i++) {
			writeFile << group[i].name << endl;
			writeFile << group[i].surname << endl;
			writeFile << group[i].course << endl;
			writeFile << group[i].mark << endl;
		}
	}
	writeFile.close();
}

void Show(vector<Student> student, int size) {
	for (int i = 0; i < size; i++) {
		cout << student[i];
	}
}

void Read_from_file() {

	int size;		
	vector<Student> MyVector;
	ifstream readFile("data.txt");
	readFile >> size;
	Student *my_srudent = new Student[size];
	while (!readFile.eof()){		
		for (int i = 0; i < size; i++) {
			readFile >> my_srudent[i].name;
			readFile >> my_srudent[i].surname;
			readFile >> my_srudent[i].course;
			readFile >> my_srudent[i].mark;

			MyVector.push_back(my_srudent[i]);
		}		
	}
	readFile.close();
	delete[] my_srudent;
	Show(MyVector, size);	
}

void Sort_by_name(vector<Student> student, int size) {
	sort(student.begin(), student.end(), sort_by_name);
	Show(student, size);	
}

void Sort_by_surname(vector<Student> student, int size) {
	sort(student.begin(), student.end(), sort_by_surname);	
	Show(student, size);
}

void Best_student(vector<Student> student, int size) {
	
	int count_best = 0;
	vector<Student> best_student;

	for (int i = 0; i < size; i++) {
		if (student[i].Getmark() >= 74) {
			count_best++;
			//cout << group[i];
			best_student.push_back(student[i]);
		}		
	}
	Show(best_student, count_best);
}

int main()
{
	int count;	
	vector<Student> group;
	
	cout<< "\n--------------------[   S T U D E T N    ]------------------- " << endl;
	cout << "\n\t>>>> Enter Student count : ";
	cin >> count;
	for (int i = 0; i < count; i++) {
		group.push_back(Student(count));
	}

	cout << "\n-------------------[     ALL STUDENT     ]-------------------" << endl;
	Show(group, count);
	
	cout << "\n-------------------[     SORT BY NAME    ]-------------------" << endl;
	Sort_by_name(group, count);	
	
	cout << "\n-------------------[   SORT BY SURNAME   ]-------------------" << endl;
	Sort_by_surname(group, count); 

	cout << "\n-------------------[     BEST STUDENT    ]-------------------" << endl;	
	Best_student(group, count);
	

	/*vector<Student> course;
	cout << "\n-------------------\n YANG COURSE : \n-------------------" << endl;
	
	partial_sort_copy(group.begin(), group.end(), course.begin(), course.begin(), sort_by_course);
	
	for (int i = 0; i < count; i++) {
		cout << course[i];
	}
	*/
	
	cout << "\n-------------------[    WRITE TO FILE    ]-------------------" << endl;
	Write_to_file(group, count);

	cout << "\n-------------------[    READ FROM FILE   ]-------------------" << endl;
	Read_from_file();

	system("pause");
	return 0;            
}
