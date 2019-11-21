#include<iostream>
#include<string>
#include<ctime>
#include"Train.h"
#include"TrainCar.h"

using namespace std;

/*�������� �������� ������ � �������, �� ����� ����� Car(�����) �� Train(����).�������� ������� ������ � ��������� :
ʳ������ �����;
ʳ������ ������ ��� ������� �����.

�� ����� �������� ����� ����������� �����, ���������� �������� ���������� ��� ��� �� ���� ��������� ���� :
���� � ����� ����� �������� ������� ��������.
���� � ����� ����� �������� ������� ��������.

���� Car ������� ������ :

����:
���  ������(����, ��������, ��������);
������� �������� � �����
													������ :
													������������
													������ ������� �� ����
													������ ���������� ��� �����

���� Train ������� ������ :

����:
	����� �����;
	����� �����(����������, ��������� "���� - ���");
	���� "������" - �������� �� ��� Car, ����� ���� 
	��������� �������� ���'��� ������� � ������� ������,
	�� ������ ������ ������ ����� �� ����� ������;
	������� ������(���� ���� ����� - ����������).

													������:
														������������: �� ������������, � ����������� �� ���������;
														��������� ������ ������� �� ���� �����;
														����� ��� ����������� ������ � ������������ ������� ��������;
														����� ��� ����������� ������ � ��������� ������� ��������;
														����� ��� ����������� �������� ������� �������� � ����;
														����� ��� ��������� ���������� ��� ���� :
															�������� ������� ��������.
															�������� ������� ������.
															����� ������ � ����� ����� �������� ������� ��������
															����� ������ � ����� ����� �������� ������� ��������.*/

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