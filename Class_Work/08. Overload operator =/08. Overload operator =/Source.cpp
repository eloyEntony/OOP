#include<iostream>
#include<string>
#include"XString.h"
using namespace std;

int main() {

	
	string s;
	XString row1;
	XString row2;

	row1.Create_row();
	row2.Create_row();

	row1.operator*=(row2);

	row1.operator+=(row2);

	row1.operator/=(row2);

	cout << "\n\n"; 
	system("pause");
	return 0;
}