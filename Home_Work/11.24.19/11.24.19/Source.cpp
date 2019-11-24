#include<iostream>
#include<string>
#include"Int.h"

using namespace std;
void Fill_digits(int &q, int &w, Int &a, Int &b);
int main()
{
	Int a, b, res;
	
	/*Int a(8), b(3), res;
	a.Show_info();
	b.Show_info();

	res=a.Sum(b);
	cout <<" RES > " <<res.Get_value() << endl;
	res = a.Sub(b);
	cout << " RES > " << res.Get_value() << endl;
	res = a.Div(b);
	cout << " RES > " << res.Get_value() << endl;
	res = a.Mul(b);
	cout << "\n RES > " << res.Get_value() << endl;
	*/


	bool exit = false;
	int choise = 0;
	int q = 0;
	int w = 0;
	

	while (!exit) {

		cout << "\n === Hard calculator (using class) ===" << endl;
		cout << " [1] + \n [2] - \n [3] * \n [4] / \n [0] exit" << endl;
		cout << " Enter your choise: ";
		cin >> choise;

		switch (choise)
		{
		case 1: 			
			Fill_digits(q, w, a, b);
			res = a.Sum(b);
			cout << "\n RES > " << res.Get_value() << endl;
			break;
		case 2:
			Fill_digits(q, w, a, b);
			res = a.Sub(b);
			cout << "\n RES > " << res.Get_value() << endl;
			break;
		case 3:
			Fill_digits(q, w, a, b);
			res = a.Mul(b);
			cout << "\n RES > " << res.Get_value() << endl;
			break;
		case 4:
			Fill_digits(q, w, a, b);
			res = a.Div(b);
			cout << "\n RES > " << res.Get_value() << endl;
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

void Fill_digits(int &q, int &w, Int &a, Int &b) {

	cout << " Enter 1 digit: ";
	cin >> q;
	a.Set_int(q);
	cout << " Enter 2 digit: ";
	cin >> w;
	b.Set_int(w);
}