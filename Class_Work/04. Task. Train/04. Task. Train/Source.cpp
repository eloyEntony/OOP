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


	int train_count = 0;

	cout << "Enter trains count: ";
	cin >> train_count;

	Train *train = new Train[train_count];

	for (int i = 0; i < train_count; i++)
	{
		cout << "\n\n Enter train name : ";
		cin >> name_train;
		train[i].Set_name(name_train);

		cout << "\n ==== Train size ====" << endl;
		cout << " Enter size: ";
		cin >> train_size;
		train[i].SetSize(train_size);

		train[i].Show_info();
		cout << "-------------------------" << endl;

	}



	/*Train mytrain;
	
			cout << "\n\n Enter train name : ";
			cin >> name_train;
			mytrain.Set_name(name_train);

			cout << "\n ==== Train size ====" << endl;
			cout << " Enter size: ";
			cin >> train_size;
			mytrain.SetSize(train_size);
			
			mytrain.Show_info();			
			cout << "-------------------------" << endl;
			mytrain.Max_car();	
			mytrain.Min_car();		
			mytrain.All_passenger();		
			//mytrain.Show_all_info();
			

			Train my2train(mytrain);
			cout << "\n\n Enter train [2] name : ";
			cin >> name_train;
			my2train.Set_name(name_train);			

			my2train.Show_info();
			cout << "-------------------------" << endl;
			my2train.Max_car();
			my2train.Min_car();
			my2train.All_passenger();
			cout << "-------------------------" << endl;*/
		


	system ("pause");
	return 0;
}