#include <iostream>
#include<string>
#include<ctime>
#include<iomanip>
using namespace std;

/*
������� ����� "Swordsman" (������), "Archer" (������) � "Mage" (���), 
����� � ���� � ����������� �������� ����� "Unit" (�����, �������) � ����'������ ��,
� ���� ���������, ��������� �� ���� � �������.

� ������� 15 ���-����� (�����), ����������� ��� ����� 5, ���� ��������� 60%.
������: 12 hp, 4 dmg, 40% dodge
���: 8 hp, 10 dmg, 30% dodge

� main() ������� ��� ������ (��������� �������) �� ��� ���� � �������, 
������� ��� ���� (������, ������ �� ���) �� ���������� ���������, 
��� ��������� ��� ������. 

����� ���� ��� ���������� ���� ��������,
���� ���������� ��� ������� ����� ������� � ���� ����,
������ - ������, ������ � ��� ����� ���� ������� � ������� � �.�.

��� � ���� ��������� �� �� ����, ���� ���� ���� � ����� �� �� ��������. 
� ������� ��� ����� �������� ����������� ��� ���� ��������, �� ������� �����, 
������ ����� ���������� � ������ �� ���� ��������. ����� �� ���������� ���������, 
�� ���������� ������ spacebar (������), ��� �� ����� ����������� ���� ����� �� ������.

� ���� ��� ��������, ��� ������� ��������� 
(�����/�����, ����/�������, ������/���� - �� ��� ���� ������� ��� �������).

�� �������� �������� ���������� ���� ���, �� �� ���������.
*/

class Unit{
public:
	string name;
	short HP;
	short attack;
	short evade_attacks;
	bool die = false;

	Unit() {};

	template<typename T>
	void Attack(T &other){

		int A = rand() % 100 + 1;

		if (A > other.evade_attacks && this->die == false && other.die == false) {
			other.HP -= this->attack;
			cout << setw(10) << this->name << setw(15) << " attack " << setw(15) << other.name << endl;
		}
		else if (A < other.evade_attacks && this->die == false && other.die == false)		
			cout << setw(10) << this->name << setw(15) << " missed " << setw(15) << other.name << endl;

		else if (other.die == true)	
			cout << setw(10) << this->name << setw(15) << " DIE --> "<< setw(15) << other.name << endl;

		else if (this->die == true)
			cout << setw(10) << this->name << setw(15) << " <-- DIE " << setw(15) << other.name << endl;
		
	}

	void Show_info(){
		cout << " UNIT : "<<setw(10) << this->name << setw(10) <<"| AT : ["  << this->attack<<"]" << setw(10) << " | HP : ("<< this->HP <<")"<< endl;
	}

};

class Swordsman: public Unit{
public:
	Swordsman()	{
		this->name = "Swordsman";
		this->HP = 15;
		this->attack = 5;
		this->evade_attacks = 60;
		this->die = false;
	}
};

class Archer : public Unit{
public:
	Archer() {
		this->name = "Archer";
		this->HP = 12;
		this->attack = 4;
		this->evade_attacks = 40;
		this->die = false;
	}
};

class Mage : public Unit{
public:
	Mage() {
		this->name = "Mage";
		this->HP = 8;
		this->attack = 10;
		this->evade_attacks = 30;
		this->die = false;
	}
};

void Fill_team(Unit *team, const int size){
	for (int i = 0; i < size; i++)	{
		int R = rand() % 3 + 1;
		if (R == 1) team[i] = Swordsman();
		else if (R == 2) team[i] = Archer();
		else team[i] = Mage();
	}
}

void Attack_team(Unit *team1, Unit *team2, int size){	
	for (int i = 0; i < size; i++)	{
		team1[i].Attack(team2[i]);
		if (team2[i].HP <= 0){
			team2[i].HP = 0;
			team2[i].attack = 0;
			team2[i].die = true;
		}
			
	}	
}

void Show_team(Unit *team, int size){
	for (int i = 0; i < size; i++) {		
		team[i].Show_info();	
	}
}

int main()
{
	srand(unsigned(time(NULL)));

	const int size = 3;

	Unit *RED_team = new Unit[size];
	Unit *BLUE_team = new Unit[size];

	Fill_team(RED_team, size);
	Fill_team(BLUE_team, size);

	///////////////////////////////////////////////////////////////////////
	cout << "\n ~~~~~~~~~~~~~~ RED_team ~~~~~~~~~~~~~~" << endl;
	Show_team(RED_team, size);

	cout << "\n ~~~~~~~~~~~~~~ BLUE_team ~~~~~~~~~~~~~~" << endl;
	Show_team(BLUE_team, size);

	

	for (int i = 0; i < 5; i++)	{
		cout << "\n\n\n   ATTACK # "<< i <<"\n"<< endl;

		cout << "\n RED TEAM ~~~~~~~~~~~~~~~~~~~~~~~ BLUE TEAM \n" << endl;
		Attack_team(RED_team, BLUE_team, size);
		cout << "\n-------------------------------------------------" << endl;
		cout << "\n BLUE TEAM ~~~~~~~~~~~~~~~~~~~~~~ RED TEAM \n" << endl;
		Attack_team(BLUE_team, RED_team, size);

		cout << "\n~~~~~~~~~~~~~~~~~~ INFO ~~~~~~~~~~~~~~~~~~" << endl;
		cout << "\n [RED] " << endl;
		Show_team(RED_team, size);
		cout << "\n\n [BLUE] " << endl;
		Show_team(BLUE_team, size);
	}


	cout << "\n---------------------------------------------------------------------------\n\n\n\n" << endl;
	cout << "\n ~~~~~~~~~~~~~~ RED_team ~~~~~~~~~~~~~~" << endl;
	Show_team(RED_team, size);
	cout << "\n ~~~~~~~~~~~~~  BLUE_team ~~~~~~~~~~~~~" << endl;
	Show_team(BLUE_team, size);

	system("pause");
	return 0;
}