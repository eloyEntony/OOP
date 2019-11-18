#include<iostream>
#include<string>
#include<ctime>

using namespace std;

/*class Point {
private:

int x = 0;
int y = 0; 

public:

	void SetPoint()
	{
		cout << " Enter X: ";
		cin >> x;
		cout << " Enter Y: ";
		cin >> y;
	}

	void ShowPoint() {
		cout << " X -> " << x << "\n Y -> " << y <<endl;
	}

	void ChangePoint()
	{		
		char choise = ' ';
		cout << "\n Enter what do you want change: (X or Y)";

		cin >> choise;

		if (choise == 'x')
		{
			cout << " Enter X: ";
			cin >> x;
		}

		else if (choise == 'y')
		{
			cout << " Enter Y: ";
			cin >> y;
		}

		else
			cout << " Error" << endl;
	}

};

int main()
{
	Point point;

	point.SetPoint();
	point.ShowPoint();
	point.ChangePoint();

	point.ShowPoint();

	system("pause");
	return 0;
}*/


class Account {	

	int numAccount = 0;
	float money = 0;
	char namevalue;
	

public:

	void Add_money() {
		float m;
		cout << " Enter money to add : ";
		cin >> m;

		money += m;
	}

	void Withdraw_money() {
		float m;
		cout << " Enter money to windraw : ";
		cin >> m;

		money += m;
	}

	void Account_value() {
		int choise;
		cout << " Enter you value: ";
		cout << "\n [1] Euro \n [2] Rubl \n [3] Dollar\n [4] Gruvna" << endl;
		cin >> choise;
		

		switch (choise)
		{
		case 1:
			namevalue = 'E';
			break;
		case 2: 
			namevalue = 'R';
			break;
		case 3:
			namevalue = '$';
			break;
		case 4:
			namevalue = 'G';
			break;

		default:
			break;
		}
	}

	void Created_Account()
	{
		Random_num();
		Account_value();
		Add_money();

	}
	void Random_num() {
		numAccount = rand() % 1000000 + 90000000;
	}

	void Show_Info()
	{
		cout << " Num Account: " << numAccount;
		cout << " Money int account: " << money;
		cout << " Value account: " << namevalue;
	}
};

int main()
{
	Account ac1;

	srand(unsigned(time(NULL)));

	cout << " 1. Created account. \n 2. Add money to account. \n 3. Withdraw money from the account. \n 4. Exit.\n 5. Show info." << endl;
	bool exit = false;
	int choise;
	cout << "Enter your choise: ";
	cin >> choise;
	while (!exit)
	{
		switch (choise)
		{
		case 1:
			ac1.Created_Account();
			break;
		case 2:
			ac1.Add_money();
			break;
		case 3:
			ac1.Withdraw_money();
			break;		
		case 4:
			exit = true;
		case 5:
			ac1.Show_Info();
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}