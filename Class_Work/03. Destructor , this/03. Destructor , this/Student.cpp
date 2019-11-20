#include "Student.h"
using namespace std;


Student::Student()
{

}


Student::~Student()
{
}

Student::Student(string name, string surname, string group, int mark[]) {
	this->name = name;
	this->surname = surname;
	this->group = group;

	for (int i = 0; i < 5; i++) {

		this->mark[i] = mark[i];
	}
}

void Student::Show_info() {

	cout << "===============================================================" << endl;
	cout << " Name : " << this ->name<<endl;
	cout << " Surname: " << this->surname << endl;
	cout << " Group: " << this-> group << endl;
	cout << " Rating: ";

	for (int i = 0; i < 5; i++)
	{
		cout << this->mark[i] << " ";
	}
	cout << endl;
}

void Student::Average_mark() {

	double suma = 0;

	for (int i = 0; i < size; i++)
	{
		suma += mark[i];
		average_mark = suma/size;
	}

	cout << " Average mark student ===> " << average_mark << endl;
}

void Student::Sort() 
{
	


}