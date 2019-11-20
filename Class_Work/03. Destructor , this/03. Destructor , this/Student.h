#pragma once
#include<iostream>
#include<string>


using namespace std;

class Student
{
	string name;
	string surname;
	string group;	
	int mark[5];
	double average_mark=0;
	int size = 5;


public:
	Student();

	Student(string name, string surname, string group, int mark[]);

	void Show_info();

	void Average_mark();	

	void Sort(Student  student[], int size);

	~Student();
};

