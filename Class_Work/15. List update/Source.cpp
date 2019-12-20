#include <iostream>
#include<string>

using namespace std;

/*Побудувати клас для роботи з однозв’язним списком. Елемент списку містить наступну інформацію про автобус: 

номер автобуса; 
прізвище та ініціали водія; 
номер маршруту. 
Програма повинна забезпечувати: 
початкове формування двох списків: 
з даними про автобуси, які знаходяться в автопарку; 
з даними про автобуси, які знаходяться на маршрутах. 
При виїзді кождого автобуса з парку вводиться номер автобуса, і програма видаляє дані про цей автобус з списку автобусів, 
які знаходяться в автопарку, та записує ці дані в список автобусів, які знаходяться на маршруті. 
аналогічна операція виконується для списків, якщо якийсь автобус повертається в автопарк; 
по запиту видіються відомості про автобуси, які знаходяться в автопарку або на маршруті. 
*/

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

		Bus(T1 number_bus = T1(), T2 driver = T2(), T3 route_number = T3(), T4 status = T4(), Bus *nextBus = nullptr){			
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

	Bus_station(){
		this->size = 0;
		this->head = nullptr;
	}

	void Push(int number_bus, string driver, int route_number, string status){
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

	

	void Show_bus(){
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
	bool exit = false;
	int choise;
	int transfer;
	int number_bus;
	string driver;
	int route_number;
	string status;

	int bus_in_park;
	int bus_in_route;

	Bus_station<int, string, int, string> list_in_park;	
	Bus_station<int, string, int, string> list_on_routes;	
	 



	while (!exit) {

		cout << " 1. [Add bus to park]" << endl;
		cout << " 2. [Add bus to route]" << endl;
		cout << " 3. [Show bus in park]" << endl;
		cout << " 4. [Show bus on route]" << endl;
		cout << " 5. [Transfer to route]" << endl;
		cout << " 6. [Transfer to park]" << endl;
		cout << " 7. [Show all]" << endl;
		cout << " 0. [Exit]" << endl;

		cout << "\n Enter you choise : ";
		cin >> choise;

		switch (choise)
		{
			

		case 1:
			cout << " How many bus in park : ";
			cin >> bus_in_park;
			cout << endl;
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
				cout << endl;
			}
			system("pause");
			break;

		case 2:
			cout << " How many bus in route : ";
			cin >> bus_in_route;
			cout << endl;
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
				cout << endl;
			}
			system("pause");
			break;

		case 3:
			list_in_park.Show_bus();
			system("pause");
			break;

		case 4:
			list_on_routes.Show_bus();
			system("pause");
			break;

		case 5:
			cout << "\n\n   #######>> BUS IN PARK <<#######" << endl;
			list_in_park.Show_bus();
			cout << "\n\n [] Enter bus to transfer : ";
			cin >> transfer;
			if (transfer > list_in_park.Get_size())
			{
				cout << "\n\n ---------------- No bus ----------------" << endl;
			}
			else 
			{
				list_in_park.Transfer(transfer, list_on_routes);
			}
			system("pause");
			break;

		case 6:
			cout << "\n\n   #######>> BUS IN ROUTE <<#######" << endl;
			list_on_routes.Show_bus();
			cout << "\n\n [] Enter bus to transfer : ";
			cin >> transfer;
			if (transfer > list_on_routes.Get_size())
			{
				cout << "\n\n ---------------- No bus ----------------" << endl;
			}
			else
			{
				list_on_routes.Transfer(transfer, list_in_park);
			}
			system("pause");
			break;

		case 7:
			cout << "\n\n   #######>> BUS IN PARK <<#######" << endl;
			list_in_park.Show_bus();
			cout << "****************************************" << endl;
			cout << "\n\n   #######>> BUS IN ROUTE <<#######" << endl;
			list_on_routes.Show_bus();
			system("pause");
			break;

		case 0:
			exit = true;
			break;

		default:
			break;			
		}
		system("cls");
	}



	system("pause");
	return 0;
}