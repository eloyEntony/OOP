#include<iostream>
#include<vector>
#include<deque>
#include<stack>

using namespace std;

/*int main()
{

	/*deque <int> conteiner = {8,5,4}; // принцип роботи черги

	deque<int>::iterator it;

	for (it = conteiner.begin(); *it != conteiner.back(); it++) {
		cout << *it << endl;
	}
	
	
	stack<int, vector<int>> array; //варіант збереження данних

	array.push(3);
	array.push(5);
	array.push(7);
	
	cout << array.top() << endl;

	auto test = array._Get_container();
	cout << test[2]<<endl;
	

	stack< int, vector<int>> arr;
	arr.push(2);
	arr.push(6);
	arr.push(9);
	arr.push(5);
	auto containerType = arr._Get_container();
	cout << "containerElement => " << containerType[2] << endl;
	cout << "Size => " << arr.size() << endl;
	cout << "Top element => " << arr.top() << endl;
	arr.pop();
	cout << "Top element => " << arr.top() << endl;
	cout << "All elements " << endl;
	while (!arr.empty()) {
		cout << arr.top() << endl;
		arr.pop();
	}


	

	system("pause");
	return 0;
}
*/

//Написати реалізацію класу stack бібліотеки STL на основі елементів типу double.
//Основна програма повинна містити код створення об'єкта, після чого потрібно "програти" методи даного класу. 
//Оцінка залежить від повноти реалізації методів даного класу.


class Stack {

	double dou;
	int size = 0;

	Stack *mystack;

public:

	Stack() {	
		this->dou = 0;
	};

	void Fill(double digit) {
		this->dou = digit;
	}

	Stack & operator = (double num) {
		this->dou = num;
		return *this;
	};

	void Top() {
		cout << mystack[size-1].dou << endl;
	}

	bool Empty() {

	}

	void Size() {
		cout << size;		
	}

	void Push(double digit) {

		Stack *new_mystack = new Stack[size + 1];
		
		for (int i = 0; i < size; i++) {
			new_mystack[i].dou = mystack[i].dou;
		}

		new_mystack[size] = digit;

		delete[] mystack;
		mystack = new_mystack;
		size++;

	}

	void Pop() {

	}

	~Stack() {};
};

int main()
{
	
	Stack mystack;

	mystack.Push(8.3);
	mystack.Push(9.3);
	mystack.Push(10.3);
	mystack.Push(10.3);
	mystack.Push(9.9);

	mystack.Top();

	cout << "---------" << endl;
	mystack.Size();
	cout << "\n---------" << endl;


	system("pause");
	return 0;
}