#include<iostream>
#include<string>
#include<ctime>
#include"Fish.h"
using namespace std;

int Fish::live_fish = 0;
char Fish::sea[10][10] = { '. ' };

int main()
{
	srand(unsigned(time(NULL)));

	Fish num1;
	num1.Moving();
	num1.Show_fish_info();

	Fish num2;
	num2.Moving();
	num2.Show_fish_info();

	Fish::Show_sea();

	system("pause");
	return 0;
}