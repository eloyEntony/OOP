#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

class Auto_Technology{
	string name;
	map<string, string> parts;	

public:
	Auto_Technology(string name = "car") : name(name) {}

	void Show_car()const {
		cout << "\n-----------------------------------\n Name:\t\t" << name << endl;
		for (auto el : parts){
			cout << el.first << "\t" << el.second << endl;
		}
		cout << "-----------------------------------\n " << endl;
	}

	string GetParts(const string & key) const {
		return parts.at(key);
	}
	void setPart(const string & key, const string & value) {
		parts[key] = value;
	}
};

class Conveyor abstract {
protected:
	Auto_Technology *car;
public:
	Conveyor()						 {		this->car = new Auto_Technology();	}
	Auto_Technology *Get_car() const {		return this->car;	}

	virtual void Build_body() = 0;
	virtual void Install_engine() = 0;
	virtual void Install_wheels() = 0;
	virtual void Paint() = 0;
	virtual void Prepare_salon() = 0;
	virtual ~Conveyor() { delete this->car; }
};

class Mini_auto : public Conveyor {
public:
	Mini_auto()						{		this->car = new Auto_Technology("MINI-CAR");	}
	void Build_body()override       {		this->car->setPart(" Lenght ", "2.2 m");		};
	void Install_engine()override   {		this->car->setPart(" Engine ", "1.5");		};
	void Install_wheels() override  {		this->car->setPart(" Wheels ", "30s m");		};	
	void Paint()override			{		this->car->setPart(" Color  ", "White");		};
	void Prepare_salon()override	{		this->car->setPart(" Salon  ", "Leather interior");	};
};

class Sport_auto : public Conveyor {
public:
	Sport_auto()					 {		this->car = new Auto_Technology("SPORT-CAR");	}
	void Build_body()override		 {		this->car->setPart(" Lenght ", "1.9 m");		};
	void Install_engine()override	 {		this->car->setPart(" Engine ", "3.0");		};
	void Install_wheels() override	 {		this->car->setPart(" Wheels ", "50s m");		};
	void Paint()override			 {		this->car->setPart(" Color  ", "Red");			};
	void Prepare_salon()override	 {		this->car->setPart(" Salon  ", "Leather interior");	};
};

class Cyber_truk : public Conveyor {
public:
	Cyber_truk()					{		this->car = new Auto_Technology("CUBER-TRUCK");	}
	void Build_body()override		{		this->car->setPart(" Lenght ", "2.0m");		};
	void Install_engine()override	{		this->car->setPart(" Engine ", "3.0");		};
	void Install_wheels() override	{		this->car->setPart(" Wheels ", "100sm");		};
	void Paint()override			{		this->car->setPart(" Color  ", "Black");			};
	void Prepare_salon()override	{		this->car->setPart(" Salon  ", "Leather interior");	};
};

class Director {
public:
	void Create_car(Conveyor* build) {
		build->Build_body();
		build->Install_engine();
		build->Install_wheels();
		build->Paint();
		build->Prepare_salon();
	}
};

enum {	Mini=1, Spotr, Cyber };

void Menu() {

	vector<Director> Zavod;

	Director *shop = new Director();
	Conveyor *builder;

	bool exit = false;
	int choise;

	while (!exit) {

		cout << "\n\t[ CAR BUILDER ]\n [1] MINI\n [2] SPORT\n [3] CYBER\n [0] EXIT\n\n Enter : ";
		cin >> choise;

		switch (choise)
		{
			case Mini: {
				builder = new Mini_auto();
				shop->Create_car(builder);
				builder->Get_car()->Show_car();

				//Zavod.push_back(builder);


				delete builder;
				break;
			}
			case Spotr: {
				builder = new Sport_auto();
				shop->Create_car(builder);
				builder->Get_car()->Show_car();
				delete builder;
				break;
			}
			case Cyber:	{
				builder = new Cyber_truk();
				shop->Create_car(builder);
				builder->Get_car()->Show_car();
				delete builder;
				break;
			}
			case 0:
				exit = true;
			default:
				break;
		}
	}

}


int main() {

	Menu();

	/*Director *shop = new Director();
	Conveyor *builder = new Mini_auto();
	shop->Create_car(builder);
	builder->Get_car()->Show_car();


	delete builder;
	builder = new Sport_auto();
	shop->Create_car(builder);
	builder->Get_car()->Show_car();


	delete builder;
	builder = new Cyber_truk();
	shop->Create_car(builder);
	builder->Get_car()->Show_car();

	delete builder;
	delete shop;*/
	//system("pause");
	return 0;
}