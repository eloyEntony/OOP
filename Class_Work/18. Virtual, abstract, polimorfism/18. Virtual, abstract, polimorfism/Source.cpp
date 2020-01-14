#include<iostream>
#include<string>

using namespace std;

//class Shooter {
//public:
//	string ammunition;
//	int count_ammunition;
//
//	Shooter(string ammunition = "bomba", int count = 0)
//	{
//		this->ammunition = ammunition;
//		this->count_ammunition = count;
//	}
//	void Shot() 
//	{
//		if (this->count_ammunition > 0) {
//			this->count_ammunition--;
//			cout << "\t\t Shot " << this->ammunition << " Left : " << this->count_ammunition << endl;
//		}
//		else
//			cout << " NOOO" << endl;
//	}
//
//	void Give_ammunition(string ammun, int count_ammun) {
//		this->ammunition = ammun;
//		this->count_ammunition = count_ammun;
//		cout << "------------------------------" << endl;
//		cout << " Ammunition : " << this->ammunition << endl;
//		cout << " Count ammunition : " << this->count_ammunition << endl;
//		cout << "------------------------------" << endl;
//	}
//
//	~Shooter() {};
//
//};

class Fortress {
public:

	string ammunition;
	int count_ammunition;
	
	Fortress(string ammo = "bomba", int count = 0) {
		this->ammunition = ammo;
		this->count_ammunition = count;
		cout << "Fortess constructor" << endl;
	};

	virtual void Shot()
	{
		cout << "boom!" << endl;
	}
};

class ArcherTower : virtual public Fortress {
public:
	ArcherTower(string ammu = "bomba", int count = 0)
	{
		ArcherTower::ammunition = ammu;
		ArcherTower::count_ammunition = count;
		cout << "ArcherTower constructor" << endl;
	}
	
	void Shot() override
	{
		cout << " count : " << --ArcherTower::count_ammunition << endl;
	}
};

class Archer :virtual public ArcherTower {
public:
	Archer() {	}
	
	void Shot(){
		cout << " Shot  --> Archer" << endl;
		cout << " Ammo : " << ArcherTower::ammunition << endl;
		cout << " Count : " << --ArcherTower::count_ammunition << endl;
	}
};

class Ranger : virtual public Fortress {
public:
	Ranger() {}

	void Shot()override {
		cout << " Shot --> Ranger" << endl;
		
	}
};

class Catapult :virtual public Fortress {
public:
	Catapult() {}

	void Shot()override {
		cout << " Shot --> Catapult" << endl;
		
	}
};



class Shooter {
public:
	void Shot(Fortress *fortess) {
		fortess->Shot();
	}
};

int main() {
		
	Fortress fort("arrow", 4);	
	//fort.Shot();	
	ArcherTower tower("arrow", 4);
	Archer arc;
	
	//Shooter bob;

	//bob.Shot(&tower);

	//arc.tower::Shot();

	system("pause");
	return 0;
}