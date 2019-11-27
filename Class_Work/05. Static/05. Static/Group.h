#pragma once
#include<istream>
#include<string>
#include"Student.h"

using namespace std;

class Group
{
	static string name;
	static int course;
	static string specialty;
	int size = 0;
	
	Student *man;

public:
	Group();
	Group(int size, string name_group, int course, string specialty);
	void Show_croup();
	void Creat_croup(int size, string name_group, int course, string specialty);
	void Set_size(int size);	
	static void ReCourse(Group &group, int course);
	static void ReSpecialty(Group &group, string specialty);
	static void Rename(Group &group, string name);
	void Change_student(int id, string name, string surname);
	~Group();
};

