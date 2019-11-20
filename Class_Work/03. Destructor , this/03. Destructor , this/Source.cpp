#include<iostream>
#include<string>
#include"Student.h"

using namespace std;


int main()
{
	string name;
	string surname;
	string group;
	const int size = 5;
	int mark[size];	

	Student student[size];		

	for (int i = 0; i < size; i++) {

		cout << "\n\n Name: ";
		cin >> name;
		cout << " Surname: ";
		cin >> surname;
		cout << " Group: ";
		cin >> group;
		
		for (int j = 0; j < size; j++) {

			cout << " [ " << j+1 << " ] Mark: ";
			cin >> mark[j];

		}
		student[i] = Student(name, surname, group, mark);
		
		student[i].Show_info();
		student[i].Average_mark();
	}

	student->Sort(student, size);
	
	student->~Student;

	system("pause");
	return 0;
}