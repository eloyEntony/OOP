#include<iostream>
#include<string>
using namespace std;

//class Car abstract{
//private:
//	string body;
//	float engine;
//	float wheels;
//	string paint;
//	string salon;
//public:
//
//	Car() {};
//
//	virtual void Set_body() = 0;
//	virtual void Set_engine() = 0;
//	virtual void Set_wheels() = 0;
//	virtual void Set_paint() = 0;
//	virtual void Set_salon() = 0;
//};

class Model_Techology {

	

};

class Auto_Technology abstract{
protected:
	string body;
	float engine;
	float wheels;
	string paint;
	string salon;


	virtual void Build_body() = 0;
	virtual void Install_engine() = 0;
	virtual void Install_wheels() = 0;
	virtual void Paint() = 0;
	virtual void Prepare_salon() = 0;

public:

	void Create_new_auto() {

	}
};

class Mini_auto : protected Auto_Technology {
	void Build_body()override {
		
	};

	void Install_engine()override {
	};

	void Install_wheels() override {
	};

	void Paint()override {
	};

	void Prepare_salon()override {
	};
};

class Sport_auto : protected Auto_Technology {

};

class Cyber_truk : protected Auto_Technology {

};

class Conveyor {
public:
	void Build(Model_Techology model) {



	}

	Conveyor Get_my_car() {
		
	}

};


int main() {

	system("pause");
	return 0;
}