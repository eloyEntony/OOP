#include <iostream>

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


int main() {
	int number;

	Bus *root = NULL;
	root = Insert(root, 50, "Bob", 30, 10);
	root = Insert(root, 20, "Bill", 15, 15);
	

	cout << "Enter number for search : " << endl;
	cin >> number;
	if (Search(root, number) == true) {
		cout << "Number: " << number << " Found" << endl;
	}
	else {
		cout << number << " Not found" << endl;
	}



	system("pause");
	return 0;
}