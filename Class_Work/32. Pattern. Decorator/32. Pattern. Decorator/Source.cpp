
/*
В програмі - грі, розробленій на минулих заняттях додати можливість
створення різних типів юнітів. До кожного з юнітів додати можливість модифікації в різні
типи юнітів: броньованого юніта, прискореного юніта, влучного юніта. 
Використати патерн Декоратор.
*/
#include<iostream>
#include<string>
#include<ctime>
#include<iomanip>
using namespace std;

class Unit abstract{
public:
	string type;
	short hp;
	short attack;
	short evade_attacks;
	bool die = false;
	
	template<typename T>
	void Attack(T &other) {

		int A = rand() % 100 + 1;

		if (A > other.evade_attacks && this->die == false && other.die == false) {
			other.hp -= this->attack;
			cout << setw(10) << this->type << setw(15) << " attack -->" << setw(15) << other.type << endl;
		}
		else if (A < other.evade_attacks && this->die == false && other.die == false)
			cout << setw(10) << this->type << setw(15) << " |missed| " << setw(15) << other.type << endl;

		else if (this->die == false && other.die == true)
			cout << setw(10) << this->type << setw(15) << " DIE --> " << setw(15) << other.type << endl;

		else if (this->die == true && other.die == false)
			cout << setw(10) << this->type << setw(15) << " <-- DIE " << setw(15) << other.type << endl;
		else
			cout << setw(10) << this->type << setw(15) << "         " << setw(15) << other.type << endl;
	}

	virtual void Show_info() {
		cout << " UNIT : " << setw(10) << this->type << setw(10) << "| AT : [" << this->attack << "]" << setw(10) << " | HP : (" << this->hp << ")" << setw(10) <<
			" | Evade : ("<<this->evade_attacks<<")"<< endl;
	}

	virtual ~Unit(){}
	virtual short Update_HP(short hp=0) = 0;
	virtual short Update_attack(short attack = 0) = 0;
	virtual short Update_evade_attacks(short evade = 0) = 0;

};

class Decorator : public Unit {
protected:
	Unit *unit_;

public:
	Decorator(Unit *unit) : unit_(unit){}
	short Update_HP(short hp = 0)				override { return this->unit_->Update_HP(); }
	short Update_attack(short attack = 0)		override { return this->unit_->Update_attack();	}
	short Update_evade_attacks(short evade = 0) override { return this->unit_->Update_evade_attacks();	}
};

class Decorator_HP : public Decorator {
public:
	Decorator_HP(Unit *unit) : Decorator(unit) {}
	short Update_HP(short hp = 0) override { return this->unit_->Update_HP(10); }
};

class Decorator_ATTACK : public Decorator {
public:
	Decorator_ATTACK(Unit *unit) : Decorator(unit) {}
	short Update_attack(short attack = 0) override { return this->unit_->Update_attack(10); }
};

class Decorator_evade_attacks : public Decorator {
public:
	Decorator_evade_attacks(Unit *unit) : Decorator(unit) {}
	short Update_evade_attacks(short evade = 0) override { return this->unit_->Update_evade_attacks(10); }
};

class Swordsman : public Unit {
public:
	Swordsman() {
		this->type = "Swordsman";
		this->hp = 15;
		this->attack = 5;
		this->evade_attacks = 60;
		this->die = false;
	}
	
	short Update_HP(short hp = 0)				override { return this->hp += hp;  };
	short Update_attack(short attack = 0)		override { return this->attack += attack; };
	short Update_evade_attacks(short evade = 0)	override { return this->evade_attacks += evade; };
};

class Archer : public Unit {
public:
	Archer() {
		this->type = "Archer";
		this->hp = 12;
		this->attack = 4;
		this->evade_attacks = 40;
		this->die = false;
	}
	short Update_HP(short hp = 0)				override { return this->hp += hp; };
	short Update_attack(short attack = 0)		override { return this->attack += attack; };
	short Update_evade_attacks(short evade = 0)	override { return this->evade_attacks += evade; };
};

class Mage :  public Unit {
public:
	Mage() {
		this->type = "Mage";
		this->hp = 8;
		this->attack = 10;
		this->evade_attacks = 30;
		this->die = false;
	}
	short Update_HP(short hp = 0)				override { return this->hp += hp; };
	short Update_attack(short attack = 0)		override { return this->attack += attack; };
	short Update_evade_attacks(short evade = 0)	override { return this->evade_attacks += evade; };
};

class Team {
public:
	//string name_team;
	const int size = 3;

	//Unit *RED_team = new Unit[size];
	//Unit *BLUE_team = new Unit[size];*/

	/*Unit *RED_team;
	Unit *BLUE_team;*/

	
	
	
	

	/*bool Death_unit(Unit *team, int size) {
		int count = 0;
		for (int i = 0; i < size; i++) {
			if (team[i].die == true) {
				count++;
			}
		}
		if (count == 3) return true;
		else return false;
	}

	void Show_team(Unit *&team, int size) {
		for (int i = 0; i < size; i++) {
			team[i].Show_info();
		}
	}*/

