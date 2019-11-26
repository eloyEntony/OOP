#include "Group.h"
#include"Student.h"
#include<iostream>
using namespace std;


Group::Group()
{
}

Group::Group(int size, string name_group, int course, string specialty)
{
	this->name = name_group;
	this->course = course;
	this->specialty = specialty;

	for (int i = 0; i < size; i++)
	{
		this->man[i].Fill_student();
	}
}

void Group::Show_croup()
{
	cout << " Group: " << this->name << endl;
	cout << " Course: " << this->course << endl;
	cout << " Specialty: " << this->specialty << endl;
	cout << " Size: " << this->size << endl;

	for (int i = 0; i < size; i++)
	{
		this->man[i].Show_student();
	}
}

void Group::Creat_croup(int size, string name_group, int course, string specialty)
{
	 this->name= name_group;
	 this->course = course;
	 this->specialty = specialty;

	for (int i = 0; i < size; i++)
	{
		this->man[i].Fill_student();
	}
}

void Group::Set_size(int size)
{
	this->size = size;
}

void Group::Set_name(string name)
{
	this->name = name;
}


Group::~Group()
{
}
