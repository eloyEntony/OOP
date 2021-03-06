﻿#include <iostream>
#include<fstream>
#include<string>
using namespace std;

//struct Node {
//	int data;
//	struct Node *left;
//	struct Node *right;
//};
/*
struct Node {
	int data;
	struct Node *left;
	struct Node *right;
	int minValue();
	Node* remove(int value, Node *parent);
};

Node *CreateNewNode(int data) {
	Node *newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node *Insert(Node *root, int data) {
	if (root == NULL)			   {		root = CreateNewNode(data);	}
	else if (data <= root->data)   {		root->left = Insert(root->left, data);	}
	else						   {		root->right = Insert(root->right, data);	}

	return root;
}

bool Search(Node* root, int data){
	if (root == NULL)			 {		return false;	}
	else if (root->data == data) {		return true;	}
	else if (data <= root->data) {		return Search(root->left, data);	}
	else						 {		return Search(root->right, data);	}
}


Node* Node::remove(int data, Node *root) {

	if (data < this->data) {
		if (left != NULL)			return left->remove(data, this);
		else						return NULL;
	}

	else if (data > this->data) {
		if (right != NULL)			return right->remove(data, this);
		else						return NULL;
	}

	else {
		if (left != NULL && right != NULL) {
			this->data = right->minValue();
			return right->remove(this->data, this);
		}

		else if (root->left == this) {
			root->left = (left != NULL) ? left : right;
			return this;
		}

		else if (root->right == this) {
			root->right = (left != NULL) ? left : right;
			return this;
		}
	}
}

int Node::minValue() {

	if (left == NULL)
		return data;
	else
		return left->minValue();

}



int main() {
	int number;

	Node *root = NULL;
	root = Insert(root, 50);
	root = Insert(root, 20);
	root = Insert(root, 23);
	root = Insert(root, 60);

	cout << "Enter number for search : " << endl;
	cin >> number;
	if (Search(root, number) == true) {
		cout << "Number: " << number << " Found" << endl;
	}
	else {
		cout << number << " Not found" << endl;
	}

	cout << "Enter number to delete : " << endl;
	cin >> number;

	
	
	system("pause");
	return 0;
}*/

/*
Написать программу, моделирующую работу автобусного парка. 
Сведения о каждом автобусе содержат: номер автобуса, фамилию и имя водителя, номер маршрута, количество мест в автобусе. 
Сформировать информацию об автобусах в виде бинарного дерева. 
Ключом для формирования дерева является номер автобуса. 
Программа должна: 
■ Предоставить интерфейс типа «меню»; 
■ Выполнять поиск по указанному ключу;
■ Выводить информацию о найденном автобусе на экран;
■ Записать информацию об автобусах в упорядоченном виде в файл.
*/

struct Bus
{
	int bus_number;
	string driver;
	int route_number;
	int seat_plase_in_bus;

	struct Bus *left;
	struct Bus *right;
};

Bus *CreateNewBus(int bus_number, string driver, int route_number, int seat_plase_in_bus) 
{
	Bus *newBus = new Bus();
	newBus->bus_number = bus_number;
	newBus->driver = driver;
	newBus->route_number = route_number;
	newBus->seat_plase_in_bus = seat_plase_in_bus;
	newBus->left = newBus->right = NULL;
	return newBus;
}

Bus *Insert(Bus *root, int bus_number, string driver, int route_number, int seat_plase_in_bus) {

	if (root == NULL)						 { 		root = CreateNewBus(bus_number, driver, route_number, seat_plase_in_bus);				}
	else if (bus_number <= root->bus_number) {		root->left = Insert(root->left, bus_number, driver, route_number, seat_plase_in_bus);	}
	else									 { 		root->right = Insert(root->right, bus_number, driver, route_number, seat_plase_in_bus);	}

	return root;
}

bool Search(Bus* root, int number) {
	if (root == NULL) { return false; }
	else if (root->bus_number == number)	{ return true; }
	else if (number <= root->bus_number)	{ return Search(root->left, number); }
	else									{ return Search(root->right, number); }
}

void Show_info(Bus *&root, int num)
{
	
	if (root != NULL)              
	{
		if(num == root->bus_number ) {

			cout << "\n ~~~ Bus number   : " << root->bus_number << endl;
			cout << " ~~~ Driver       : " << root->driver << endl;
			cout << " ~~~ Route number : " << root->route_number << endl;
			cout << " ~~~ Seat plase   : " << root->seat_plase_in_bus << endl;
		}
		else if(num >= root->bus_number )
		Show_info(root->right, num);

		else if(num <= root->bus_number )
		Show_info(root->left, num);  	             
	}
}

void Write_to_file(Bus *root)
{
	string path = "data.txt";
	ofstream writeFile;
	writeFile.open(path, ios::app);

	if (root != NULL) {

		if (!writeFile.is_open())
		{
			cout << " [!] Can't save file!" << endl;
		}
		else {

			writeFile << root->bus_number << endl;
			writeFile << root->driver << endl;
			writeFile << root->route_number << endl;
			writeFile << root->seat_plase_in_bus << endl;
			writeFile << "------------------------" << endl;
		}
		writeFile.close();
		cout << endl;	

		Write_to_file(root->left);
		Write_to_file(root->right);
	}
	
}

int main() {
	int number;
	int choise;
	bool exit = false;

	Bus *root = NULL;
	root = Insert(root, 50, "Bob", 30, 10);
	root = Insert(root, 20, "Bill", 15, 15);

	while (!exit)
	{
		cout << "\n------------------------ Bus Station ------------------------" << endl;
		cout << " [1] Search bus " << endl;
		cout << " [2] Show bus " << endl;
		cout << " [3] Write to file " << endl;
		cout << " [0] Exit" << endl;

		cout << "\n Enter your choise : ";
		cin >> choise;

		switch (choise)
		{
		case 1:
			cout << "\n Enter number for search : ";
			cin >> number;
			if (Search(root, number) == true) {
				cout << "\n ~~~ Number: " << number << " Found" << endl;
			}
			else {
				cout << number << "\n ~~~ Not found" << endl;
			}
			break;
		case 2:
			cout << "\n Enter number to show : ";
			cin >> number;
			Show_info(root, number);
			cout << endl;
			break;
		case 3:
			Write_to_file(root);
			cout << " ~~~ Data save! " << endl;
			break;
		case 0:
			exit = true;
			break;
		default:
			break;
		}
	}


	system("pause");
	return 0;
}