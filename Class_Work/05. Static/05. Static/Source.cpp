#include<iostream>
#include<string>
#include"Group.h"
#include"Student.h"

using namespace std;

string Group::name;
int Group::course = 0;
string Group::specialty;
int Student::counter = 0;

int main()
{
	string name_student;
	string surname_student;
	int id = 0;
	string name_group;
	int course;
	string specialty;
	int size = 0;
	int choise = 0;
	bool exit = false;
	Group mygroup;



	while (!exit)
	{
		cout << "\n==================== Group =======================" << endl;
		cout << " 1. Create group\n 2. Change student\n 3. Rename group\n 4. Change course\n 5. Change specialty\n 6. Show group \n 0. Exit" << endl;
		cout << " Enter your choise: ";
		cin >> choise;

		switch (choise)	{
		case 1:
			cout << "\n Enter name group: ";
			cin >> name_group;
			cout << " Enter course: ";
			cin >> course;
			cout << " Enter specialty: ";
			cin >> specialty;
			cout << " Enter group size: ";
			cin >> size;
			mygroup.Set_size(size);
			mygroup.Creat_croup(size, name_group, course, specialty);
			cout << "\n\n\t GROUP CREATED!!!" << endl;
			break;
		case 2:
			cout << " Enter ID student to change: ";
			cin >> id;
			if (id > size)	{
				cout << " Error... No student to " << id << " ID" << endl;
			}
			else{
				cout << " Enter new student name: ";
				cin >> name_student;
				cout << " Enter new student surname: ";
				cin >> surname_student;
				mygroup.Change_student(id, name_student, surname_student);
			}
			break;
		case 3:
			cout << " Enter new group name: ";
			cin >> name_group;
			Group::Rename(mygroup, name_group);
			break;
		case 4:
			cout << " Enter new course: ";
			cin >> course;
			Group::ReCourse(mygroup, course);
			break;
		case 5:
			cout << " Enter new specialty: ";
			cin >> specialty;
			Group::ReSpecialty(mygroup, specialty);
			break;
		case 6: 
			mygroup.Show_croup();
			break;
		case 0:
			exit = true;
			break;
		default:
			break;
		}
	}

	

	/*cout << "\n Enter name group: ";
	cin >> name_group;
	cout << " Enter course: ";
	cin >> course;
	cout << " Enter specialty: ";
	cin >> specialty;
	cout << " Enter group size: ";
	cin >> size;
	mygroup.Set_size(size);
	mygroup.Creat_croup(size, name_group, course, specialty);
	mygroup.Show_croup();

	Group::Rename(mygroup, "34C9-1PR");
	mygroup.Show_croup();*/

	


	system("pause");
	return 0;
}