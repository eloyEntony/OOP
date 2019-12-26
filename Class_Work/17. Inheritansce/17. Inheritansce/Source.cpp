#include<iostream>
#include<string>
using namespace std;

class Fuel {
	string fuel = "disel";
public:
	string GetFuel() {
		return this->fuel;
	}
};

class Car {
	class Engine {
	public:
		void Drive()
		{
			cout << "Driving..." << endl;
		}
	};
	Engine TDI;
	Fuel disel;

public:
	void Drive()
	{
		TDI.Drive();
	}
	void GASstation()
	{
		cout << "Fuel = " << disel.GetFuel() << endl;
	}
};

int main() {

	Car car;

	car.Drive();
	car.GASstation();

	system("pause");
	return 0;
}