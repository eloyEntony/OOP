#include<iostream>
#include<string>
#include<map>
using namespace std;

/*Створити класи Клієнт, Банк, Рахунок(номер рахунку, пароль, сума).
У класі Рахунок визначити методи отримання інформації про кошти на рахунку 
та зняття з рахунку певної суми.
Створити клас Банкомат, який надаватиме сервіси зняття грошей та інформації по
рахунку певному клієнту.Використати патерн Proxy.*/

/*
__interface IBank {
public:
	void Get_info() const  = 0;
	void Get_money() const = 0;
};

class Account : public IBank{

	int account_number;
	string password;
	double cash = 0;

public:
	Account() {};

	void Get_info() const override {
		cout << " Account number : " << this->account_number << endl;
		cout << " Password       : " << this->password << endl;
		cout << " Cash           : " << this->cash << endl;
	}

	void Get_money() const override {
		double money;

		cout << "Enter money to get : ";
		cin >> money;

		if (money > this->cash) {
			cout << " Dont to get soo big" << endl;
		}
		else {
			this->cash - money;
		}
	}

};

class ATM : public IBank{
	Account * account_;

public:
	ATM() {};
	ATM(Account * account) : account_(account){
	}

	~ATM() {
		delete account_;
	}

};

class Client {
	int my_account;
	string my_pass;
	bool go;
	ATM *my_atm;

public:

	Client() {};
	
	void open_account() {
		cout << " Enter your account number : ";
		cin >> my_account;
		cout << " Enter your password : ";
		cin >> my_pass;

		cout << " Get money : ";
		cin >> go;
	}
	6
};

int main()
{
	system("pause");
	return 0;
}
*/

/* 
Створити клас Студент(прізвище, ім’я, оцінка у 100 бальній шкалі). 
Створити клас - адаптер класу Студент, який надає інший спосіб
виведення оцінки студента (у шкалі A-F).
*/

class Student {
	string name;
	string surname;
	int mark;

public:

	Student() {	
		cout << " Enter name         : ";
		cin >> name;
		cout << " Enter surname      : ";
		cin >> surname;
		cout << " Enter mark (1-100) : ";
		cin >> mark;
	};

	void Show_mark() {
		cout << " MARK    : " << mark <<"\n"<< endl;
	}

	void Show_info() {
		cout << "\n NAME    : " <<name << endl;
		cout << " SURNAME : "<<surname << endl;		
	}

	int Get_mark() {
		return this->mark;
	}

	~Student() {};
};

__interface IStudent {
public:
	void Show_mark();	
};

class New_student : public IStudent , public Student{
public:
	void Show_mark() {
		if (Get_mark() <= 16) cout << " MARK    : A " << endl;
		else if (Get_mark() > 16 && Get_mark() <= 32) cout << " MARK    : B " << endl;
		else if (Get_mark() > 32 && Get_mark() <= 48) cout << " MARK    : C " << endl;
		else if (Get_mark() > 48 && Get_mark() <= 64) cout << " MARK    : D " << endl;
		else if (Get_mark() > 64 && Get_mark() <= 80) cout << " MARK    : E " << endl;
		else if (Get_mark() > 80 && Get_mark() <= 100) cout << " MARK   : F " << endl;
	}
};

void stud() {
	Student student;	
	student.Show_info();
	student.Show_mark();
};

void new_stud(){
	New_student student;	
	student.Show_info();
	student.Show_mark();
};

int main() {

	stud();
	new_stud();

	system("pause");
	return 0;
}