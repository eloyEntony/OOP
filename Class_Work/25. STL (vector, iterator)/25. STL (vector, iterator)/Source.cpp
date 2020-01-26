#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<conio.h>
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
Зберегти інформацію про студентів у текстовому файлі
Почитати інформацію про студентів з файлу у контейнер
*/

class Student {

	string name;
	string surname;
	string course;
	int mark;	

public:

	Student() {
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

	friend ostream &operator<<(ostream &stream, Student obj);	
	
	string Getname() {	return this->name;	}
	string Getsuname(){	return this->surname;	}
	int Getmark() { return this->mark; }
	string Getcourse() { return this->course; }
	//bool rh(const Student &rhs) const { return name < rhs.name; }
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


int main()
{
	int count_best=0;
	int count;
	vector<Student> group;
	vector<Student> best_student;
	
	
	cout << " Enter Student count : ";
	cin >> count;

	for (int i = 0; i < count; i++) {
		group.push_back(Student());
	}
	for (int i = 0; i < count; i++) {
		cout << group[i];
	}

	
	cout << "\n-------------------\n Sort by name : \n-------------------" << endl;
	sort(group.begin(), group.end(), sort_by_name);
	for (int i = 0; i < count; i++) {
		cout << group[i].Getname() << endl;
	}

	cout << "\n-------------------\n Sort by surname : \n-------------------" << endl;
	sort(group.begin(), group.end(), sort_by_surname);
	for (int i = 0; i < count; i++) {
		cout << group[i].Getsuname() << endl;
	}


	cout << "\n-------------------\n BEST STUDENT : \n-------------------" << endl;
	for (int i = 0; i < count; i++) {
		if (group[i].Getmark() >= 74){
			count_best++;
			//cout << group[i];
			best_student.push_back(group[i]);
		}
		else cout << " No" << endl;
	}
	for (int i = 0; i < count_best; i++) {
		cout << best_student[i];
	}
	

	vector<Student> course;
	cout << "\n-------------------\n YANG COURSE : \n-------------------" << endl;
	
	partial_sort_copy(group.begin(), group.end(), course.begin(), course.begin(), sort_by_course);
	
	for (int i = 0; i < count; i++) {
		cout << course[i];
	}
	
	
	
	

	system("pause");
	return 0;            
}
