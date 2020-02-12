#include<iostream>
#include<string>
#include<vector>
using namespace std;

/* Кавамашина. Маню: Американо Американо з молоком Еспрессо Еспрессо з молоком Лате Мокачіно.*/



class Drink abstract {

public: 
	virtual void Make_coffee() = 0;
	virtual ~Drink() {};
};

class Americano : public Drink {
	void Make_coffee() override {
		cout<< "Make AMERICANO"<<endl;
	}
};

class Americano_milk : public Drink {
	void Make_coffee() override {
		cout << "Make AMERICANO with MILK" << endl;
	}
};

class Ecspresso : public Drink {
	void Make_coffee() override {
		cout << "Make ECSPRESSO" << endl;
	}
};

class Ecspresso_milk : public Drink {
	void Make_coffee() override {
		cout << "Make ECSPRESSO with MILK" << endl;
	}
};

class Latte : public Drink {
	void Make_coffee() override {
		cout << "Make LATTE" << endl;
	}
};

class Mokachino : public Drink {
	void Make_coffee() override {
		cout << "Make MOKACHINO" << endl;
	}
};

enum Coffee {
	americano = 1, americano_milk, ecspresso, ecspresso_milk, latte, mokachino
};

class Fabric_metod {
public:
	static Drink* createDrink(Coffee type) {

		switch (type)
		{
		case americano:
			return new Americano;
			break;

		case americano_milk:
			return new Americano_milk;
			break;
		default:
			break;
		}
	};
};

int main() {		
	int choise;
	vector <Drink*> c;
	while (true) {

		cout << " [1] Americano \n [2] Americano_milk\n [3] Ecspresso\n [4] Ecspresso_milk\n [5] Latte \n [6] Mokachino\n [0] Exit \n";
		cin >> choise;
		if (choise == 0)
			break;

		else {
			c.push_back(Fabric_metod::createDrink((Coffee)choise));
			
		}
			

		cout << "\n---------------------------------" << endl;
	}


	system("pause");
	return 0;
}