#include<iostream>
#include<string>
#include"XString.h"
using namespace std;

/*
Create an XString class that describes the string. The class must contain the following constructors:

a default constructor that allows you to create a string of 80 characters;
a constructor that creates a string and initializes it with a string passed as a parameter;
copy designer.

In addition, this class must contain a set of overloaded operations to work with strings:

operation *: must return a new line formed by crossing two lines, that is, their common characters.

For example, the intersection of the "Microsoft" and "Windows" rows will result in the "ioso" row.

operation /: must return a new line formed by selecting the first line characters that are not in the second line.
For example, dividing Microsoft from Windows would be Mcrft.

a + operation that allows you to add two rows (line concatenation).
For example, adding two rows "Microsoft" and "Windows" will result in the row "MicrosoftWindows".

operations * =, / = and + =, which operate according to the above principle.
*/


int main() {

	
	string s;
	XString row1;
	XString row2;

	row1.Create_row();
	row2.Create_row();

	row1.operator*=(row2);	

	row1.operator/=(row2);

	row1.operator+=(row2);

	cout << "\n\n"; 
	system("pause");
	return 0;
}