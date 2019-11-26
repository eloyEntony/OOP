#include<iostream>
#include<string>

#include"Group.h"
#include"Student.h"

using namespace std;

int main()
{
	string name_group;
	int course;
	string specialty;
	int size = 0;
	Group mygroup;

	cout << "\n Enter name group: ";
	cin >> name_group;
	cout << " Enter course: ";
	cin >> course;
	cout << " Enter specialty: ";
	cin >> specialty;

	cout << " Enter group size: ";
	cin >> size;

	mygroup.Group(size, name_group, course, specialty);

	
	

	mygroup.Show_croup();

	system("pause");
	return 0;
}