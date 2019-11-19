#include "Card.h"
using namespace std;


Card::Card()
{

}

void Card::Show_info() {
	cout << "-----------------------------------------------------" << endl;
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
	if (All_prise > 1000 && All_prise<10000)
	{
		Discont++;
	}
}

