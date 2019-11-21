#include<iostream>
#include<string>
#include<ctime>
#include"Train.h"
#include"TrainCar.h"

using namespace std;

int main() {

	srand(unsigned(time(NULL)));

	int number_train=0;
	string name_train;
	int train_size;
	int type;
	
	

	Train mytrain;

	cout << "\n\n==========================Train Station========================== " << endl;

	cout << "\n\n Enter train name [Kyev-Lviv] : ";
	getline(cin, name_train);
	mytrain.Set_name(name_train);

	cout << "\n===== Train-car type====\n [1] Sompartmen\n [2] Seat \n [3] Sleeping\n" << endl;
	cout << " Enter type train-car: ";
	cin >> type;

	

	cout << "\n ==== Train size ====" << endl;
	cout << " Enter size: ";
	cin >> train_size;
	mytrain.SetSize(train_size);
	//mytrain.Add_train_car(train_size, type);



	mytrain.Show_info(train_size);

	


	system("pause");
	return 0;
}