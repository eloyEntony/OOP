#include<iostream>
#include<string>
#include<ctime>
#include<iomanip>
using namespace std;

/*Опишіть класи Swordsman (Мечник), Archer (Лучник) і Mage (Маг), кожен з яких є
екземпляром базового(можна абстрактного) класу Unit (штука, елемент) в компютерній
грі, і може атакувати, ухилятись від атак і вмирати.
У мечника 15 хіт-поінтів (життів), пошкодження при атаці 5, шанс ухилятись 60%.
Лучник: 12 hp, 4 dmg, 40% dodge
Маг: 8 hp, 10 dmg, 30% dodge

-------------------------------------------------------------------------------------------------------------
Опишіть клас Team(Команда), у якому є поля
o назва команди
o масив чи вектор по три(чи більше) юніта,
причому тип юніта (мечник, лучник чи маг) має задаватись випадково, при
заповненні команди(на початку гри).
Написати методи:
o перевірки чи у команді є не вбиті гравці
o виводу гравців команди
-------------------------------------------------------------------------------------------------------------
Опишіть клас Game(Гра), що містить 2 команди ворогуючих сторін
Можливі варіанти ворогуючих сторін: три лучники проти мечника і двох магів, або -
лучник, мечник і маг проти двох мечників і лучника і т.д(при кількості гравців у команді
3).
Опишіть метод бою між КОМАНДАМИ, поки бійці однієї з сторін всі не загинуть. В
консоль при цьому виводьте повідомлення хто кого атакував, чи вдалась атака, скільки
життя залишилось у жертви чи вона загинула. Нехай бій відбувається поступово, по
натиснення клавіші spacebar (пробіла), щоб ми могли спостерігати його атака за атакою.
В кінці бою оголосіть, яка команда перемогла (перша/друга, синя/червона, альянс/орки чи
ін.).
...............................................................................................................
Правила бою : кожен боєць (Воїн, Лучник чи Маг) вишукує серед ворогів суперника свого
типу і атакує його.
Скажімо, якщо маємо команди:
A11 - M21
A12 - S22
S13 - A23
...то А11 має вибрати своєї ціллю А23.
Якщо ворогів свого типу не знайдено, тоді нехай бійці атакують довільного суперника*/


class Unit {
public:
	string type;
	short hp;
	short attack;
	short evade_attacks;
	bool die = false;

	Unit() {};

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

	void Show_info() {
		cout << " UNIT : " << setw(10) << this->type << setw(10) << "| AT : [" << this->attack << "]" << setw(10) << " | HP : (" << this->hp << ")" << endl;
	}

};

class Swordsman : virtual public Unit {
public:
	Swordsman() {
		this->type = "Swordsman";
		this->hp = 15;
		this->attack = 5;
		this->evade_attacks = 60;
		this->die = false;
	}
};

class Archer :virtual public Unit {
public:
	Archer() {
		this->type = "Archer";
		this->hp = 12;
		this->attack = 4;
		this->evade_attacks = 40;
		this->die = false;
	}
};

class Mage : virtual public Unit {
public:
	Mage() {
		this->type = "Mage";
		this->hp = 8;
		this->attack = 10;
		this->evade_attacks = 30;
		this->die = false;
	}
};

class Team {
public:
	string name_team;
	const int size = 3;

	Unit *RED_team = new Unit[size];
	Unit *BLUE_team = new Unit[size];


	bool Death_unit(Unit *team, int size){
		int count=0;
		for (int i = 0; i < size; i++) {
			if (team[i].die == true) {
				count++;
			}		
		}
		if (count == 3) return true;
		else return false;
	}

	void Show_team(Unit *team, int size) {
		for (int i = 0; i < size; i++) {
			team[i].Show_info();
		}
	}

};


void Fill_team(Unit *team, const int size){
	for (int i = 0; i < size; i++) {
		int R = rand() % 3 + 1;
		if (R == 1) team[i] = Swordsman();
		else if (R == 2) team[i] = Archer();
		else team[i] = Mage();
	}
};

void Attack(Unit *team1, Unit *team2, int size) {
	for (int i = 0; i < size; i++) {

		if      (team1[i].type == team2[0].type && team2[0].die == false){		team1[i].Attack(team2[0]);		}	
		else if (team1[i].type == team2[1].type && team2[1].die == false){		team1[i].Attack(team2[1]);		}
		else if (team1[i].type == team2[2].type && team2[2].die == false){		team1[i].Attack(team2[2]);		}
		else if (team1[i].type != team2[0].type && team2[0].die == false){		team1[i].Attack(team2[0]);		}
		else if (team1[i].type != team2[1].type && team2[1].die == false){		team1[i].Attack(team2[1]);		}
		else if (team1[i].type != team2[2].type && team2[2].die == false){		team1[i].Attack(team2[2]);		}

		if (team2[i].hp <= 0) {
			team2[i].hp = 0;
			team2[i].attack = 0;
			team2[i].die = true;
		}
	}
}
class Game: public Team{
public:
		
	void Create_team() {
		Fill_team(RED_team, size);
		Fill_team(BLUE_team, size);
	}

	void WAR() {
		cout << "\n-------------------------------------------" << endl;
		cout << " RED                                  BLUE " << endl;
		cout << "-------------------------------------------" << endl;
		Attack(RED_team, BLUE_team, size);
		cout << "\n-------------------------------------------" << endl;
		cout << " BLUE                                  RED " << endl;
		cout << "-------------------------------------------" << endl;
		Attack(BLUE_team, RED_team, size);
	}

	void Show_info() {
		cout << "\n-RED-------------------------------------" << endl;
		Show_team(RED_team, size);		
		cout << "\n-BLUE------------------------------------" << endl;
		Show_team(BLUE_team, size);
		cout << "------------------------------------------" << endl;
	}

	int Exit() {		
		if (Death_unit(RED_team, size) == true) {
			return 2;
		}
		if (Death_unit(BLUE_team, size) == true) {
			return 1;
		}
		else return 0;
	}	
};




int main()
{
	srand(unsigned(time(NULL)));
	bool game_over = false;
	int win_team = 0;
	Game game;
	game.Create_team();
	game.Show_info();

	while (!game_over) {
	
		cout << "\n\n________________________________________________________________________________________________________\n\n" << endl;
		game.WAR();
		game.Show_info();
		win_team = game.Exit();
		
		if (win_team == 1){
			cout << "\t\t\t\t\t\t\t  !!! WIN RED TEAM !!! " << endl;
			system("color 47");
			game_over = true;
		}
		else if (win_team == 2){
			cout << "\t\t\t\t\t\t\t  !!! WIN BLUE TEAM !!! " << endl;
			system("color 17");
			game_over = true;
		}
		else cout << "\t\t\t\t\t\t\t Battle continue ... " << endl;		

		system("pause");
	}	

	system("pause");
	return 0;
}