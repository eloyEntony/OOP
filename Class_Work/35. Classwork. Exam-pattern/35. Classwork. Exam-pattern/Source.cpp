#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

/*
Реализуйте с использованием паттернов проектирования простейшую систему планирования задач. 
Должна быть возможность создания списка дел, установки приоритетов, установки дат выполнения, удаление и изменения дел. 
Каждому делу можно установить тег. 
Список дел можно загружать и сохранять в файл. 
Необходимо реализовать возможность поиска конкретного дела. Критерии поиска: по датам, по тегам, по приоритету и так далее.
*/

class Task {
public:
	string task;
	string priority;
	string mark;
	string deth_line;

public:

	vector<Task> my_list;

	/*void Add_to_list() {
		for (size_t i = 0; i < my_list.size(); i++) {
			if (my_list[i] == my_list.back()) {
				cout << my_list[i];
			}
			else {
				cout << my_list[i] << ", ";
			}
		}
		cout << "\n\n";
	}*/

	void Add_to_list(Task *task) {
		my_list.push_back(*task);
	}

};

class Builder {
public:

	virtual ~Builder() {}
	virtual void SET_task(string task = "-") = 0;
	virtual void SET_priority(string priority = "-") = 0;
	virtual void SET_mark(string mark = "-") = 0;
	virtual void SET_deth_line(string deth_line = "-") = 0;
};

class Task_builder : Builder {
private:
	Task *my_task;
	vector<Task> my_list;
public:

	Task_builder() { this->Reset(); }

	void Reset() {
		this->my_task = new Task();
	}

	void SET_task(string task = "-") override {
		this->my_task->task = task;
	};

	void SET_priority(string priority = "-")override {
		this->my_task->priority = priority;
	};

	void SET_mark(string mark = "-") override {
		this->my_task->mark = mark;
	};

	void SET_deth_line(string deth_line = "-") override {
		this->my_task->deth_line = deth_line;
	};

	/*void Write_to_file(Task *task) {
		string path = "data.txt";
		ofstream inFile;

		inFile.open(path);
		inFile << this->my_task << endl;

		inFile.close();
	}*/

	void Create_task() {
		
		my_list.push_back(*my_task);
		
	}
	void Show_vector() {

		for (int i = 0; i < my_list.size(); i++) {
			cout << "TASK      : "<< my_task[i].task << endl;
			cout << "DETH LINE :" << my_task[i].deth_line << endl;
			cout << "PRIORITY  :" << my_task[i].priority << endl;
			cout << "MARK      :" << my_task[i].mark << endl;
			cout << "---------------------------" << endl;
		}
	}



	void Show() {
		cout << "TASK      : "<< my_task->task << endl;
		cout << "DETH LINE :" << my_task->deth_line << endl;
		cout << "PRIORITY  :" << my_task->priority << endl;
		cout << "MARK      :" << my_task->mark << endl;
	}

	Task *Get_task() {
		Task*result = this->my_task;
		this->Reset();
			return result;
	}

};

class Directoc_task {
private:
	Task_builder *builder;

public:
	void Set_builder(Task_builder *builder) { this->builder = builder; }

	void Build_draft(string task /*string deth_linestring, string priority, string mark,*/) {
		this->builder->SET_task(task);
		this->builder->Create_task();

	}

	void Build_elementary_task(string task, string deth_line/*string priority, string mark,*/ ) {
		this->builder->SET_task(task);
		this->builder->SET_deth_line(deth_line);
	}

	void Build_priority_task(string task, string deth_line, string priority /*string mark,*/) {
		this->builder->SET_task(task);		
		this->builder->SET_deth_line(deth_line);
		this->builder->SET_priority(priority);
	}

	void Build_full_task(string task, string deth_line, string priority, string mark) {
		this->builder->SET_task(task);		
		this->builder->SET_deth_line(deth_line);
		this->builder->SET_priority(priority);
		this->builder->SET_mark(mark);
	}

	void Show() {
		this->builder->Show();
	}

	void Write_to_file() {
		string path = "data.txt";
		ofstream inFile;

		inFile.open(path);
		inFile << this->builder << endl;

		inFile.close();
	}

	void Serch() {

	}

};

class Facade {

};

void ClientCode(Directoc_task& director)
{
	Task_builder* builder = new Task_builder();
	director.Set_builder(builder);
	cout << "Standard basic product:\n";
	director.Build_draft("HELLO");
	director.Show();
	director.Write_to_file();

	/*builder->SET_deth_line("12316");
	builder->Show();*/

	//Product1* p = builder->GetProduct();
	//p->ListParts();
	//delete p;

	//std::cout << "Standard full featured product:\n";
	//director.BuildFullFeaturedProduct();

	//p = builder->GetProduct();
	//p->ListParts();
	//delete p;

	//// Помните, что паттерн Строитель можно использовать без класса Директор.
	/*std::cout << "Custom product:\n";
	builder->SET_task("HEllo");*/


	/*builder->ProducePartC();
	p = builder->GetProduct();
	p->ListParts();
	delete p;*/

	delete builder;
}

int main() {

	Directoc_task* director = new Directoc_task();
	ClientCode(*director);
	delete director;


	system("pause");
	return 0;
}