#include<iostream>
#include<string>
#include "Card.h"

using namespace std;

/*Wrote the class "Discount card", which is contained in the following work :

Card number
Large amount reduction(decreases due to accumulation; initially it is equal to 1 % .For every 1000 UAH.Purchases, the amount of reduction is 1 % .)
Purchase an additional box to preserve the reliability of the purchased item
Provide access to :
Buy potato products at a discount
Display information about the current big discount
You will find that you need to document the product even more so that a large number of discounts can be increased.

Написати клас "Карточка на знижку", який містить наступну інформацію: 

Номер карточки 
Розмір знижки (знижка передбачається накопичуваною; на початковому етапі вона рівна 1%. За кожні 1000 грн. покупки, сума знижки збільшується на 1%.) 
Приховане допоміжне поле для збереження вартості накупленого товару 
Забезпечити можливість: 
Купляти товар з використанням карточки на знижку 
Виводити інформацію про поточну величину знижки 
Виводити інформацію про те, на яку суму ще необхідно докупити товару, щоб величина знижки збільшилась. 

*/

int main()
{
	bool exit = false;
	int choise = 0;
	int buy = 0;

	Card mycard;


	while (!exit) {
		

		cout << "\n 1. Laptop [ 500 $ ]\n 2. Phone [ 300 $ ]\n 3. TV [ 800 $ ]\n 4. Washing machine [ 1100 $ ]\n 5. Refrigerator [ 900 $ ]\n 6. Enter my by [ ... $ ] \n 7. Show info \n 0. Exit" << endl;
		cout << " Enter your choise: ";
		cin >> choise;

		buy = 0;
		buy = mycard.Get_All_prise();

		switch (choise)
		{
		case 1:
			cout << "\n\n Buy Laptop " << endl;
			buy = 500;
			mycard.Plus_Discont();
			mycard.Set_All_prise(buy);
			break;
		case 2:
			cout << "\n\n Buy Phone " << endl;
			buy = 300;
			mycard.Plus_Discont();
			mycard.Set_All_prise(buy);
			break;
		case 3:
			cout << "\n\n Buy TV " << endl;
			buy = 800;
			mycard.Plus_Discont();			
			mycard.Set_All_prise(buy);
			break;
		case 4:
			cout << "\n\n Buy Washing machine  " << endl;
			buy = 1100;
			mycard.Plus_Discont();
			mycard.Set_All_prise(buy);
			break;
		case 5:
			cout << "\n\n Buy Refrigerator " << endl;
			buy = 900;
			mycard.Plus_Discont();
			mycard.Set_All_prise(buy);
			break;
		case 6:
			cout << "\n\n Enter youe by: ";
			cin >> buy;
			mycard.Plus_Discont();
			mycard.Set_All_prise(buy);
			break;
		case 7:
			mycard.Plus_Discont();
			mycard.Show_info();
			break;
		case 0:
			cout << " Exit" << endl;
			exit = true;
			break;
		default:
			break;
		}
		
		
		system("pause");
		system("cls");
	}


	system("pause");
	return 0;
}
