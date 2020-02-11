#include<iostream>
#include<string>

using namespace std;
/*
class Presedent {

	string name;
	
	Presedent(string name) : name(name) {};
	~Presedent() {};

	Presedent(const Presedent&) = delete;
	Presedent& operator = (const Presedent&) = delete;

public:

	static Presedent& getObj(string name = "user") {
	
		static Presedent obj(name);
		return obj;
	};
	void Show_info() {
		cout << " Name    : " << name << endl;
	}
};


int main() {
	
	Presedent &s = Presedent::getObj("Bob");
	s.Show_info();

	Presedent&v = Presedent::getObj("Biil");		
	v.Show_info();	


	system("pause");
	return 0;
}
*/
/*class Singelton {

	Singelton() = default;
	~Singelton() = default;

	Singelton(const Singelton&) = delete; //відміна створення , констуктор копій
	Singelton& operator =(const Singelton&) = delete;//відміна створення
	void* operator new(size_t) = delete;//відміна створення
	void* operator new[](size_t) = delete;//відміна створення
	void operator delete(void*) = delete;//відміна створення
	void operator delete[](void*) = delete;//відміна створення

public:
	static Singelton& getInst() {
		static Singelton obj; //створення обєкта класу
		return obj;
	}
};

void foo() {
	auto& a = Singelton::getInst();
	cout << &a << endl;
}
void bar() {
	auto& b = Singelton::getInst();
	cout << &b << endl;
}

int main() {

	auto& s = Singelton::getInst();
	foo();
	bar();
	cout << &s << endl;

	system("pause");
	return 0;
}*/


//1. Написати клас Logger в якому можна залогінитись лише один раз. (Singleton)
//у випадку якщо екземпляр класу вже створений, повертати відповідне повідомлення



class Logger {

	string log;
	
	static Logger *obj;
	Logger(string log):log(log) {};
	~Logger() {};

	Logger (const Logger&) = delete;
	Logger& operator = (const Logger&) = delete;

public:	

	static Logger& getObj(string log = "user") {

		if (obj == nullptr) {
			obj = new Logger(log);
		}
		else {
			cout << "Object is created... his NIK => "<<obj->getName() << endl;
			//Logger::getName();
		}
		//static Logger obj(log);
		return *obj;
	}

	string getName(){
		return this->log;
	}

	/*void setObj(string name){
		this->log = name;
	}*/

};

Logger*Logger::obj = nullptr;

int main()
{
	string log;

	cout << " Enter log-name : ";
	cin >> log;
	Logger &a = Logger::getObj(log);	

	cout << a.getName() << endl;

	cout << "\n----------------------------------" << endl;
	

	cout << " Enter log-name : ";
	cin >> log;
	Logger &b = Logger::getObj(log);
	
	//cout << b.getName() << endl;

	cout << "\n Enter log-name : ";
	cin >> log;
	Logger &c = Logger::getObj(log);


	system("pause");
	return 0;
}