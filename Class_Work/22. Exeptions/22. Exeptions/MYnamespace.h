#pragma once

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

namespace MySpace {

	class Documante {
		string name;
		string surname;
		string birthday;
		string serial_number;
	public:

		Documante() {};
		
		void Fill() {				
			cout << " --> Enter your name      : ";	
			//cin.ignore();
			getline(cin, name);
			cout << " --> Enter your surnaem   : ";
			getline(cin, surname);
			cout << " --> Enter your birthday  : ";
			getline(cin, birthday);
			cout << " --> Create serial number : ";
			getline(cin, serial_number);
		}

		void Show_info() {
			cout << "\n__________________________________" << endl;
			cout << " Name          : " << this->name << endl;
			cout << " Surname       : " << this->surname << endl;
			cout << " Birthday      : " << this->birthday << endl;
			cout << " Serial number : " << this->serial_number << endl;
		}

		void Set_name(string name) { this->name = name; }
		void Set_surname(string surmane) { this->surname = surmane; }
		void Set_birthday(string birthday) { this->birthday = birthday; }
		void Set_serial_number(string serial_number) { this->serial_number = serial_number; }


		void Write_to_file() {
			
			string path = "file.txt";

			ofstream writeFile;
			writeFile.open(path);
				writeFile << this->name;
				writeFile << this->surname;
				writeFile << this->birthday;
				writeFile << this->serial_number;



			path = "file.txt";
			ifstream myFile;
			myFile.exceptions(ifstream::badbit | ifstream::failbit);  // Only for ifstream (Demo)
			
			try{		
				myFile.open(path);				
				cout << "\n ->>> Successfuly open and close file \n" << endl;
				myFile.close();				
			}
			catch (const std::exception& error){
				cout << error.what() << endl;
				cout << "\n ->>> Error open file.\n" << endl;
			}
		}
		~Documante() {};
	};

}



