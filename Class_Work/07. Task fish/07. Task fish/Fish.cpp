#include "Fish.h"



Fish::Fish(){	
}

Fish::Fish(char ruba){
	this->live_fish++;
	this->ruba = ruba;	
}

void Fish::Create(){
	this->x = rand() % 9 + 0;
	this->y = rand() % 9 + 0;	
}

void Fish::Moving(){
	bool q = rand() % 2;
	bool w = rand() % 2;	
	
	if(q == true)					this->x ++;// рандомне переміщення риби
	else if (q == false)			this->x --;
	if(w == true)					this->y ++;
	else if (w == false)			this->y --;
	
	if (this->x < 0)		 {	this->x += 2;   }  // якщо риба підходить до краю моря, то повертається назад		
	else if (this->x > 9)	 {	this->x -= 2;	}
	if (this->y < 0)		 {	this->y += 2;	}
	else if (this->y > 9)	 {	this->y -= 2;	}
	if (this->health <= 0) { this->x = 0; this->y = 0; this->health = 0; } // якщо риба мертва її координати = 0
	
		Health();
		Deth();

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (i == x && j == y) {
					if (this->health < 0) {
						this->sea[i][j] = more; // якщо здоровя риби <= 0, риба не виводиться
					}						
					else{
						this->sea[i][j] = ruba;
						if (i == vodorosl_x[0] && j == vodorosl_y[0]) { this->health = 100; } //якщо риба поавдає на водорослі, її здоровя стає 100
						else if (i == vodorosl_x[1] && j == vodorosl_y[1]) { this->health = 100; }
						else if (i == vodorosl_x[2] && j == vodorosl_y[2]) { this->health = 100; }
						else if (i == vodorosl_x[3] && j == vodorosl_y[3]) { this->health = 100; }
						else if (i == vodorosl_x[4] && j == vodorosl_y[4]) { this->health = 100; }
					
					}						
				}
			}
		}

}



void Fish::Show_fish_info(){
	cout << "\n ID " << this->ruba << " |  Coordinates  ";
	cout << " [X] -> " << this->x << "  [Y] -> " << this->y ;	
	cout << "    |    Health ->  " << this->health << " % " << endl;	
}

void Fish::Show_sea(){		
	cout << "\n\n\n";
	for (int i = 0; i < 10; i++){	
		cout << "\t\t";
		for (int j = 0; j < 10; j++) {	
			cout << "  " << sea[i][j];					
		}
		cout << "\n\n";
	}
	cout  << endl;

}

void Fish::Live(){
	cout << " LIVE FISH : " << live_fish << endl;
}

void Fish::Sea(){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++) {				
			if (i == vodorosl_x[0] && j==vodorosl_y[0])			{ sea[i][j] = vodorosl; }				
			else if (i == vodorosl_x[1] && j == vodorosl_y[1])	{ sea[i][j] = vodorosl; }				
			else if (i == vodorosl_x[2] && j == vodorosl_y[2])	{ sea[i][j] = vodorosl; }
			else if (i == vodorosl_x[3] && j == vodorosl_y[3])	{ sea[i][j] = vodorosl; }
			else if (i == vodorosl_x[4] && j == vodorosl_y[4])	{ sea[i][j] = vodorosl; }	
			else
			sea[i][j] = more;
		}
	}
}

void Fish::Health(){
	if (health < 0)
		health = 0;

	else
	health -=1;		
}

void Fish::Vodorosli(){
	for (int i = 0; i < 5; i++)	{
		vodorosl_x[i] = rand() % 9 + 0;
		vodorosl_y[i] = rand() % 9 + 0;
	}
}

int Fish::Get_health(){
	if (this->health > 0)
		return this->health;
	else
		return 0;
}

void Fish::Deth(){
	if (health <= 0)
		live_fish-=1;
}

Fish::~Fish()
{	
}
