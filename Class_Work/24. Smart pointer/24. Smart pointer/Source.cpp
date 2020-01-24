#include<iostream>
#include<string>

using namespace std;

/*
Дано рядок(С або С++ на вибір).
Перевірити чи він містить вірно записану IP-адресу.
Використати рядкові потоки.
Наприклад, 255.255.255.0 - вірна, 255.255.0.256, 192.0.157 – невірні.
*/

int main() {

	string ip;
	string cod;
	char buffer[4];
	int j = 0;
	getline(cin, ip);

	for (int i = 0;i < ip.length(); i++) {		


		if (ip[i] == 46) {
			cout << "krapka" << endl;
			buffer[j] = '\0';
			j = 0;
		}
		else {
			buffer[j] = ip[i];
			j++;			
		}
		
		cout << "-------------cod   " << cod << endl;

		if (atoi(cod.c_str()) < 255) {
			cout << "\nGOOD" << endl;
		}
	}


	system ("pause");
	return 0;
}



