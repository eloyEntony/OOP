#include <iostream>
#include <string>

using namespace std;

class Train {
public:
	Train() {
		//cout << "Default train constructor." << endl;
	}
	Train(string route, int distance, int size) {
		this->route = route;
		this->distance = distance;
		this->size = size;
		this->counter++;
		this->trainID = this->counter;
		this->car = new Car[size];

		for (int i = 0; i < size; i++)		{
			cout << "\n [ " << i+1 << " ]" << endl;
			this->car[i].FillCar();
		}
		//cout << "Overload train constructor." << endl;
	}
	void ShowTrain() {
		cout ;
		cout << "\n--------------"<< "[" << this->trainID << "]"<<"---------------------\n Route: " << this->route << "\n Distance: " << this->distance << endl;
		cout << "\n =====Car=====" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << "\t[" << i + 1 << "] ";
			car[i].ShowCar();
		}
	}
	~Train() {
		car = nullptr;
		delete[] car;
	}
	
private:

	class Car {
	private:
		string type;
		int passengers;
	public:
		Car(){
		// cout << "Default car constructor. " << endl;
		}
		Car(string type, int passengers){
			this->type = type;
			this->passengers = passengers;
			//cout << "Overload car constructor. " << endl;
		}
		void ShowCar(){
			cout <<  "   Type: " << this->type << "\t Passengers: " << this->passengers << endl;
		}
		void FillCar(){
			cout << " Enter type: ";
			cin >> this->type;
			cout << " Enter passenger: ";
			cin >> this->passengers;			
		}
	};


	string route;
	int distance;
	int size;
	unsigned int trainID;
	static int counter;
	Car *car;
};

int Train::counter = 0;

int main() {

	/*Train polissya("Rivne - Lviv", 210, "Lux", 200);
	polissya.ShowTrain();*/

	/*const int SIZE = 3;


	Train trains[SIZE]{
		Train("Rivne - Lviv", 210, "Lux", 200),
		Train("Charkiv - Uzgorod", 1110, "Lux", 210),
		Train("Kyiv - Odessa ", 610, "DeLux", 400)
	};

	for (int i = 0; i < SIZE; i++) {
		trains[i].ShowTrain();
	}*/

	string route;
	int size;
	int distance;
	string type_car;
	int train_count;



	cout << "\n Enter train count: ";
	cin >> train_count;
	Train *train = new Train[train_count];

	for (int i = 0; i < train_count; i++){
		cout << "\n =========== Train =============" << endl;
		cout << " Route : ";
		cin >> route;
		cout << " Distanse : ";
		cin >> distance;
		cout << " Size : ";
		cin >> size;

		train[i] = Train(route, distance, size);
	}


	for (int i = 0; i < train_count; i++){
		train[i].ShowTrain();
	}
	
	
	

	/*Train mytrain(route, distanse, size);
	   
	mytrain.ShowTrain();*/


	train = nullptr;
	delete[] train;
	
	
	system("pause");
	return 0;
}


