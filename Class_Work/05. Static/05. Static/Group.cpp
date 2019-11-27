#include"Group.h"
#include"Student.h"
#include<iostream>
using namespace std;


Group::Group(){}

Group::Group(int size, string name_group, int course, string specialty){
	this->name = name_group;
	this->course = course;
	this->specialty = specialty;		
}

void Group::Show_croup(){
	cout << "\n\n ============Group=============" << endl;
	cout << " - Group: " << this->name << endl;
	cout << " - Course: " << this->course << endl;
	cout << " - Specialty: " << this->specialty << endl;
	cout << " - Size: " << this->size << endl;
	cout << " ===========Students===========" << endl;
	
	for (int i = 0; i < size; i++)	{		
		man[i].Show_student();
	}
}

 void Group::Creat_croup(int size, string name_group, int course, string specialty){
	 this->name= name_group;
	 this->course = course;
	 this->specialty = specialty;
			 
	 this->man = new Student[size];	 
	for (int i = 0; i < size; i++)	{	
		man[i].Fill_student();
	}
}

void Group::Set_size(int size){
	this->size = size;
}

void Group::ReCourse(Group & group, int course){
	group.course = course;
}

void Group::ReSpecialty(Group & group, string specialty){
	 group.specialty = specialty;
}

void Group::Rename(Group &group, string name){
	group.name = name;
}

void Group::Change_student(int id, string name, string surname){
	for (int i = 0; i < this->size; i++){
		if (i == id){
			man[i].Set_name(name);
			man[i].Set_surname(surname);
		}
	}	
}

Group::~Group(){
	man = nullptr;
	delete[] man;
}
