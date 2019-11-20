#include "Card.h"

using namespace std;


Card::Card()
{

}

void Card::Show_info() {
	cout << "\n\n-----------------------------------------------------" << endl;
	cout << " Num card : " << Num_card << endl;
	cout << " Discaunt : " << Discont << " % " << endl;
	cout << " All money buy : " << All_prise << " $ " << endl;
	cout << "-----------------------------------------------------" << endl;
}

double Card::Get_All_prise()
{
	return All_prise;
}

void Card::Set_All_prise(double buy)
{
	All_prise += buy;
}

void Card::Plus_Discont()
{
	int dickaunt = (All_prise / 1000)+1;	

	if (dickaunt <= 10){
		Discont = dickaunt;
	}

	else if (dickaunt >10){
		Discont = 10;
		cout << "\n You have max discont ===> "<<Discont<<" % " << endl;
	}
}

Card::~Card()
{
}
