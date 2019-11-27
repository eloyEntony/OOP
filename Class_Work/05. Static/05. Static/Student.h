#pragma once
#include<iostream>
#include<string>
using namespace std;

class Student
{
	string name;
	string surname;
	int studentID = 0;
	static int counter;

public:
	Student();
	//Student(string name, string surname);
	void Fill_student();	
	
	void Set_name(string name);
	void Set_surname(string surname);

	void Show_student();
	~Student();
};

