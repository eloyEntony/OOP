#include<iostream>
#include<string>
#include<ctime>

using namespace std;

/*Write a class "Account" containing :

	Account number
	The amount of funds in the account
	Name of account currency(rubles, hryvnias, euros, etc.), which can be used with one symbol : R, G, E, $, etc.
	Provide opportunity :
	Open an account and deposit money into the account
	Withdraw money from the account
	Put money into the account
	NOTE!12 points also realize the ability to transfer money from one account to another.

	Написати клас "Банківський рахунок" (Account), який містить:

	Номер рахунку
	Розмір коштів на рахунку
	Назва валюти рахунку (рублі, гривні, евро тощо), для позначення якої можна скористатись одним символом: R, G, E, $ тощо
	Забезпечити можливість:
	Відкривати рахунок та первинно вносити гроші на рахунок
	Знімати гроші з рахунку
	Докладати гроші на рахунок
	ПРИМІТКА! На 12 балів реалізувати також можливість здійснювати переказ грошей з одного рахунку на другий.

*/



class Account {

	int numAccount = 0;
	float money = 0;
	string namevalue;
	int numvalue;

public:

	void Add_money() {
		float m;
		cout << "\n Bank account -> " << numAccount;
		cout << "\n Enter money to add : ";
		cin >> m;

		money += m;
	}

	void Withdraw_money() {
		float m;

		cout << "\n Bank account -> " << numAccount;
		cout << "\n Enter money to windraw : ";
		cin >> m;

		if (money <= 0){
			cout << "\n You cannot withdraw money! " << endl;
			cout << " You have : " << money;
		}
		else if (m > money){
			cout << "\n You cannot withdraw money! " << endl;
			cout << " You have and you can withdraw : " << money;
		}
		else{
			money -= m;
		}		
	}

	void Account_value() 
{
		int choise;		
		cout << "\n\n Enter you value: ";
		cout << "\n [1 -> Euro]  [2 -> Rubl]  [3 -> Dollar]  [4 -> Gruvna]" << endl;
		cin >> choise;


		switch (choise)
		{
		case 1:
			namevalue = "Euro";
			numvalue = 1;
			break;
		case 2:
			namevalue = "Rubl";
			numvalue = 2;
			break;
		case 3:
			namevalue = "$";
			numvalue = 3;
			break;
		case 4:
			namevalue = "Gruvna";
			numvalue = 4;
			break;

		default:
			break;
		}
	}

	void Random_num() {		
			numAccount = rand() % 9000000000 + 1895000000;
			cout << "\n Bank account created!";
			cout <<"\t Bank account : \t" <<numAccount;		
	}

	void Show_Info()
	{
		cout << "\n Num Account: \t\t " << numAccount << endl;
		cout << " Money int account: \t" << money << "  " << namevalue << endl;
		
	}

	void Transfer_add(float transfer_money)
	{
		money += transfer_money;
	}
	void Transfer_withdraw(float transfer_money)
	{
		if (transfer_money > money)
		{
			cout << "\n You cannot withdraw money! " << endl;
			cout << " You have and you can transfer : " << money;
		}
		else
		money -= transfer_money;
	}

	int Return_value()
	{
		return numvalue;
	}


	
};

void Transfer_money(Account &ac1, Account &ac2, int tmp, float transfer_money)
{
	int one = 0;
	int two = 0;
	cout << "\n\t [1] From 1 to 2 " << endl;
	cout << "\t [2] From 2 to 1" << endl;
	cin >> tmp;
	one = ac1.Return_value();
	two = ac2.Return_value();
	

	switch (tmp)
	{
	case 1:
		if (one != two) {
			cout << "\n Transfer cannot be made! Different currency!";
		}
		else {
			cout << "\n Enter transfer money: ";
			cin >> transfer_money;
			ac2.Transfer_add(transfer_money);
			ac1.Transfer_withdraw(transfer_money);
		}
		break;
	case 2:
		if (one != two) {
			cout << "\n Transfer cannot be made! Different currency!";
		}
		else {
			cout << "\n Enter transfer money: ";
			cin >> transfer_money;
			ac1.Transfer_add(transfer_money);
			ac2.Transfer_withdraw(transfer_money);
		}
	default:
		cout << "\n Try again!!!" << endl;
		break;
	}

		
}

int main()
{
	
	Account ac1;
	Account ac2;	

	srand(unsigned(time(NULL)));
	int tmp = 0;
	float transfer_money = 0;
	
	bool exit = false;
	int choise;
	
	while(!exit)
	{
		
		cout << "\n\n\t 1. Created account. \n\t 2. Add money to account # 1 \n\t 3. Add money to account # 2 \n\t 4. Withdraw money to account # 1 \n\t 5. Withdraw money to account # 2 \n\t 6. Show info \n\t 7. Transfer money \n\t 0. Exit" << endl;
		cout << "\n Enter your choise: ";
		cin >> choise;
		cout << "\n\n";
		switch (choise)
		{
		case 1:
			cout << "\n----------------------------------------------------\n [First account] " << endl;
			ac1.Random_num();
			ac1.Account_value();
			cout << "\n----------------------------------------------------\n [Second account] " << endl;
			ac2.Random_num();
			ac2.Account_value();
			break;
		case 2:
			ac1.Add_money();
			break;
		case 3:
			ac2.Add_money();
			break;
		case 4:
			ac1.Withdraw_money();
			break;
		case 5:
			ac2.Withdraw_money();
			break;
		case 6:
			cout << "\n----------------------------------------------------\n [First account] " << endl;
			ac1.Show_Info();
			cout << "\n----------------------------------------------------\n [Second account] " << endl;
			ac2.Show_Info();
			break;
		case 7:
			Transfer_money(ac1, ac2, tmp, transfer_money);			
			break;
		case 0: 
			exit = true;
			break;
		default:

			break;
		}
		
		cout << "\n\n\t\t\t\t Clean screen :  " ;
		system("pause");
		system("cls");
	}

	system("pause");
	return 0;
}