#include<iostream>
#include<string>
#include<fstream>
using namespace std;

/*
Создать класс СПРАВОЧНИК со следующими полями:
1. Название фирмы;
2. Владелец;
3. Телефон;
4. Адрес;
5. Род деятельности.
Реализовать следующие возможности:
1. Поиск по названию;
2. Поиск по владельцу;
3. Поиск по номеру телефона;
4. Поиск по роду деятельности;
5. Показ всех записей и добавление.
Вся информация, должна сохранятся в бинарном файле, должна быть реализована
возможность добавления новых данных.
*/

class Directory {
private:
	string company_name;
	string owner;
	string phone;
	string address;
	string work;
public:

	Directory(string company_name = " ", string owner = " ", string phone = " ", string address = " ", string work = " ") {	}

	void Fill() {
		
		for (int i = 0; i < 1; i++) {
			cout << " Company name : ";
			cin >> company_name;
			cout << " Owner        : ";
			cin >> owner;
			cout << " Phone        : ";
			cin >> phone;
			cout << " Address      : ";
			cin >> address;
			cout << " Work         : ";
			cin >> work;
		}
	}
	void Show_directory() {

		for (int i = 0; i < 1; i++) {
			cout << " Company name : " << company_name << endl;
			cout << " Owner        : " << owner << endl;
			cout << " Phone        : " << phone << endl;
			cout << " Address      : " << address << endl;
			cout << " Work         : " << work << endl;
		}
	}

};

void Create_object() {
	int size;

	cout << " Enter size directory : ";
	cin >> size;

	Directory *my_directory = new Directory[size];

	//Directory my_directory[size];

	for (int i = 0; i < size; i++) {
		my_directory[i].Fill();
	}
	cout << "\n\n ______________________________________________________________" << endl;
	cout << "\t ================ DIRECTORY ================\n" << endl;
	for (int i = 0; i < size; i++) {
		cout << " # " << i + 1 << endl;
		my_directory[i].Show_directory();
	}
	

	ofstream _fp("test.txt", ios::binary);
	_fp << size;
	_fp.write(reinterpret_cast<char*>(&my_directory), sizeof(Directory)*size);
	delete[] my_directory;
	_fp.close();

	Directory * final;
	    final = new Directory[size];
	
	    ifstream is("test.txt", ios::binary);
	    is.read(reinterpret_cast<char *>(final), sizeof(Directory) * size);
     is.close();
	
	 final[0].Show_directory();

}

void Search_for_name() {


}

void Search_for_owner() {


}

void Search_for_phone() {


}
void Search_for_work() {


}

void Write_to_file() {

	
}

int main()
{
	Create_object();


	system("pause");
	return 0;
}