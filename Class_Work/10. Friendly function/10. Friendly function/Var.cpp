#include "Var.h"



Var::Var()
{
}

Var::Var(int digit){
	type = t_int;
	integ = digit;
}

Var::Var(double big_digit){
	type = t_double;
	doub = big_digit;
}

Var::Var(string stroka){
	type = t_string;
	str.Set_string(stroka);	
}

void Var::Show_info()
{
	if (type == t_int)
		cout << "\n Type: " << type << " [Int] => " << integ;
	else if (type == t_double)
		cout << "\n Type: " << type << " [Double] => " << doub;
	else if (type == t_string)	{
		cout << "\n Type: " << type ;	
		str.Show_string();	
	}
		
}

Var Var::operator+(Var &other)
{
	if (this->type == t_int && other.type == t_int)	{
		int sum = this->integ + other.integ;		
		cout << " Sum [int + int] : " << sum;
	}
	else if (this->type == t_int && other.type == t_double)	{
		int sum = this->integ + other.doub;
		cout << " Sum [int + double] : " << sum;
	}
	else if (this->type == t_int && other.type == t_string)	{
		//string s = "Hello";
		//int sum = 0;
		//for (int i = 0; i < s.length(); i++)		{
		//	//sum += int(s[i]);
		//	sum = i + 1;
		//}
		//cout << sum;

		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		int sum = this->integ + int_string;
		cout << " Sum [int + string] : " << sum;
		
	}

	//////////////////////////////////////////////////////////////////

	else if (this->type == t_double && other.type==t_double)	{
		double sum = this->doub + other.doub;
		cout << " Sum [double + double] : " << sum;
	}
	else if (this->type == t_double && other.type == t_int)	{
		double sum = this->doub + other.integ;
		cout << " Sum [double + int] : " << sum;
	}
	else if (this->type == t_double && other.type == t_string)	{
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		double sum = this->doub + int_string;
		cout << " Sum [double + string] : " << sum;
	}

	//////////////////////////////////////////////////////////////////
	else if (this->type == t_string && other.type == t_string)	{
		string sum = this->str.Get_string() + other.str.Get_string();
		cout << " Sum [string + string] : " << sum;
	}
	else if (this->type == t_string && other.type ==t_double)	{
		string doub_str = other.convert_from_double_to_string(other.doub);
		string sum = this->str.Get_string() + doub_str;
		cout << " Sum [string + double] : " << sum;
	}	
	else if (this->type == t_string && other.type==t_int)	{
		string int_str = other.convert_from_int_to_string(other.integ);	
		string sum = this->str.Get_string() + int_str;
		cout << " Sum [string + int] : " << sum;
	}

	return 0;
}

Var Var::operator-(Var & other)
{
	if (this->type == t_int && other.type == t_int) {
		int subtraction = this->integ - other.integ;
		cout << " Subtraction [int - int] : " << subtraction;
	}

	else if (this->type == t_int && other.type == t_double) {
		int subtraction = this->integ - other.doub;
		cout << " Subtraction [int - double] : " << subtraction;
	}
	else if (this->type == t_int && other.type == t_string)	{
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		int subtraction = this->integ - int_string;
		cout << " Subtraction [int - string] : " << subtraction;
	}

	//////////////////////////////////////////////////////////////////

	else if (this->type == t_double && other.type == t_double) {
		double subtraction = this->doub - other.doub;
		cout << " Subtraction [double - double] : " << subtraction;
	}
	else if (this->type == t_double && other.type == t_int) {
		double subtraction = this->doub - other.integ;
		cout << " Subtraction [double - int] : " << subtraction;
	}
	else if (this->type == t_double && other.type == t_string)	{
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		double subtraction = this->doub - int_string;
		cout << " Subtraction [double - string] : " << subtraction;
	}

	//////////////////////////////////////////////////////////////////
	else if (this->type == t_string && other.type == t_string)  {	cout << " You can't subtract from sting " << endl;	}
	else if (this->type == t_string && other.type == t_double)  {	cout << " You can't subtract from sting " << endl;	}
	else if (this->type == t_string && other.type == t_int)		{	cout << " You can't subtract from sting " << endl;	}

	return 0;
}

Var Var::operator*(Var & other)
{
	if (this->type == t_int && other.type == t_int) {
		int multiplication = this->integ * other.integ;
		cout << " Multiplication [int * int] : " << multiplication;
	}
	else if (this->type == t_int && other.type == t_double) {
		int multiplication = this->integ * other.doub;
		cout << " Multiplication [int * double] : " << multiplication;
	}
	else if (this->type == t_int && other.type == t_string) {	
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		int multiplication = this->integ * int_string;
		cout << " Multiplication [int * string] : " << multiplication;
	}

	//////////////////////////////////////////////////////////////////

	else if (this->type == t_double && other.type == t_double) {
		double multiplication = this->doub * other.doub;
		cout << " Multiplication [double * double] : " << multiplication;
	}
	else if (this->type == t_double && other.type == t_int) {
		double multiplication = this->doub * other.integ;
		cout << " Multiplication [double * int] : " << multiplication;
	}
	else if (this->type == t_double && other.type == t_string) {
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		double multiplication = this->doub * int_string;
		cout << " Multiplication [double * string] : " << multiplication;
	}

	//////////////////////////////////////////////////////////////////
	else if (this->type == t_string && other.type == t_string)  { cout << " Cannot be multiplied string " << endl;	}
	else if (this->type == t_string && other.type == t_double)  { cout << " Cannot be multiplied string " << endl;	}
	else if (this->type == t_string && other.type == t_int)		{ cout << " Cannot be multiplied string " << endl;	}

	return 0;
}


int Var::convert_from_string_to_int(string strin){
	//string S = "74";	
	int num_str = atoi(strin.c_str());
	//cout << num_str;
	return num_str;
}

string Var::convert_from_int_to_string(int num){
	string strNumber = to_string(num);
	//cout << strNumber;
	return strNumber;
}

string Var::convert_from_double_to_string(double num){
	string strNumber = to_string(num);
	//cout << strNumber;
	return strNumber;
}

int  Var::convert_from_double_to_int(double num){
	//double pi = 3.14;
	int i = static_cast<int>(num);
	cout << i << endl;
	return i;
}


Var::~Var()
{
}
