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
		train[i].Train_number();
		
		//train[i].Show_info();
		cout << "-------------------------" << endl;

	}

	for (int i = 0; i < train_count; i++)
	{
		train[i].Show_info();
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