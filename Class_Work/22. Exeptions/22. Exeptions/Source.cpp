﻿//#include<iostream>
//#include<string>
//using namespace std;
#include"MYnamespace.h"
#include"Passport.h"

/* 
Створити програму, яка демонструє, що функція зі своїм власним try–блоком
не зобов’язана перехоплювати всі можливі виключення, викинуті у блоці try. 
Деякі виключення можуть бути випущені у зовнішні області дії і оброблятися у них.
*/

/*
void Division(int a, int b){
	if (b == 0) {	throw exception(" Fatal error. Division on 0. ");	}
	cout << " Division : " << a / b << endl;
}
int main() {
	int a, b;
	cout << " Enter A and B : ";
	cin >> a>>b;
	try {	Division(a, b);	}
	catch (const exception &error) {	cout << error.what() << endl;	}
	system("pause");
	return 0;
}
*/

/*
Реалізувати задачу Паспорт, Іноземний Паспорт як багато файловий проект.
При цьому кожен з класів розмістити у окремому просторі імен.
Перевірити роботу класів.
*/

int main(){

	/*MySpace::Documante mypasport;
	mypasport.Fill();
	mypasport.Show_info();*/

	passportSpace::Passport myPassport;

	cout << "\n\t C R E A T E   P A S S P O R T\n\n" << endl;
	myPassport.Fill();

	cout << "\n------------- I N F O ------------" << endl;
	myPassport.Show_info();
	myPassport.Write_to_file();

	system("pause");
	return 0;
}