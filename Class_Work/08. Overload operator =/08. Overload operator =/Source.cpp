#include<iostream>
#include<string>
#include"XString.h"
using namespace std;

int main() {

	char str[80];

	cout << " Enter you str: ";
	cin >> str;

	XString row1(str);
	XString row2;

	row1.Show_string();

	row2.Show_string();

	system("pause");
	return 0;
}