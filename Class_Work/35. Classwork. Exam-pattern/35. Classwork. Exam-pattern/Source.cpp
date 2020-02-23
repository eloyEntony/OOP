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
	int number;
	string task;
	string priority;
	string mark;
	string deth_line;
};

vector<Task> my_list;

class Builder {
public:
	virtual ~Builder() {}
	virtual void SET_task(string task = "-") = 0;
	virtual void SET_priority(string priority = "-") = 0;
	virtual void SET_mark(string mark = "-") = 0;
	virtual void SET_deth_line(string deth_line = "-") = 0;
};

class Task_builder : public Builder {
private:
	Task *my_task;
	
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

	void Create_task() {
		my_task->number = my_list.size()+1;
		my_list.push_back(*my_task);
	}

	Task *Get_task() {
		Task*result = this->my_task;
		this->Reset();
			return result;
	}

	~Task_builder(){}
};

class Directoc_task {
private:
	Task_builder *builder;

public:
	void Set_builder(Task_builder *builder) { this->builder = builder; }

	void Build_draft(string task /*string deth_linestring, string priority, string mark,*/) {
		this->builder->SET_task(task);	
		this->builder->SET_deth_line();
		this->builder->SET_priority();
		this->builder->SET_mark();
	}

	void Build_elementary_task(string task, string deth_line/*string priority, string mark,*/ ) {
		this->builder->SET_task(task);
		this->builder->SET_deth_line(deth_line);
		this->builder->SET_priority();
		this->builder->SET_mark();
	}

	void Build_priority_task(string task, string deth_line, string priority /*string mark,*/) {
		this->builder->SET_task(task);		
		this->builder->SET_deth_line(deth_line);
		this->builder->SET_priority(priority);
		this->builder->SET_mark();
	}

	void Build_full_task(string task, string deth_line, string priority, string mark) {
		this->builder->SET_task(task);		
		this->builder->SET_deth_line(deth_line);
		this->builder->SET_priority(priority);
		this->builder->SET_mark(mark);
	}

	void Create() {		this->builder->Create_task();	}

	void Show() {
		cout << "SIZE : " << my_list.size() << endl;

		for (int i = 0; i < my_list.size(); i++) {
			cout << "# " << my_list[i].number << endl;
			cout << "TASK      : "<< my_list[i].task << endl;
			cout << "DETH LINE : " << my_list[i].deth_line << endl;
			cout << "PRIORITY  : " << my_list[i].priority << endl;
			cout << "MARK      : " << my_list[i].mark << endl;
			cout << "---------------------------" << endl;
		}
	}

	void Write_to_file() {
		string path = "data.txt";
		ofstream inFile;
		inFile.open(path);
		inFile << my_list.size() << endl;
		for (int i = 0; i < my_list.size(); i++) {
			inFile << my_list[i].number << endl;
			inFile << my_list[i].task << endl;
			inFile << my_list[i].deth_line << endl;
			inFile << my_list[i].priority << endl;
			inFile << my_list[i].mark << endl;
		}
		inFile.close();
	}

	void Serch() {
		int choise;
		string tmp;
		cout << "\n\t====SERCH====\n [1] By date.\n [2] By teg.\n [3] By priority. " << endl;
		cout << "\n Enter your choise : ";
		cin >> choise;

		switch (choise)
		{
		case 1:
			cout << "\n Enter date /00.00.00/ : ";
			cin >> tmp;
			for (int i = 0; i < my_list.size(); i++) {
				if (tmp == my_list[i].deth_line) {					
					cout << "\n    TASK      : " << my_list[i].task << endl;		
					cout << "->> DETH LINE : " << my_list[i].deth_line << endl;
					cout << "    PRIORITY  : " << my_list[i].priority << endl;
					cout << "    MARK      : " << my_list[i].mark << endl;
					cout << "---------------------------" << endl;
				}
			}			
			break;
		case 2:
			cout << "\n Enter teg /#teg/ : ";
			cin >> tmp;
			for (int i = 0; i < my_list.size(); i++) {
				if (tmp == my_list[i].mark) {
					cout << "\n    DETH LINE : " << my_list[i].deth_line << endl;
					cout << "    TASK      : " << my_list[i].task << endl;
					cout << "    PRIORITY  : " << my_list[i].priority << endl;
					cout << "->> MARK      : " << my_list[i].mark << endl;
					cout << "---------------------------" << endl;
				}
			}
			break;
		case 3: 
			cout << "\n Enter priority /string/ : ";
			cin >> tmp;
			for (int i = 0; i < my_list.size(); i++) {
				if (tmp == my_list[i].priority) {
					cout << "\n   DETH LINE : " << my_list[i].deth_line << endl;
					cout << "    TASK      : " << my_list[i].task << endl;
					cout << "->> PRIORITY  : " << my_list[i].priority << endl;
					cout << "    MARK      : " << my_list[i].mark << endl;
					cout << "---------------------------" << endl;
				}
			}
			break;
		default:
			cout << " Wrong choise." << endl;
			break;
		}
	}