	/*void Fill_team(Team *&team) {
		for (int i = 0; i < 3; i++) {
			int R = rand() % 3 + 1;

			if (R == 1) team[i] = *u1;
			else if (R == 2) team[i] = *u2;
			else team[i] = *u3;
		}
	};*/

};


//void Attack(Unit *team1, Unit *team2, int size) {
//	for (int i = 0; i < size; i++) {
//
//		if (team1[i].type == team2[0].type && team2[0].die == false) { team1[i].Attack(team2[0]); }
//		else if (team1[i].type == team2[1].type && team2[1].die == false) { team1[i].Attack(team2[1]); }
//		else if (team1[i].type == team2[2].type && team2[2].die == false) { team1[i].Attack(team2[2]); }
//		else if (team1[i].type != team2[0].type && team2[0].die == false) { team1[i].Attack(team2[0]); }
//		else if (team1[i].type != team2[1].type && team2[1].die == false) { team1[i].Attack(team2[1]); }
//		else if (team1[i].type != team2[2].type && team2[2].die == false) { team1[i].Attack(team2[2]); }
//
//		if (team2[i].hp <= 0) {
//			team2[i].hp = 0;
//			team2[i].attack = 0;
//			team2[i].die = true;
//		}
//	}
//}
//class Game : public Team {
//public:
//
//	void Create_team(Team *&team1, Team* &team2) {
//		Fill_team(team1);
//		Fill_team(team2);
//	}
//
//	void WAR(Unit *team1, Unit* team2) {
//		cout << "\n-------------------------------------------" << endl;
//		cout << " RED                                  BLUE " << endl;
//		cout << "-------------------------------------------" << endl;
//		Attack(team1, team2, size);
//		cout << "\n-------------------------------------------" << endl;
//		cout << " BLUE                                  RED " << endl;
//		cout << "-------------------------------------------" << endl;
//		Attack(team1, team2, size);
//	}
//
//	void Show_info(Unit *&team1, Unit*& team2) {
//		cout << "\n-RED-------------------------------------" << endl;
//		Show_team(team1, size);
//		cout << "\n-BLUE------------------------------------" << endl;
//		Show_team(team2, size);
//		cout << "------------------------------------------" << endl;
//	}
//
//	int Exit(Unit *team1, Unit* team2) {
//		if (Death_unit(team1, size) == true) {
//			return 2;
//		}
//		if (Death_unit(team2, size) == true) {
//			return 1;
//		}
//		else return 0;
//	}
//};

void Up_HP(Unit *unit) {	unit->Update_HP();}
void Up_AT(Unit *unit) {	unit->Update_attack();}
void Up_EV(Unit *unit) {	unit->Update_evade_attacks(); }



int main()
{
	Unit *u1 = new Swordsman;
	Unit *u2 = new Archer;
	Unit *u3 = new Mage;


	u1->Show_info();

	Unit *u1_ = new Decorator_HP(u1);
	Up_HP(u1_);
	Unit *u1__ = new Decorator_ATTACK(u1);
	Up_AT(u1__);
	Unit *u1___ = new Decorator_evade_attacks(u1);
	Up_EV(u1___);

	u1->Show_info();

	cout << "--------------------------" << endl;

	u2->Show_info();

	Unit *u2_ = new Decorator_ATTACK(u2);
	Up_AT(u2_);	
	Unit *u2_2 = new Decorator_HP(u2);
	Up_HP(u2_2);
	Unit *u1_3 = new Decorator_evade_attacks(u2);
	Up_EV(u1_3);

	u2->Show_info();



	/*Team *RED_team = new Team[3];
	Team *BLUE_team = new Team[3];*/


	/*Unit *u1 = new Swordsman;
	Unit *u2 = new Archer;
	Unit *u3 = new Mage;*/
	
	/*Game game;
	game.Create_team(RED_team, BLUE_team);
	game.Show_info(RED_team, BLUE_team);*/

	//srand(unsigned(time(NULL)));
	//bool game_over = false;
	//int win_team = 0;
	//Game game;
	//game.Create_team(RED_team, BLUE_team);
	//game.Show_info(RED_team, BLUE_team);

	/*while (!game_over) {

		cout << "\n\n________________________________________________________________________________________________________\n\n" << endl;
		game.WAR(RED_team, BLUE_team);
		game.Show_info(RED_team, BLUE_team);
		win_team = game.Exit(RED_team, BLUE_team);

		if (win_team == 1) {
			cout << "\t\t\t\t\t\t\t  !!! WIN RED TEAM !!! " << endl;
			system("color 47");
			game_over = true;
		}
		else if (win_team == 2) {
			cout << "\t\t\t\t\t\t\t  !!! WIN BLUE TEAM !!! " << endl;
			system("color 17");
			game_over = true;
		}
		else cout << "\t\t\t\t\t\t\t Battle continue ... " << endl;

		system("pause");
	}
*/
	system("pause");
	return 0;
}