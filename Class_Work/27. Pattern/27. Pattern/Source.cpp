#include<iostream>
#include<string>

using namespace std;

class Presedent {

private:

	string name;
	static Presedent *obj;
	Presedent(string name) : name(name) {}

public:

	static Presedent* getObj(string name = "user");

	void Show_info() {

		cout << " Name    : " << this->name << endl;

	}

	string getName() const
	{
		return this->name;
	}

	void setObj(string name)
	{
		this->name = name;
	}

	~Presedent() {};

};


int main() {

	

	Presedent Bob;

	Bob.Show_info();
		
		

	


	system("pause");
	return 0;
}