	void Change_task() {
		int choise;
		int choise2;
		string tmp;
		cout << "\n Select a task : " << endl;
		Show();

		cout << "\n Enter your choise : ";
		cin >> choise;
	

		for (int i = 0; i < my_list.size(); i++) {
			if (choise == my_list[i].number) {

				cout << "\n [1] Task. [2] Data. [3] Priority. [4] Mark. [5] All task.";
				cout << "\n Enter what you want to change : ";
				cin >> choise2;
				switch (choise2)
				{
				case 1:
					cout << " Enter new task : ";
					cin >> tmp;
					my_list[i].task = tmp;

					cout << "---------------------------" << endl;
					cout << "\n # " << my_list[i].number << endl;
					cout << " TASK      : " << my_list[i].task << endl;
					cout << " DETH LINE : " << my_list[i].deth_line << endl;
					cout << " PRIORITY  : " << my_list[i].priority << endl;
					cout << " MARK      : " << my_list[i].mark << endl;
					cout << "---------------------------" << endl;

					break;
				case 2:
					cout << " Enter new deth line : ";
					cin >> tmp;
					my_list[i].deth_line = tmp;

					cout << "---------------------------" << endl;
					cout << "\n # " << my_list[i].number << endl;
					cout << " TASK      : " << my_list[i].task << endl;
					cout << " DETH LINE : " << my_list[i].deth_line << endl;
					cout << " PRIORITY  : " << my_list[i].priority << endl;
					cout << " MARK      : " << my_list[i].mark << endl;
					cout << "---------------------------" << endl;

					break;
				case 3:
					cout << " Enter new priority : ";
					cin >> tmp;
					my_list[i].priority = tmp;

					cout << "---------------------------" << endl;
					cout << "\n # " << my_list[i].number << endl;
					cout << " TASK      : " << my_list[i].task << endl;
					cout << " DETH LINE : " << my_list[i].deth_line << endl;
					cout << " PRIORITY  : " << my_list[i].priority << endl;
					cout << " MARK      : " << my_list[i].mark << endl;
					cout << "---------------------------" << endl;

					break;
				case 4:
					cout << " Enter new mark : ";
					cin >> tmp;
					my_list[i].mark = tmp;

					cout << "---------------------------" << endl;
					cout << "\n # " << my_list[i].number << endl;
					cout << " TASK      : " << my_list[i].task << endl;
					cout << " DETH LINE : " << my_list[i].deth_line << endl;
					cout << " PRIORITY  : " << my_list[i].priority << endl;
					cout << " MARK      : " << my_list[i].mark << endl;
					cout << "---------------------------" << endl;

					break;
				case 5:
					break;
					cout << " Enter new task : ";
					cin >> tmp;
					my_list[i].task = tmp;
					cout << " Enter new deth line : ";
					cin >> tmp;
					my_list[i].deth_line = tmp;
					cout << " Enter new priority : ";
					cin >> tmp;
					my_list[i].priority = tmp;
					cout << " Enter new mark : ";
					cin >> tmp;
					my_list[i].mark = tmp;

					cout << "---------------------------" << endl;
					cout << "\n # " << my_list[i].number << endl;
					cout << " TASK      : " << my_list[i].task << endl;
					cout << " DETH LINE : " << my_list[i].deth_line << endl;
					cout << " PRIORITY  : " << my_list[i].priority << endl;
					cout << " MARK      : " << my_list[i].mark << endl;
					cout << "---------------------------" << endl;

				default:
					break;
				}				
			}			
		}
	}

	void Delete_task() {
		int choise;
		cout << "\n Select a task : \n\t";		
		Show();
		cout << " Enter choise : ";
		cin >> choise;

		for (int i = 0; i<my_list.size(); i++) {
			if ((choise-1) == i) {
				my_list.erase(my_list.begin() + i);
			}
		}		
	}

	void Read_from_file() {
		Task my_task;
		ifstream readFile;
		char temp[255];
			

		readFile.open("data.txt");

		if (!readFile.is_open()) {
			cout << "Can't open file!\n";
		}
		else {
			int size = 0, i = 0;
			readFile.getline(temp, 255);
			size = atoi(temp);
			while (i < size) {

				readFile.getline(temp, 255);
				my_task.number = atoi(temp);

				readFile.getline(temp, 255);
				my_task.task = temp;

				readFile.getline(temp, 255);
				my_task.deth_line = temp;

				readFile.getline(temp, 255);
				my_task.priority = temp;

				readFile.getline(temp, 255);
				my_task.mark = temp;

				my_list.push_back(my_task);
				i++;
			}
		}
		readFile.close();		
	}
};

class Facade {

};

void ClientCode(Directoc_task &director)
{

	/*Task_builder* builder = new Task_builder();
	director.Set_builder(builder);
	director.Build_draft("HELLO");
	director.Create();

	Task_builder* builder2 = new Task_builder();
	director.Set_builder(builder2);
	director.Build_draft("HELLO2");
	director.Create();

	Task_builder* builder3 = new Task_builder();
	director.Set_builder(builder3);
	director.Build_full_task("1", "2", "3", "4");
	director.Create();*/


	/*director.Show();
	director.Write_to_file();

	director.Serch();

	director.Change_task();
*/
	//director.Delete_task();
	//director.Write_to_file();
	director.Read_from_file();
	director.Show();

	/*delete builder;
	delete builder2;*/
}

int main() {

	Directoc_task* director = new Directoc_task();
	ClientCode(*director);
	delete director;


	system("pause");
	return 0;
}