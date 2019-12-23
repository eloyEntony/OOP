#include<iostream>
#include<string>
#include<ctime>

using namespace std;

/*
		�������� �������� � ������ ������� - �������, �������, ����.

		����� ���� �������������� (��������� ��������� � ��� ������� �������� ����������
			� ����������� �����) � �쳺 ����������� � ������� � ����� � ��������� 70%.
		����� ���� � ������� �� ��������� �����.

		������� ����������� � ������ �����, ������ 30 ����� � �쳺:
			o ��������� ���� (������ ���� '�������')
			o �������� ���� (������)

		������� �쳺:
			o �������� �������(����� ����� �������� �������� � �������)
			o ������� - ��������� ������� ���� 1 ����, �, ���� ���, ��������� ���� ����������
			(���� ��� ����� �����, �� ������, � ������� ��������� ��������� '������' )

		��� ������ � ������� �� ���������� ����������� ������ ����:
		������� ��������� ���� 5, � �����������.
		������� ��������� ���� 6, � ������.
*/


class Machine
{
	template<typename T>
	class Shop
	{
		template<typename T>
		class Stuff
		{
		public:
			Stuff * next_stuff;
			T num;

			Stuff(T num = T(), Stuff *next_stuff = nullptr) {
				this->num = num;
				this->next_stuff = next_stuff;
			}
		};
		Stuff<T> *head;
		int size;

	public:

		Shop() {
			this->head = nullptr;
			this->size = 0;
		}

		int Get_size() { return this->size;	}

		void Push(){
			if (this->head == nullptr){		this->head = new Stuff<T>(rand()% 10+1);	}
			else
			{
				Stuff<T> *current = this->head;
				while (current->next_stuff != nullptr)
				{
					current = current->next_stuff;
				}
				current->next_stuff = new Stuff<T>(current->num + 1);
			}
			this->size++;
		}

		T& operator[](int i){
			int count = 0;
			Stuff<T> *current = this->head;

			while (current != nullptr) {
				if (count == i) {	return current->num;	}
				current = current->next_stuff;
				count++;
			}
		}

		void DeleteFirst() {
			Stuff<T> *temp = this->head;
			this->head = this->head->next_stuff;
			delete temp;
			size--;
		}
	};


	Shop<int> shop;

public:

	void Fire()
	{
		if (shop.Get_size() > 0)
		{
			shop.DeleteFirst();
			int hit = rand() % 10 + 1;

			if (hit > 0 && hit < 7)
				cout << " Cool !!!    STAFF # " << shop[0] << " hit ." << endl;
			else
				cout << " Bad !!!     STAFF # " << shop[0] << " missed . " << endl;
		}
		else
		{
			bool choise;
			cout << " You mast reload machine . [1/0]" << endl;
			cin >> choise;
			if(choise==true)	Reload();
			else cout << " You machine pusta . " << endl;
		}

		cout << " Shop size = " << shop.Get_size() << "\n\n";
	}


	void Reload(){	for (int i = shop.Get_size(); i < 30; i++)	{	shop.Push();  }		}

};






int main()
{
	srand(unsigned(time(NULL)));

	Machine m;

	m.Reload();
	m.Fire();
	m.Fire();
	m.Fire();
	m.Fire();
	m.Fire();
	m.Fire();

	system("pause");
	return 0;
}