#include<iostream>
#include<string>

using namespace std;

//Завдання 1.  Використати шаблон Абстрактна фабрика.
//Створити фабрики для створення кнопок та прапорців для ОС Windows, Macintosh  в залежності від вибору користувача.
//Створити клас Клієнт(Application) для перевірки роботи фабрик.
//Діаграма класів подібно https ://refactoring.guru/uk/design-patterns/abstract-factory



class Buttons_and_checkboxes {
protected:
	virtual void Show() const = 0;
	virtual ~Buttons_and_checkboxes(){};
};

class Fabrica {
protected:
	virtual Buttons_and_checkboxes *Create()const = 0;
};

class Win_but : Buttons_and_checkboxes {
public:
	void Show() const override { cout << " Windows button X" << endl; }
};

class Mac_but : Buttons_and_checkboxes {
public:
	void Show() const override { cout << " MacOS button X" << endl; }
};

class Windows : Fabrica {

};

class Mac : Fabrica {

};

int main()
{
	system("pause");
	return 0;
}