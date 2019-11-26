#include "Student.h"
#include<iostream>
using namespace std;


Student::Student()
{
	
}

Student::Student(string name, string surname)
{
	this->name = name;
	this->surname = surname;
	
}

void Student::Fill_student()
{
	cout << "\n----------------------------------------" << endl;
	cout << " Enter name: ";
	cin >> this->name;
	cout << " Enter surname: ";
	cin >> this->surname;

	
}

void Student::Show_student()
{
	cout << "-----------------------------------" << endl;
	cout << " Name : " << this->name << " \n Surname: " << this->surname << endl;
}


Student::~Student()
{
}
