#pragma once
#include<istream>
#include<string>
#include"Student.h"

using namespace std;

class Group
{
	static string name;
	int course;
	string specialty;
	int size = 0;

	Student *man;

public:
	Group();
	Group(int size, string name_group, int course, string specialty);
	void Show_croup();
	void Creat_croup(int size, string name_group, int course, string specialty);
	void Set_size(int size);
	void Set_name(string name);

	static void Rename(Group &group, string name);
	~Group();
};

