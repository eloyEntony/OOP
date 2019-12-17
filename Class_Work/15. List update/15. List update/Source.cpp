#include <iostream>
#include<string>

using namespace std;

template<typename T1, typename T2, typename T3, typename T4>
class Bus_station
{
	template<typename T1, typename T2, typename T3, typename T4>
	class Bus
	{
	public:
		Bus *nextBus;
		T1 number_bus;
		T2 driver;
		T3 route_number;
		T4 status;

		Bus(T1 number_bus = T1(), T2 driver = T2(), T3 route_number = T3(), T4 status = T4(), Bus *nextBus = nullptr)		{			
			this->number_bus= number_bus;			
			this->driver= driver;			
			this->route_number= route_number;
			this->status = status;
			this->nextBus = nextBus;
		}		
	};
	 
	int size=0;
	Bus<T1, T2, T3, T4> *head;

public:

	Bus_station()	{
		this->size = 0;
		this->head = nullptr;
	}

	void Push(int number_bus, string driver, int route_number, string status)	{
		if (head == nullptr){
			head = new Bus<T1, T2, T3, T4>(number_bus,  driver,  route_number, status);
		}
		else{
			Bus<T1, T2, T3, T4> *current = this->head;
			while (current->nextBus != nullptr)
			{
				current = current->nextBus;
			}
			current->nextBus=new Bus<T1, T2, T3, T4>(number_bus, driver, route_number, status);
		}
		size++;
	}

	int Get_size(){
		return this->size;
	}

	

	void Show_bus()	{
		Bus <T1, T2, T3, T4> *current = head;

		int counter = 0;

		while (current != nullptr) {

			cout << "------------------------------------" << endl;
			cout << " Number bus   : " << current->number_bus << endl;
			cout << " Driver       : " << current->driver << endl;
			cout << " Route number : " << current->route_number << endl;
			cout << " Status       : " << current->status << endl;
			cout << "------------------------------------" << endl;

			current = current->nextBus;
			counter++;			
		}

		cout << "Counter bus : " << counter << endl;
	}

	void DeleteFirst() {
		Bus<T1, T2, T3, T4> *temp = this->head;
		this->head = this->head->nextBus;
		delete temp;
		size--;
	}

	void RemoveByIndex(const int index) {
		if (index == 0) {
			DeleteFirst();
		}
		else {
			Bus<T1, T2, T3, T4> *prev = this->head;
			for (int i = 0; i < index - 1; i++) {
				prev = prev->nextBus;
			}

			Bus<T1, T2, T3, T4> *toDel = prev->nextBus;
			prev->nextBus = toDel->nextBus;
			delete toDel;
			size--;
		}
	}


	void Transfer(const int index, Bus_station &other)	{
		if ((index - 1) == 0)
		{
			other.Add(this->head->number_bus, this->head->driver, this->head->route_number, this->head->status);
			DeleteFirst();
		}

		else {
			Bus <T1, T2, T3, T4> *prev = this->head;
			for (int i = 0; i < index - 1; i++) {
				prev = prev->nextBus;
			}

			Bus <T1, T2, T3, T4> *toDel = prev->nextBus;
			other.Add(toDel->number_bus, toDel->driver, toDel->route_number, toDel->status);
			prev->nextBus = toDel->nextBus;
			other.size++;
			delete toDel;
			this->size--;
		}
	}


	void Add(T1 number_bus, T2 driver, T3 route_number, T4 status)	{
		this->head = new Bus<T1, T2, T3, T4>(number_bus, driver, route_number, status, this->head);
		this->size++;
	}


};


int main()
{

	int number_bus;
	string driver;
	int route_number;
	string status;

	int bus_in_park;
	int bus_in_route;

	Bus_station<int, string, int, string> list_in_park;	
	Bus_station<int, string, int, string> list_on_routes;	



	cout << " How many bus in park : ";
	cin >> bus_in_park;

	for (int i = 0; i < bus_in_park; i++){

		cout << " Enter number bus   : ";
		cin >> number_bus;
		cout << " Enter driver       : ";
		cin >> driver;
		cout << " Enter route number : ";
		cin >> route_number;
		cout << " Enter status       : ";
		cin >> status;
		cout << endl;

		list_in_park.Push(number_bus, driver, route_number, status);
	}
	
	cout << " How many bus in route : ";
	cin >> bus_in_route;

	for (int i = 0; i < bus_in_route; i++){
		cout << " Enter number bus   : ";
		cin >> number_bus;
		cout << " Enter driver       : ";
		cin >> driver;
		cout << " Enter route number : ";
		cin >> route_number;
		cout << " Enter status       : ";
		cin >> status;

		cout << endl;
		
		list_on_routes.Push(number_bus, driver, route_number, status);
	}


	list_in_park.Show_bus();
	list_on_routes.Show_bus();

	list_in_park.Transfer(1, list_on_routes);
	cout << "======================================" << endl;
	list_in_park.Show_bus();

	cout << "======================================\n\n" << endl;
	list_on_routes.Show_bus();
	//list_in_park.DeleteFirst();
	//list_in_park.Show_bus();


	system("pause");
	return 0;
}