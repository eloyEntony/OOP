#include<iostream>
#include<string>

using namespace std;

/*
Дано рядок(С або С++ на вибір).
Перевірити чи він містить вірно записану IP-адресу.
Використати рядкові потоки.
Наприклад, 255.255.255.0 - вірна, 255.255.0.256, 192.0.157 – невірні.
*/

class IP {

	char arr[4];
public:
	void Fill() {
		
		for (int i = 0; i < 4; i++) {
			cin >> arr[i];

			if (arr[i] == 46) {
				this->arr[4] = arr[i];
				continue;
			}
		}
	}

	void Check() {

		if (arr[0] != 46 && arr[4] == 46) {
			cout << "GOOD" << endl;
		}

		
	}

};

int main() {

	IP *ip = new IP[4];

	for (int i = 0; i < 4; i++){
		ip[i].Fill();
	}

	for (int i = 0; i < 4; i++) {
		ip[i].Check();
	}

	system("pause");
	return 0;
}


