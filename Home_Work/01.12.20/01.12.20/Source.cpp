/*
������� ���� "Fortress" (�������).

��� �������, �������� ���� "Shooter" (�������), ���� ���� ������ ��� ����: ����� �������� �� �� �������. 
³� ���� �������� �� "������" � ��������� ��� ����� ������� �������, ����������� � �������, �� ���� ����������. 
� ����� ���� �������� �� "���� �������", ��� ��������������� ����� � ������� �������, ��������� �� ��� ����� ���������.

������� �� ��� ������ �����: "Archer" (������), "Ranger" (��������) �� "Catapult" (����������),
�� �������� �� "������", ���������� ����������� � ������� ����������� ��� ��, 
��� ���� � ��� ��������. ����� ��� ������ ������� �������, � ���������� - ��������.

³� ������ ���� ����������� ���� "ArcherTower" (C������� ����),
� ��� ����� ������� �� ���� ���� (�������) ��� ����: ������� � ��������� 
(���������, ���� ������� ���������� ������������ ��� ����� �����������).

³� ����� "�������� ����" � "����������" �� �������� ���� "Fortress". 
���� � �� ����������� ����� ������������ ����� ��� �������� ��� � ����� ��� ����������.
������� �� ������� �� ����� ���� - ������� ���, ���� ���� � ��������, � �.�. - �� ������ ������� �� �����糿.

������ ����� ��������� ������ �� ��'���� ���������� �� �������. 
� ������� � ���� �� ������ � ��� �������� �� ���� ������������ ������������ ����� �������,
� ������������ �� ���������� �� �������-����������� �� ������� �������������� �������. 
��� �����, ��� � main() ����� ���� �������� ��������:

- �������� ��'��� �������
- ��������� ����� ��������, ���� ���������� � ��� � ����������
����, ������ �� ���� 6 �����, ����� ������� � ��������� ����� ����� ��� � ���� "�������", 
���� ���� ��'��� ��� ���� ��������. ������� �� �� ����� - 6 ����� �������, �� ����������������.
��� ��'��� � ��� ������� ����.

���̲���! ���� ���������������� �������, �������� � �������� ���� ���� 4 �����,
��� ���� ���� �����, �� �� ������ ������ ��������� ���� �� ���������,
������� ������ ����� ��� �������� 3 �� 4-� ����.


*/


#include<iostream>
#include<string>

using namespace std;

class Shooter {
public:
	string ammunition;
	int count_ammunition;	

	Shooter(string ammunition = "bomba", int count = 0) {
		this->ammunition = ammunition;
		this->count_ammunition = count;
	}
	void Shot(string ammunition)	{
		if (this->count_ammunition > 0) {
			this->count_ammunition--;
			cout << "\t\t Shot " << ammunition << " Left : " << this->count_ammunition << endl;
		}
		else
			cout << " NOOO" << endl;				
	}

	void Give_ammunition(string ammun, int count_ammun)	{
		this->ammunition = ammun;
		this->count_ammunition = count_ammun;
		cout << "------------------------------" << endl;
		cout << " Ammunition : " << this->ammunition << endl;
		cout << " Count ammunition : " << this->count_ammunition << endl;
		cout << "------------------------------" << endl;
	}

};

class Archer : virtual public Shooter {
public:
	Archer(string ammunition = "arrow", int count_ammunition = 0) 	{
		//Archer::Give_ammunition(ammunition, count_ammunition);		
	}
	void Shot() {	
		cout << "  --> Archer" << endl;
		Shooter::Shot("arrow");
	}
};

class Ranger :virtual public Shooter {
public:
	Ranger(string ammunition = "arrow", int count_ammunition = 0) {
		//Ranger::Give_ammunition(ammunition, count_ammunition);
	}
	void Shot() {
		cout << "  --> Ranger" << endl;
		Shooter::Shot("arrow");
	}
};

class Catapult :virtual public Shooter {
public:
	Catapult(string ammunition = "stones", int count_ammunition = 0) {
		//Catapult::Give_ammunition(ammunition, count_ammunition);
	}
	void Shot() {
		cout << "  --> Catapult" << endl;
		Shooter::Shot("stones");
	}
};

class ArcherTower : public Archer, public Ranger{
public:
	ArcherTower(string ammunition = "arrow", int count_ammunition = 0) {
		Shooter::count_ammunition = count_ammunition;
		Shooter::ammunition = ammunition;
	}

};

class Fortress : public ArcherTower, public Catapult {
public:
	Fortress(int arrow_count) {
		ArcherTower::count_ammunition = arrow_count;
		//Catapult::count_ammunition = stones_count;
	}
};

int main() {

	Fortress fort(4);

	fort.Archer::Shot();
	fort.Archer::Shot();
	fort.Archer::Shot();
	fort.Archer::Shot();
	cout << "\n----------------" << endl;
	fort.Ranger::Shot();
	cout << "\n----------------" << endl;
	fort.Catapult::Shot();

	system("pause");
	return 0;
}