#include<iostream>
#include<string>

using namespace std;
template<typename T>
class Node_list {

	template<typename T>
	class Conteiner
	{
	public:

		Conteiner * next_conteiner;
		T data;

		Conteiner(T data = T(), Conteiner *next_conteiner = nullptr) {
			this->data = data;
			this->next_conteiner = next_conteiner;
		}
	};

	Conteiner<T> *head;
	int size;


public:

	Node_list() {
		this->head = nullptr;
		this->size = 0;
	}


	int Get_size() {
		return this->size;	
	}

	void Push(T data)
	{
		if (this->head == nullptr)
		{
			this->head = new Conteiner<T>(data);
			
		}
		else
		{
			Conteiner<T> *current = this->head;
			while (current->next_conteiner != nullptr)
			{
				current = current->next_conteiner;
			}
			current->next_conteiner = new Conteiner<T>(data);			
		}

		this->size++;
	}

	T& operator[](int i) {

		int count = 0;
		Conteiner<T> *current = this->head;
		
		while (current != nullptr) {

			if (count == i) {
				return current->data;
			}
			current = current->next_conteiner;
			count++;
		}
	}
		

};


int main()
{
	Node_list<int>list;

	cout << "List size : "<<list.Get_size() << endl;

	list.Push(5);
	list.Push(3);
	list.Push(2);
	list.Push(1);
	list.Push(1);

	cout << list[1] << endl;

	cout << "List size : " << list.Get_size() << endl;

	system("pause");
	return 0;
}