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

	for (int i = 0; i < size; i++){
		this->mark[i] = mark[i];
	}
}

void Student::Show_info() {

	cout << "===============================================================" << endl;
	cout << "\n Name : " << this ->name<<endl;
	cout << " Surname: " << this->surname << endl;
	cout << " Group: " << this-> group << endl;
	cout << " Rating: ";

	for (int i = 0; i < size; i++){
		cout << this->mark[i] << " ";
	}
	cout << endl;
	
}

void Student::Average_mark() {

	double suma = 0;

	for (int i = 0; i < size; i++){
		suma += mark[i];
		this->average_mark = suma/size;
	}

	cout << " Average mark student ===> " << average_mark << endl;
}


void Student::Sort(Student student[], int size) 
{
	Student tmp;

	for (int j = 0; j < size - 1; j++) {
		for (int i = 0; i < size - 1; i++)
		{
			if (student[i].average_mark > student[i + 1].average_mark)
			{ 
				tmp = student[i];
				student[i] = student[i + 1];
				student[i + 1] = tmp;
			}
		}
	}
	cout << "\n\n\n ------------------------Sort metod--------------------------------" << endl;

	for (int i = 0; i < size; i++){		
		student[i].Show_info();
		cout << " AVERAGE MARK ------------>>> " << student[i].average_mark <<"\n"<< endl;
		cout << "--------------------------------------------------------" << endl;
	}

}