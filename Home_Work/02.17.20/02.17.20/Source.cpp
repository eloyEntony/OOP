#include<iostream>
#include<string>

using namespace std;

//Завдання 1.  Використати шаблон Абстрактна фабрика.
//Створити фабрики для створення кнопок та прапорців для ОС Windows, Macintosh  
//в залежності від вибору користувача.
//Створити клас Клієнт(Application) для перевірки роботи фабрик.
//Діаграма класів подібно https ://refactoring.guru/uk/design-patterns/abstract-factory



class Buttons {
public:
	virtual string Show() const = 0;
	virtual ~Buttons(){};
};

class Win_but : public Buttons {
public:
	string Show() const override { return " Windows button"; }
};

class Mac_but : public Buttons {
public:
	string Show() const override { return  " MacOS button "; }
};


class Checkboxes {
public:
	virtual string Show() const = 0;
	virtual ~Checkboxes() {};
};

class Win_box : public Checkboxes {
public:
	string Show() const override { return " Windows Checkboxes" ; }
};

class Mac_box : public Checkboxes {
public:
	string Show() const override { return " MacOS Checkboxes "; }
};



__interface Fabrica_abstruct {
public:
	virtual Buttons *Create_but()const = 0;
	virtual Checkboxes *Create_box()const = 0;
};


class Windows : public Fabrica_abstruct {
public:
	Buttons *Create_but()const override {
		return new Win_but();
	}
	Checkboxes *Create_box()const override {
		return new Win_box();
	}
};

class Mac : public Fabrica_abstruct {
public:
	Buttons *Create_but()const override {
		return new Mac_but();
	}
	Checkboxes *Create_box()const override {
		return new Mac_box();
	}
};

class Application{
public:
	Application() {};
	void Show(const Fabrica_abstruct &factory){
		const Buttons * buttons = factory.Create_but();
		const Checkboxes * checkboxes = factory.Create_box();

		cout << "\n----------------\n ";
		cout << buttons->Show();
		cout << "\n ";
		cout << checkboxes->Show() << endl;	

		delete buttons;
		delete checkboxes;
	}
	~Application() {};
};



int main(){
	bool exit = false;
	int choise;
	Windows *w = new Windows();
	Mac *m = new Mac();
	Application app;	

	while (!exit) {

		cout << "\n----------------\n [1] Windows \n [2] Mac \n [0] Exit \n\n Enter : ";
		cin >> choise;
		switch (choise)
		{
			case 1:
				app.Show(*w);
				break;
			case 2:
				app.Show(*m);
				break;
			case 0:
				delete w;
				delete m;
				exit = true;
			default:
				break;
		}
	}
	
	return 0;
}