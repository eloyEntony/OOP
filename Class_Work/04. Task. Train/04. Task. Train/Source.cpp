#include<iostream>
#include<string>
#include<ctime>
#include"Train.h"
#include"TrainCar.h"

using namespace std;

/*Написати програму роботи з поїздами, на основі класів Car(Вагон) та Train(Поїзд).Програма пропонує ввести з клавіатури :
Кількість поїздів;
Кількість вагонів для кожного поїзда.

На основі уведених даних створюються поїзди, виводиться загальна інформація про них та набір наступних звітів :
Поїзд в якому їхала найбільша кількість пасажирів.
Поїзд в якому їхала найменша кількість пасажирів.

Клас Car повинен містити :

поля:
тип  вагона(купе, плацкарт, спальний);
кількість пасажирів у вагоні
													методи :
													конструктори
													методи доступу до полів
													виводу інформації про вагон

Клас Train повинен містити :

поля:
	номер поїзда;
	назва поїзда(сполучення, наприклад "Львів - Київ");
	поле "вагони" - вказівник на тип Car, якому буде 
	виділятися динамічна пам'ять розміром в кількість вагонів,
	де індекс даного масиву вказує на номер вагону;
	кількість вагонів(може бути полем - константою).

													методи:
														Конструктори: по замовчуванню, з параметрами та копіювання;
														Стандартні методи доступу до полів класу;
														Метод для знаходження вагона з максимальною кількість пасажирів;
														Метод для знаходження вагона з мінімальною кількість пасажирів;
														Метод для знаходження загальної кількості пасажирів в поїзді;
														Метод для виведення інформації про поїзд :
															загальна кількість пасажирів.
															загальна кількість вагонів.
															номер вагону в якому їхала найменша кількість пасажирів
															номер вагону в якому їхала найбільша кількість пасажирів.*/

int main() {

	srand(unsigned(time(NULL)));

	int number_train=0;
	string name_train;
	int train_size;

	bool exit = false;
	int choise = 0;
	Train mytrain;

	while (!exit) {
		cout << "\n\n==========================Train Station========================== " << endl;
		cout << " [1] Creator train\n [2] Info by train and train-car\n [3] Max train-car\n [4] Min train-car\n [5] All passenger\n [6] All info by train\n [0] Exit\n" << endl;
		cout << " Enter your choise: ";
		cin >> choise;

		switch (choise)
		{
		case 1:
			cout << "\n\n Enter train name : ";
			cin >> name_train;
			mytrain.Set_name(name_train);

			cout << "\n\n ==== Train size ====" << endl;
			cout << " Enter size: ";
			cin >> train_size;
			mytrain.SetSize(train_size);
			break;
		case 2:
			mytrain.Show_info();
			break;
		case 3:
			mytrain.Max_car();
			break;
		case 4:
			mytrain.Min_car();
			break;
		case 5:
			mytrain.All_passenger();
			break;
		case 6:
			mytrain.Show_all_info();
			break;
		case 0:
			exit = true;
			break;
		default:
			break;
		}

	}



	//system ("pause");
	return 0;
}