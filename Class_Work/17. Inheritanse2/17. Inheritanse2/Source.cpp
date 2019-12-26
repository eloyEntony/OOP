#include<iostream>
#include<string>
using namespace std;

class Human{
protected:
	int age;
	string name;
public:
	string GetName()			{	return this->name;	}
	int Get_age()				{	return this->age;	}
	void Set_name(string name)	{	this->name = name;	}
	void Set_age(int age)		{	this->age = age;	}
};

class Junior :public Human {
public:
	string position;
	void Write_code(){	cout << " " << this->GetName() << " writing code using StackOverflow..." << endl;	}
};

class Middle :public Junior{
public:
	bool customers;
	void Write_code(){	cout <<" "<< this->GetName() << " writing code without StackOverflow..." << endl;	}
};

class Sinior :public Middle {
public:
	void CreateDB()	 {	cout << " Create DB" << endl;	}
	void Write_code(){  cout <<" "<< this->GetName() << " writing code well..." << endl;	}
};

int main()
{
	Junior human;
	cout << "\n\n";
	human.Set_name("Bill");
	//cout << human.GetName() << endl;
	human.position = " junior Software developer";
	cout <<" "<< human.GetName() << human.position << endl;
	human.Write_code();
	human.Set_age(20);
	cout << " Age : " << human.Get_age() << endl;


	Middle middle;
	cout << "\n\n";
	middle.customers = true;
	middle.Set_name("Max");
	//cout << middle.GetName() << middle.position << endl;
	middle.Write_code();
	cout << " Communicate with customer : " << middle.customers << endl;
	middle.Set_age(25);
	cout << " Age : " << middle.Get_age() << endl;


	Sinior sinior;
	cout << "\n\n";
	sinior.customers = true;
	sinior.Set_name("Bob");
	sinior.Write_code();
	sinior.CreateDB();
	cout << " Communicate with customer : " << sinior.customers << endl;
	sinior.Set_age(30);
	cout << " Age : " << sinior.Get_age() << endl;

	system("pause");
	return 0;
}