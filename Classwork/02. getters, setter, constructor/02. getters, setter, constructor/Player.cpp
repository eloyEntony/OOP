#include "Player.h"
#include<iostream>
#include<string>

using namespace std;
		
		void Player::UpdatePrice() {
			price += 1000;
		}	
		void Player::UpdateGoals(int newGoal) {
			goals += newGoal;
		}	
		Player::Player() {
			cout << "\nDefault constructor rinning....\n" << endl;
		}	
		Player::Player(string pName, string pCountry, string pTeam, string pPosition, unsigned int pGoals, int pSalary, int pPrice) {
			cout << "\nModefied constructor rinning....\n" << endl;
			name = pName;
			country = pCountry;
			team = pTeam;
			position = pPosition;
			goals = pGoals;
			salary = pSalary;
			price = pPrice;
		}
		void Player::ShowPlayer() {
			cout << "=======================Show Player====================" << endl;
			cout << "Name: " << name << "\nCountry: " << country << "\nTeam: " << team << "\nPosition: "
				<< position << "\nGoals: " << goals << "\nSalary: " << salary << "\nPrice: " << price << endl;
			cout << "=======================Show Player====================" << endl;
		}	
		int Player::GetGoals() {
			return goals;
		}	
		void Player::SetGoals(int newGoal) {
			if (newGoal >= 1) {
				UpdateGoals(newGoal);
				UpdatePrice();
			}
			else {
				cout << "R.T.F.M." << endl;
			}
	
		}
