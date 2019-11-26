#pragma once
#include<istream>
#include<string>
#include"Student.h"

using namespace std;

class Group
{
	string name;
	int course = 0;
	string specialty;
	int size = 0;

	Student *man = new Student[size];

public:
	Group();
	Group(int size, string name_group, int course, string specialty);
	void Show_croup();
	void Creat_croup(int size, string name_group, int course, string specialty);
	void Set_size(int size);
	void Set_name(string name);
	~Group();
};

