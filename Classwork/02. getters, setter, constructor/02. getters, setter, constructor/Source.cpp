#include <iostream>
#include <string>
#include"Player.h"
#include"Card.h"


using namespace std;

//class Player {
//private:
//	string name;
//	string country;
//	string team;
//	string position;
//	unsigned int goals;
//	int salary;
//	int price;
//	void UpdatePrice() {
//		price += 1000;
//	}
//
//	void UpdateGoals(int newGoal) {
//		goals += newGoal;
//	}
//
//public:
//
//	Player() {
//		cout << "\nDefault constructor rinning....\n" << endl;
//	}
//
//	Player(string pName, string pCountry, string pTeam, string pPosition, unsigned int pGoals, int pSalary, int pPrice) {
//		cout << "\nModefied constructor rinning....\n" << endl;
//		name = pName;
//		country = pCountry;
//		team = pTeam;
//		position = pPosition;
//		goals = pGoals;
//		salary = pSalary;
//		price = pPrice;
//	}
//	void ShowPlayer() {
//		cout << "=======================Show Player====================" << endl;
//		cout << "Name: " << name << "\nCountry: " << country << "\nTeam: " << team << "\nPosition: "
//			<< position << "\nGoals: " << goals << "\nSalary: " << salary << "\nPrice: " << price << endl;
//		cout << "=======================Show Player====================" << endl;
//	}
//
//	int GetGoals() {
//		return goals;
//	}
//
//	void SetGoals(int newGoal) {
//		if (newGoal >= 1) {
//			UpdateGoals(newGoal);
//			UpdatePrice();
//		}
//		else {
//			cout << "R.T.F.M." << endl;
//		}
//
//	}
//};


//int main() {
//
//	Player ronaldo("Cristiano Ronaldo", "Portugal", "Juventus", "Forward", 600, 20000000, 100000000);
//	ronaldo.ShowPlayer();
//
//	int goals = ronaldo.GetGoals();
//	cout << "Ronaldo goals = > " << goals << endl;
//	ronaldo.SetGoals(1);
//	ronaldo.ShowPlayer();
//
//
//	system("pause");
//	return 0;
//}

int main()
{
	bool exit = false;
	int choise = 0;
	double buy = 0;

	Card mycard;

	

	while (!exit) {	
		
		
		mycard.Show_info();
		buy = mycard.Get_All_prise();

		cout << "\n 1. Laptop [ 500 $ ]\n 2. Phone [ 300 $ ]\n 3. TV [ 800 $ ]\n 4. Washing machine [ 1100 $ ]\n 5. Refrigerator [ 900 $ ]\n 0. Exit" << endl;
		cout << " Enter your choise: ";
		cin >> choise;
		switch (choise)
		{
		case 1:
			cout << "\n\n Buy Laptop " << endl;
			buy += 500;
			mycard.Plus_Discont();
			//mycard.Show_info();
			mycard.Set_All_prise(buy);
			break;
		case 2: 
			cout << "\n\n Buy Phone " << endl;
			buy += 300;
			mycard.Plus_Discont();
			//mycard.Show_info();
			mycard.Set_All_prise(buy);
			break;
		case 3:
			cout << "\n\n Buy TV " << endl;
			buy += 800;
			mycard.Plus_Discont();
			//mycard.Show_info();
			mycard.Set_All_prise(buy);
			break;
		case 4:
			cout << "\n\n Buy Washing machine  " << endl;
			buy += 1100;
			mycard.Plus_Discont();
			//mycard.Show_info();
			mycard.Set_All_prise(buy);
			break;
		case 5:
			cout << "\n\n Buy Refrigerator " << endl;
			buy += 900;
			mycard.Plus_Discont();
			//mycard.Show_info();
			mycard.Set_All_prise(buy);
			break;
		case 0:
			cout << " Exit" << endl;
			exit = true;
			break;

		default:
			break;
		}
		system("pause");
		system("cls");
	}
	
	
	system("pause");
	return 0;
}