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
		cout << "\tALL TASK : " << my_list.size()<<"\n\n"<< endl;
		for (int i = 0; i < my_list.size(); i++) {
			cout << " # " << my_list[i].number << endl;
			cout << " TASK      : "<< my_list[i].task << endl;
			cout << " DETH LINE : " << my_list[i].deth_line << endl;
			cout << " PRIORITY  : " << my_list[i].priority << endl;
			cout << " MARK      : " << my_list[i].mark << endl;
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
		bool good = false;
		string tmp;
		cout << "\n\t====SERCH====\n\t [1] By date.\n\t [2] By teg.\n\t [3] By priority. " << endl;
		cout << "\n\t Enter your choise : ";
		cin >> choise;

		switch (choise)
		{
		case 1:
			cout << "\n Enter date /00.00.00/ : ";
			cin >> tmp;
			for (int i = 0; i < my_list.size(); i++) {
				if (tmp == my_list[i].deth_line) {		
					cout << "---------------------------" << endl;
					cout << "\n    #         : " << my_list[i].number << endl;
					cout << "    TASK      : " << my_list[i].task << endl;		
					cout << "->> DETH LINE : " << my_list[i].deth_line << endl;
					cout << "    PRIORITY  : " << my_list[i].priority << endl;
					cout << "    MARK      : " << my_list[i].mark << endl;
					cout << "---------------------------" << endl;
					good = true;
				}
			}
			if (good == false) {
				cout << "\n\t Tasks not detected !" << endl;
			}
			break;
		case 2:
			cout << "\n Enter teg /#teg/ : ";
			cin >> tmp;
			for (int i = 0; i < my_list.size(); i++) {
				if (tmp == my_list[i].mark) {
					cout << "---------------------------" << endl;
					cout << "\n    #         : " << my_list[i].number << endl;
					cout << "    TASK      : " << my_list[i].task << endl;
					cout << "    DETH LINE : " << my_list[i].deth_line << endl;					
					cout << "    PRIORITY  : " << my_list[i].priority << endl;
					cout << "->> MARK      : " << my_list[i].mark << endl;
					cout << "---------------------------" << endl;
					good = true;
				}
			}
			if (good == false) {
				cout << "\n\t Tasks not detected !" << endl;
			}
			break;
		case 3: 
			cout << "\n Enter priority /string/ : ";
			cin >> tmp;
			for (int i = 0; i < my_list.size(); i++) {
				if (tmp == my_list[i].priority) {
					cout << "---------------------------" << endl;
					cout << "\n    #         : " << my_list[i].number << endl;
					cout << "    TASK      : " << my_list[i].task << endl;
					cout << "    DETH LINE : " << my_list[i].deth_line << endl;					
					cout << "->> PRIORITY  : " << my_list[i].priority << endl;
					cout << "    MARK      : " << my_list[i].mark << endl;
					cout << "---------------------------" << endl;
					good = true;
				}
			}
			if (good == false) {
				cout << "\n\t Tasks not detected !" << endl;
			}
			break;
		default:
			cout << "\n\t Wrong choise." << endl;
			break;
		}
	}

	void Change_task() {
		int choise;
		int choise2;
		string tmp;
		cout << "\n\t Select a task : \n" << endl;
		Show();
		cout << "\n\n\t Enter your choise : ";
		cin >> choise;	

		for (int i = 0; i < my_list.size(); i++) {
			if (choise == my_list[i].number) {

				cout << "\n\t [1] Task.      [4] Mark. " << endl;
				cout << "\t [2] Data.      [5] All task." << endl;
				cout << "\t [3] Priority.  [0] Exit." << endl;
				cout << "\n Enter what you want to change : ";
				cin >> choise2;
				switch (choise2)
				{
					case 1:
						cout << "\n Enter new task : ";
						cin.ignore();
						getline(cin, tmp);
						my_list[i].task = tmp;

						cout << "---------------------------" << endl;
						cout << "\n # -> " << my_list[i].number << endl;
						cout << " TASK      : " << my_list[i].task << endl;
						cout << " DETH LINE : " << my_list[i].deth_line << endl;
						cout << " PRIORITY  : " << my_list[i].priority << endl;
						cout << " MARK      : " << my_list[i].mark << endl;
						cout << "---------------------------" << endl;
						break;
					case 2:
						cout << "\n Enter new deth line : ";
						cin.ignore();
						getline(cin, tmp);
						my_list[i].deth_line = tmp;

						cout << "---------------------------" << endl;
						cout << "\n # -> " << my_list[i].number << endl;
						cout << " TASK      : " << my_list[i].task << endl;
						cout << " DETH LINE : " << my_list[i].deth_line << endl;
						cout << " PRIORITY  : " << my_list[i].priority << endl;
						cout << " MARK      : " << my_list[i].mark << endl;
						cout << "---------------------------" << endl;
						break;
					case 3:
						cout << "\n Enter new priority : ";
						cin.ignore();
						getline(cin, tmp);
						my_list[i].priority = tmp;

						cout << "---------------------------" << endl;
						cout << "\n # -> " << my_list[i].number << endl;
						cout << " TASK      : " << my_list[i].task << endl;
						cout << " DETH LINE : " << my_list[i].deth_line << endl;
						cout << " PRIORITY  : " << my_list[i].priority << endl;
						cout << " MARK      : " << my_list[i].mark << endl;
						cout << "---------------------------" << endl;
						break;
					case 4:
						cout << "\n Enter new mark : ";
						cin.ignore();
						getline(cin, tmp);
						my_list[i].mark = tmp;

						cout << "---------------------------" << endl;
						cout << "\n # -> " << my_list[i].number << endl;
						cout << " TASK      : " << my_list[i].task << endl;
						cout << " DETH LINE : " << my_list[i].deth_line << endl;
						cout << " PRIORITY  : " << my_list[i].priority << endl;
						cout << " MARK      : " << my_list[i].mark << endl;
						cout << "---------------------------" << endl;
						break;
					case 5:
						cout << "\n Enter new task : ";
						cin.ignore();
						getline(cin, tmp);
						my_list[i].task = tmp;
						cout << " Enter new deth line : ";
						getline(cin, tmp);
						my_list[i].deth_line = tmp;
						cout << " Enter new priority : ";
						getline(cin, tmp);
						my_list[i].priority = tmp;
						cout << " Enter new mark : ";
						getline(cin, tmp);
						my_list[i].mark = tmp;

						cout << "---------------------------" << endl;
						cout << "\n # -> " << my_list[i].number << endl;
						cout << " TASK      : " << my_list[i].task << endl;
						cout << " DETH LINE : " << my_list[i].deth_line << endl;
						cout << " PRIORITY  : " << my_list[i].priority << endl;
						cout << " MARK      : " << my_list[i].mark << endl;
						cout << "---------------------------" << endl;
						break;
					case 0:
						break;
					default:
						break;
				}				
			}			
		}
	}

	void Delete_task() {
		int choise;
		cout << "\n\t Select a task : \n\n";		
		Show();
		cout << "\n\t Enter choise : ";
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

void Choice_of_task(Directoc_task &director) {
	int choice;
	int number;
	string task;
	string priority;
	string mark;
	string deth_line;
	bool exit = false;
	Task_builder* builder = new Task_builder();
	cout << "\t [1] Draft (only task)                [3] Task with priority   " << endl;
	cout << "\t [2] Elementary (task and data)       [4] Full task (with mark) " << endl;
	cout << "\t [0] Back " << endl;
	cout << "\n\t >>> Enter : ";
	cin >> choice;
	
	switch (choice){
		case 1:
			cout << "\n Enter new task : ";
			cin.ignore();
			getline(cin, task);
			director.Set_builder(builder);
			director.Build_draft(task);
			director.Create();
			break;
		case 2:
			cout << "\n Enter new task : ";
			cin.ignore();
			getline(cin, task);
			cout << " Enter new deth line : ";
			getline(cin, deth_line);
			director.Set_builder(builder);
			director.Build_elementary_task(task, deth_line);
			director.Create();
			break;
		case 3:
			cout << "\n Enter new task : ";
			cin.ignore();
			getline(cin, task);
			cout << " Enter new deth line : ";
			getline(cin, deth_line);
			cout << " Enter new priority : ";
			getline(cin, priority);
			director.Set_builder(builder);
			director.Build_priority_task(task, deth_line, priority);
			director.Create();
			break;
		case 4:
			cout << "\n Enter new task : ";
			cin.ignore();
			getline(cin, task);
			cout << " Enter new deth line : ";
			getline(cin, deth_line);
			cout << " Enter new priority : ";
			getline(cin, priority);
			cout << " Enter new mark : ";
			getline(cin, mark);
			director.Set_builder(builder);
			director.Build_full_task(task, deth_line, priority, mark);
			director.Create();
			break;
		case 0:			
			break;
		default:
			cout << " Wrong choice ! \n" << endl;
			break;
	}
	delete builder;
	
}

void Menu(Directoc_task &director)
{
	int choise;
	bool exit = false;
	

	while (!exit) {
		cout << "\n\t____________________________________________________________\n" <<
			"\t\t   <<<<<  T A S K    P L A N N I N G  >>>>>\n\t____________________________________________________________\n\t" << endl;
		cout << "\n\t\t\t<<< MENU >>>\n" << endl;
		cout << "\t [1] Add task.             [5] Change task." << endl;
		cout << "\t [2] Show all task.        [6] Save task to file." << endl;
		cout << "\t [3] Search task.          [7] Download tasks from file." << endl;
		cout << "\t [4] Delete task.          [0] Exit." << endl;
		cout << "\n\t >>> Enter : ";
		cin >> choise;
		cout << "\n\n";
		switch (choise)	{
			case 1 : 
				Choice_of_task(director);
				system("cls");
				break;
			case 2:
				director.Show();
				system("pause");
				system("cls");
				break;
			case 3:
				director.Serch();
				system("pause");
				system("cls");
				break;
			case 4:
				director.Delete_task();
				system("pause");
				system("cls");
				break;
			case 5:
				director.Change_task();
				system("pause");
				system("cls");
				break;
			case 6:
				director.Write_to_file();
				system("pause");
				system("cls");
				break;
			case 7:
				director.Read_from_file();
				system("cls");
				break;
			case 0:
				exit = true;
				break;
			default:
				cout << " Wrong choice ! \n" << endl;
				break;
		}
	}
}

int main() {

	Directoc_task* director = new Directoc_task();
	Menu(*director);
	delete director;

	system("pause");
	return 0;
}