/*Створити програму, яка працює подібно стандартній програмі Командний Рядок. Тобто
програма очікує команду і виконує її. Вихід з програми виконувати за командою exit або
quit. Реалізувати наступні команди:
o create filename(створення текстового файлу, завершення вводу – комбінація Ctrl-Z)
o print filename(вивід текстового файлу на екран)
o append filename(доповнення текстового файлу, завершення вводу – комбінація Ctrl-
Z)
o copy filename1 filename2(копіювання файлу)
При введенні невірної команди або вказанні невірного шляху до файлу програма
повинна видавати відповідне повідомлення(«Невірна команда», «Невірна кількість
параметрів», «Невірний шлях до файлу»).*/

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

string create_filename()
{
	string path;
	string text;
	cout << " Enter file name : ";
	cin >> path;
	
	cout << " Enter any text : ";
	cin.ignore();
	getline(cin, text);		

	ofstream myfile;
	myfile.open(path);
	myfile << text;
	myfile.close();

	return path;
}

void print_filename(string path)
{
	string text_in_file;
	ifstream in_file;
	in_file.open(path);
	if (in_file.fail())	{
		cout << "File opening error. " << endl;
	}
	else{
		getline(in_file, text_in_file);
		cout << text_in_file;
	}
	in_file.close();
	cout << "\n\n";
}

void append_filename(string path)
{
	string text;
	cout << " Enter any text : ";
	cin.ignore();
	getline(cin, text);

	ofstream myfile;
	myfile.open(path, fstream::app);
	myfile <<text;
	myfile.close();
}

void copy_filename1_filename2()
{
	cout<<" Enter "
}


int main()
{
	string command;
	string path;
	bool exit = false;

	cout << "Microsoft Windows [Version 10.0.17763.914]\n(c)2018 Microsoft Corporation.All rights reserved.\n\n" << endl;
	
	while (!exit) {

		cout << "C:\\Users\\kozyar > ";
		cin >> command;

		
		if (command == "create") {
			path = create_filename();
			//cout << path << endl;
		}
			
		else if (command == "print") {
			cout << " Enter file name : ";
			cin >> path;
			print_filename(path);
		}
			
		else if (command == "append") {
			cout << " Enter file name : ";
			cin >> path;
			append_filename(path);
		}
			
		else if (command == "copy")
			copy_filename1_filename2();
		else if (command == "exit" || command == "quit")
			exit = true;
		else
			cout << " Wrong commad " << endl;


		cout << "\n";
	}
	


	system("pasue");
	return 0;
}