#include<iostream>
#include<string>

using namespace std;

/*
Реализовать базу данных ГАИ по штрафным квитанциям с помощью бинарного дерева. 
Ключом будет служить номер автомашины, значением узла — список правонарушений. 
Если квитанция добавляется в первый раз,то в дереве появляется новый узел, 
а в списке данные по правонарушению; если нет, то данные заносятся в существующий список. 
Необходимо также реализовать следующие операции:
•	 Полная распечатка базы данных (по номерам машини списку правонарушений, числящихся за ними);
•	 Распечатка данных по заданному номеру;
•	 Распечатка данных по диапазону номеров.
*/

struct GAI {
	string auto_number;
	string offenses[5] = { ".", ".", ".", ".", "."};
	struct GAI *left;
	struct GAI *right;
};

GAI *Create_new_data(string auto_number, string offenses){
	GAI *newGai = new GAI();
	newGai->auto_number = auto_number;
	newGai->offenses[0] = offenses;
	newGai->left = newGai->right = NULL;
	return newGai;
}

GAI *Insert(GAI *root, string auto_number, string offenses) {
	if (root == NULL) { root = Create_new_data(auto_number, offenses); }
	else if (auto_number <= root->auto_number) { root->left = Insert(root->left, auto_number, offenses); }
	else { root->right = Insert(root->right, auto_number, offenses); }
	return root;
}

void Search(GAI *root, string auto_number){
	if (root == NULL){  
		cout << " There is no such car in the database. " << endl;
	}
	else if (root->auto_number == auto_number){ 
		cout << " AUTO NUMBER : " << root->auto_number << endl;
		cout << " OFFENSES    : " << endl;
		for (int i = 0; i < 5; i++) {
			cout << "  ~ | " << root->offenses[i] << endl;
		}
		cout << " ----------------------" << endl;
	}
	else if (auto_number <= root->auto_number){
		return Search(root->left, auto_number); }
	else{ 
		return Search(root->right, auto_number); }
}


void Show_all(GAI *root){
	if (root == NULL) return;
	else{
		Show_all(root->left);
		cout << " AUTO NUMBER  [ " << root->auto_number << " ]" << endl;
		cout << " OFFENSES : " << endl;
		for (int i = 0; i < 5; i++){
			cout << "  ~ | " << root->offenses[i] << endl;
		}
		cout << " ----------------------" << endl;
	}
	Show_all(root->right);
}

void Add_offenses(GAI *root, string auto_number){
	if (root == NULL) return;
	else {
		if (root->auto_number == auto_number){
			for (int i = 0; i < 5; i++){
				if (root->offenses[i] == "."){
					cout << " Enter offenses : ";
					cin >> root->offenses[i];
					break;
				}				
			}
		}
	}
}

int main()
{
	string auto_num;
	string offenses;
	bool exit = false;
	int choise;
	GAI *root = NULL;	
	

	while (!exit)
	{
		cout << " :::::::::::::::::::::::::::::::::::" << endl;
		cout << " :: ************  G  ************ ::" << endl;
		cout << " :: ************  A  ************ ::" << endl;
		cout << " :: ************  I  ************ ::" << endl;
		cout << " :::::::::::::::::::::::::::::::::::" << endl;


		cout << "\n [1] Add new auto. \n [2] Search auto to number. \n [3] Show all database. \n [4] Add offenses to any car. \n [0] EXIT." << endl;
		cout << " Enter you choise : ";
		cin >> choise;


		switch (choise)
		{
		case 1:
			cout << "\n\n Enter auto number : ";
			cin >> auto_num;
			cout << " Enter offenses    : ";
			cin >> offenses;
			root = Insert(root, auto_num, offenses);
			break;

		case 2:
			cout << "\n\n Enter auto number to search : ";
			cin >> auto_num;
			Search(root, auto_num);
			break;

		case 3:
			cout << "\n\n";
			Show_all(root);
			break;

		case 4:
			cout << "\n\n Enter auto number to add offenses : ";
			cin >> auto_num;
			Add_offenses(root, auto_num);
			break;

		case 0:
			exit = true;
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}	
	return 0;
}
