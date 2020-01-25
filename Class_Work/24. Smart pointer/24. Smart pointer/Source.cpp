#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*
Дано рядок(С або С++ на вибір).
Перевірити чи він містить вірно записану IP-адресу.
Використати рядкові потоки.
Наприклад, 255.255.255.0 - вірна, 255.255.0.256, 192.0.157 – невірні.
*/

void Check(char code[], int &cod_count, int &element_count, int &good_reaction) {
	
	if (code[0] == 48 && strlen(code) > 1){   throw exception("\n\n\t\t\t\t- - - - - !!! Erorr !!! - - - - -\n\t\t\t\t- - - - -     [ 0 ]     - - - - -\n\n"); }
	if (element_count > 3)					{	throw exception("\n\n\t\t\t\t- - - - - !!! Erorr !!! - - - - -\n\t\t\t - - - - - [ So big code element (3+) ] - - - - -\n\n");	}
	if (atoi(code) < 0 || atoi(code) > 255)	{	throw exception("\n\n\t\t\t\t- - - - - !!! Erorr !!! - - - - -\n\t\t\t   - - - - - [ So big code (255+) ] - - - - -\n\n"); }	
	for (int i = 0; i < element_count; i++) {
		if (code[i] <= 45 || code[i] >= 58) {	throw exception("\n\n\t\t\t\t- - - - - !!! Erorr !!! - - - - -\n\t\t\t      - - - - - [ IP has leters ] - - - - -\n\n"); }
	}	
	cod_count++;
	good_reaction++;		
}

int main() {
	bool exit = false;

	while (!exit) {
		char element[16] = {};
		char cod[4] = {};
		int element_count = 0;
		int cod_count = 0;
		int j = 0;
		int good_reaction = 0;
		////////////////////////////////////////////////////
		system("color 07");
		cout << "\n\n\t\t\t\t   E N T E R   I P :   ";
		cin >> element;
		cout << "\n\t\t\t\t----------------------------------\n\t\t\t\t\t    ";
		for (int i = 0; i < strlen(element); i++) {	cout << element[i];	}
		cout << "\n\t\t\t\t----------------------------------" << endl;

		for (int i = 0; i < strlen(element) + 1; i++) {
			if (element[0] == 48) {
				cout<<"\n\n\t\t\t\t - - - - - !!! Erorr !!! - - - - -\n\t\t\t\t - - - - - [  First 0  ] - - - - -\n\n"<<endl;
				system("color 04");
				break;
			}
			if (element[i] == 46 || (cod_count == 3 && i == strlen(element))) {						
				try { Check(cod, cod_count, element_count, good_reaction); } // перевірка масива 
				catch (const exception & error) {
					cout << error.what() << endl;
					system("color 04");
					break;
				}
				for (int i = 0; i < 4; i++) { cod[i] = '\0'; }	//обнуляємо масив
				j = 0;
				element_count = 0;
			}
			else {
				element_count++;
				cod[j] = element[i]; // створення масиву
				j++;
			}
		}
		if (good_reaction == 4) {
			system("color 02");
			cout << "\n\n\t\t\t  - - - - - G O O D   I P   A D R E S S - - - - -\n\n" << endl;
		}
		cout << " \n\n\t\t\t ENTER  ->[1]  TO   EXIT ||  ->[0]  TO   CONTINUE  :   ";
		cin >> exit;
	}	
	//system("pause");
	return 0;
}


