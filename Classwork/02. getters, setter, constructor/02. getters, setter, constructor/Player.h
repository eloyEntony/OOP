#pragma once

#include<string>
#include<iostream>
using namespace std;

class Player
{
	string name;
	string country;
	string team;
	string position;
	unsigned int goals;
	int salary;
	int price;

	void UpdatePrice();
	void UpdateGoals(int newGoal);

public:
	Player(string pName, string pCountry, string pTeam, string pPosition, unsigned int pGoals, int pSalary, int pPrice);
	Player();
	void ShowPlayer();
	int GetGoals();
	void SetGoals(int newGoal);
	
};

