#include<iostream>
#include<string>
#include<vector>
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
Описати клас Студент(ім’я, курс, оцінка у 100-бальній системі). 
Перевизначити для класу оператор виводу у потік.
Визначити функцію заповнення вектору(деку) студентів довільними даними
Визначити функцію виводу вмісту вектору(деку).
Впорядкувати вектор(дек) за іменами студентів по зростанню.
Відсортувати вектор(дек) за прізвищами студентів
Знайти кількість студентів, що добре навчаються(бал &gt;=74)
Cкопіювати студентів, що добре навчаються у інший контейнер(вектор, дек чи список)
Встановити у перші три елементи вектору(деку) студентів самих молодших курсів за зростанням(partial_sort_copy).
Зберегти інформацію про студентів у текстовому файлі
Почитати інформацію про студентів з файлу у контейнер
*/

class Student {

	string name;
	string course;
	int mark;

public:

	Student() {};

	void Fill() {
		cout << " Enter name student : ";
		cin >> this->name;
		//getline(cin, name);

	}

};

int main()
{
	vector<Student> group;

	group.push_back(Student());

	


	system("pause");
	return 0;            
}