/*
Описати клас "Fortress" (Фортеця).

Для початку, напишіть клас "Shooter" (стрілець), який буде містити два поля: назва аммуніції та її кількість. 
Він може виконати дію "постріл" і витратити для цього одиницю амуніції, повідомляючи в консоль, як вона називалась. 
А також може здійснити дію "дати амуніцію", яка встановлюватиме назву і кількість амуніції, отримуючі ці дані через параметри.

Стрілець має три дочірні класи: "Archer" (Лучник), "Ranger" (Рейнджер) та "Catapult" (Катапульта),
які заміщають дію "постріл", доповнюючи повідомлення в консоль інформацією про те, 
хто саме з них вистрілив. Перші два повинні стріляти стрілами, а катапульта - каменями.

Від перших двох породжується клас "ArcherTower" (Cтрілкова вежа),
у якої запас амуніції має бути один (спільний) для обох: лучника і рейнджера 
(подумайте, який механізм множинного успадкування тут варто застосувати).

Від класів "стрілкова вежа" і "катапульта" має походити клас "Fortress". 
Лише в її конструкторі мають поставлятись стріли для стрілкової вежі і камені для катапульти.
Додайте до фортеці ще кілька полів - товщина стін, стан воріт у відсотках, і т.д. - по вашому бажанню та фантазії.

Більше ніяких допоміжних методів чи об'єктів створювати не потрібно. 
В кожного з полів чи методів у цій ієрархії має бути встановлений максимальний рівень захисту,
і успадкування має відбуватись по найвищо-допустимому по захисту специфікаторові доступу. 
Але таким, щоб в main() можна було виконати наступне:

- створити об'єкт фортеці
- вистрілити тричі лучником, двічі рейнджером і раз з катапульти
Отже, всього має бути 6 класів, вінцем творіння і фінальним дитям серед них є клас "Фортеця", 
лише один об'єкт якої буде створено. Зверніть на це увагу - 6 класів описано, всі використовуються.
Але об'єкт у всій програмі один.

ПРИМІТКИ! Коли створюватиметься фортеця, доставте в стрілкову вежу лише 4 стріли,
тоді буде явно видно, що на другий постріл рейнджеру стріл не вистачить,
оскільки лучник перед тим витратив 3 із 4-х стріл.


*/


#include<iostream>
#include<string>

using namespace std;

class Shooter {
public:
	string ammunition;
	int count_ammunition;	

	Shooter(string ammunition = "bomba", int count = 0) {
		this->ammunition = ammunition;
		this->count_ammunition = count;
	}
	void Shot(string ammunition)	{
		if (this->count_ammunition > 0) {
			this->count_ammunition--;
			cout << "\t\t Shot " << ammunition << " Left : " << this->count_ammunition << endl;
		}
		else
			cout << " NOOO" << endl;				
	}

	void Give_ammunition(string ammun, int count_ammun)	{
		this->ammunition = ammun;
		this->count_ammunition = count_ammun;
		cout << "------------------------------" << endl;
		cout << " Ammunition : " << this->ammunition << endl;
		cout << " Count ammunition : " << this->count_ammunition << endl;
		cout << "------------------------------" << endl;
	}

};

class Archer : virtual public Shooter {
public:
	Archer(string ammunition = "arrow", int count_ammunition = 0) 	{
		//Archer::Give_ammunition(ammunition, count_ammunition);		
	}
	void Shot() {	
		cout << "  --> Archer" << endl;
		Shooter::Shot("arrow");
	}
};

class Ranger :virtual public Shooter {
public:
	Ranger(string ammunition = "arrow", int count_ammunition = 0) {
		//Ranger::Give_ammunition(ammunition, count_ammunition);
	}
	void Shot() {
		cout << "  --> Ranger" << endl;
		Shooter::Shot("arrow");
	}
};

class Catapult :virtual public Shooter {
public:
	Catapult(string ammunition = "stones", int count_ammunition = 0) {
		//Catapult::Give_ammunition(ammunition, count_ammunition);
	}
	void Shot() {
		cout << "  --> Catapult" << endl;
		Shooter::Shot("stones");
	}
};

class ArcherTower : public Archer, public Ranger{
public:
	ArcherTower(string ammunition = "arrow", int count_ammunition = 0) {
		Shooter::count_ammunition = count_ammunition;
		Shooter::ammunition = ammunition;
	}

};

class Fortress : public ArcherTower, public Catapult {
public:
	Fortress(int arrow_count) {
		ArcherTower::count_ammunition = arrow_count;
		//Catapult::count_ammunition = stones_count;
	}
};

int main() {

	Fortress fort(4);

	fort.Archer::Shot();
	fort.Archer::Shot();
	fort.Archer::Shot();
	fort.Archer::Shot();
	cout << "\n----------------" << endl;
	fort.Ranger::Shot();
	cout << "\n----------------" << endl;
	fort.Catapult::Shot();

	system("pause");
	return 0;
}