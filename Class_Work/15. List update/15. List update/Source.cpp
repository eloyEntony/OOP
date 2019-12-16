#include <iostream>
#include<string>

using namespace std;

template<typename T>
class Bus_station
{
	template<typename T>
	class Bus
	{
	public:
		Bus *nextBus;
		int number_bus;
		string driver;
		int route_number;
		int status;

		Bus(Bus *nextBus = nullptr)
		{
			cout << " Enter number bus   : ";
			cin >> this->number_bus;
			cout << " Enter driver       : ";
			cin >> this->driver;
			cout << " Enter route number : ";
			cin >> this->route_number;
			cout << " Enter bus status  (park / route)   : ";
			cin >> this->status;

			this->nextBus = nextBus;
		}

		
	};
	 
	int size=0;
	Bus<T> *head;

public:

	Bus_station()
	{
		this->size = 0;
		this->head = nullptr;
	}

	void Push()
	{
		if (head == nullptr)
		{
			head = new Bus<T>();
		}
		else 
		{
			Bus<T> *current = this->head;
			while (current->nextBus != nullptr)
			{
				current = current->nextBus;
			}
			current->nextBus=new Bus<T>();
		}

		size++;
	}

	int Get_size()
	{
		return this->size;
	}

	

	int operator[](const int index)
	{
		int counter = 0;
		
		if(head) while (this->head != nullptr) {

			cout << "------------------------------------" << endl;
			cout << " Number bus   : " << head->number_bus << endl;
			cout << " Driver       : " << head->driver << endl;
			cout << " Route number : " << head->route_number << endl;
			cout << " Status       : " << head->status << endl;
			cout << "------------------------------------" << endl;
			counter++;


			//http://blog.kislenko.net/show.php?id=1276

			this->head = head->nextBus;
		}

		cout << " Bus in the park : ";
		return counter;
	}
};


int main()
{
	int bus_in_park;

	Bus_station<int> list_in_park;	
	Bus_station<int> list_on_routes;


	cout << " How many bus in park : ";
	cin >> bus_in_park;

	for (int i = 0; i < bus_in_park; i++) 
	{
		list_in_park.Push();
	}
	
	for (int i = 0; i < list_in_park.Get_size(); i++)
	{
		cout << list_in_park[i] << endl;
	}


	system("pause");
	return 0;
}