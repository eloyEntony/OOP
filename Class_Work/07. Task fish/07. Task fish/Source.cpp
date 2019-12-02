#include<iostream>
#include<string>
#include<ctime>
#include"Fish.h"
#include <windows.h>
using namespace std;

int Fish::live_fish = 0;
char Fish::sea[10][10];
char Fish::more = '.';
char Fish::vodorosl = '#';
char Fish::vodorosl_x[5];
char Fish::vodorosl_y[5];
int Fish::xV = 0;
int Fish::yV = 0;

int main()
{
	srand(unsigned(time(NULL)));

	Fish A('A');
	A.Create();
	A.Show_fish_info();

	Fish B('B');
	B.Create();
	B.Show_fish_info();

	Fish C('C');
	C.Create();
	C.Show_fish_info();		

	
		Fish::Live();
		Fish::Vodorosli();

		for (int i = 0; i < 101; i++) {
			system("cls");
			
			Fish::Sea();
			A.Moving();
			B.Moving();
			C.Moving();
			Fish::Show_sea();			

			A.Show_fish_info();
			B.Show_fish_info();
			C.Show_fish_info();
			cout << "\n\n";

			Fish::Live();			
			Sleep(1000);			
		}
		

	system("pause");
	return 0;
}