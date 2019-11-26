#pragma once
#include<iostream>
#include<string>
using namespace std;

class Student
{
	string name;
	string surname;

public:
	Student();
	Student(string name, string surname);
	void Fill_student();
	
	void Show_student();
	~Student();
};

