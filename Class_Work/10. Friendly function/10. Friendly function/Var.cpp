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

void Var::operator+(Var &other)
{
	int sumI;
	double sumD;
	string sumS;

	if (this->type == t_int && other.type == t_int)	{
		sumI = this->integ + other.integ;
		cout << " Sum [int + int] : " << sumI;
	}
	else if (this->type == t_int && other.type == t_double)	{
		sumI = this->integ + other.doub;
		cout << " Sum [int + double] : " << sumI;
	}
	else if (this->type == t_int && other.type == t_string)	{		
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		sumI = this->integ + int_string;
		cout << " Sum [int + string] : " << sumI;
		
	}

	//////////////////////////////////////////////////////////////////

	else if (this->type == t_double && other.type==t_double)	{
		sumD = this->doub + other.doub;
		cout << " Sum [double + double] : " << sumD;
	}
	else if (this->type == t_double && other.type == t_int)	{
		sumD = this->doub + other.integ;
		cout << " Sum [double + int] : " << sumD;
	}
	else if (this->type == t_double && other.type == t_string)	{
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		sumD = this->doub + int_string;
		cout << " Sum [double + string] : " << sumD;
	}

	//////////////////////////////////////////////////////////////////
	else if (this->type == t_string && other.type == t_string)	{
		sumS = this->str.Get_string() + other.str.Get_string();
		cout << " Sum [string + string] : " << sumS;
	}
	else if (this->type == t_string && other.type ==t_double)	{
		string doub_str = other.convert_from_double_to_string(other.doub);
		sumS = this->str.Get_string() + doub_str;
		cout << " Sum [string + double] : " << sumS;
	}	
	else if (this->type == t_string && other.type==t_int)	{
		string int_str = other.convert_from_int_to_string(other.integ);	
		sumS = this->str.Get_string() + int_str;
		cout << " Sum [string + int] : " << sumS;
	}

	
}

void Var::operator-(Var & other)
{
	int subtraction_I;
	double subtraction_D;

	if (this->type == t_int && other.type == t_int) {
		subtraction_I = this->integ - other.integ;
		cout << " Subtraction [int - int] : " << subtraction_I;
	}

	else if (this->type == t_int && other.type == t_double) {
		subtraction_I = this->integ - other.doub;
		cout << " Subtraction [int - double] : " << subtraction_I;
	}
	else if (this->type == t_int && other.type == t_string)	{
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		subtraction_I = this->integ - int_string;
		cout << " Subtraction [int - string] : " << subtraction_I;
	}

	//////////////////////////////////////////////////////////////////

	else if (this->type == t_double && other.type == t_double) {
		subtraction_D = this->doub - other.doub;
		cout << " Subtraction [double - double] : " << subtraction_D;
	}
	else if (this->type == t_double && other.type == t_int) {
		subtraction_D = this->doub - other.integ;
		cout << " Subtraction [double - int] : " << subtraction_D;
	}
	else if (this->type == t_double && other.type == t_string)	{
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		subtraction_D = this->doub - int_string;
		cout << " Subtraction [double - string] : " << subtraction_D;
	}

	//////////////////////////////////////////////////////////////////
	else if (this->type == t_string && other.type == t_string)  {	cout << " You can't subtract from sting " << endl;	}
	else if (this->type == t_string && other.type == t_double)  {	cout << " You can't subtract from sting " << endl;	}
	else if (this->type == t_string && other.type == t_int)		{	cout << " You can't subtract from sting " << endl;	}

	
}

void Var::operator*(Var & other)
{
	int multiplication_I;
	double multiplication_D;

	if (this->type == t_int && other.type == t_int) {
		multiplication_I = this->integ * other.integ;
		cout << " Multiplication [int * int] : " << multiplication_I;
	}
	else if (this->type == t_int && other.type == t_double) {
		multiplication_I = this->integ * other.doub;
		cout << " Multiplication [int * double] : " << multiplication_I;
	}
	else if (this->type == t_int && other.type == t_string) {	
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		multiplication_I = this->integ * int_string;
		cout << " Multiplication [int * string] : " << multiplication_I;
	}

	//////////////////////////////////////////////////////////////////

	else if (this->type == t_double && other.type == t_double) {
		multiplication_D = this->doub * other.doub;
		cout << " Multiplication [double * double] : " << multiplication_D;
	}
	else if (this->type == t_double && other.type == t_int) {
		multiplication_D = this->doub * other.integ;
		cout << " Multiplication [double * int] : " << multiplication_D;
	}
	else if (this->type == t_double && other.type == t_string) {
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		multiplication_D = this->doub * int_string;
		cout << " Multiplication [double * string] : " << multiplication_D;
	}

	//////////////////////////////////////////////////////////////////
	else if (this->type == t_string && other.type == t_string)  { cout << " Cannot be multiplied string " << endl;	}
	else if (this->type == t_string && other.type == t_double)  { cout << " Cannot be multiplied string " << endl;	}
	else if (this->type == t_string && other.type == t_int)		{ cout << " Cannot be multiplied string " << endl;	}

	
}

void Var::operator/(Var & other)
{
	int division_I;
	double division_D;

	if (this->type == t_int && other.type == t_int) {
		division_I = this->integ * other.integ;
		cout << " Division [int / int] : " << division_I;
	}
	else if (this->type == t_int && other.type == t_double) {
		division_I = this->integ * other.doub;
		cout << " Division [int / double] : " << division_I;
	}
	else if (this->type == t_int && other.type == t_string) {
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		division_I = this->integ * int_string;
		cout << " Division [int / string] : " << division_I;
	}

	//////////////////////////////////////////////////////////////////

	else if (this->type == t_double && other.type == t_double) {
		division_D = this->doub * other.doub;
		cout << " Division [double / double] : " << division_D;
	}
	else if (this->type == t_double && other.type == t_int) {
		division_D = this->doub * other.integ;
		cout << " Division [double / int] : " << division_D;
	}
	else if (this->type == t_double && other.type == t_string) {
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		division_D = this->doub * int_string;
		cout << " Division [double / string] : " << division_D;
	}

	//////////////////////////////////////////////////////////////////
	else if (this->type == t_string && other.type == t_string) { cout << " Cannot be division string " << endl; }
	else if (this->type == t_string && other.type == t_double) { cout << " Cannot be division string " << endl; }
	else if (this->type == t_string && other.type == t_int) { cout << " Cannot be division string " << endl; }

	
}

void Var::operator+=(Var & other)
{

	if (this->type == t_int && other.type == t_int) {
		this->integ += other.integ;
		cout << " Result [int += int] : " << this->integ;
	}
	else if (this->type == t_int && other.type == t_double) {
		this->integ += other.doub;
		cout << " Result [int += double] : " << this->integ;
	}
	else if (this->type == t_int && other.type == t_string) {
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		this->integ += int_string;
		cout << " Result [int += string] : " << this->integ;
	}

	//////////////////////////////////////////////////////////////////

	else if (this->type == t_double && other.type == t_double) {
		this->doub += other.doub;
		cout << " Result [double += double] : " << this->doub;
	}
	else if (this->type == t_double && other.type == t_int) {
		this->doub += other.integ;
		cout << " Result [double += int] : " << this->doub;
	}
	else if (this->type == t_double && other.type == t_string) {
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		this->doub += int_string;
		cout << " Result [double += string] : " << this->doub;
	}

	//////////////////////////////////////////////////////////////////
	/*else if (this->type == t_string && other.type == t_string) {
		this->str.Get_string() += other.str.Get_string();
		cout << " Result [string += string] : " << str.Get_string();
	}
	else if (this->type == t_string && other.type == t_double) {
		string doub_str = other.convert_from_double_to_string(other.doub);
		this->str.Get_string() += doub_str;
		cout << " Result [string += double] : " << this->str.Get_string();
	}
	else if (this->type == t_string && other.type == t_int) {
		string int_str = other.convert_from_int_to_string(other.integ);
		this->str.Get_string() += int_str;
		cout << " Result [string += int] : " << this->str.Get_string();
	}*/
}

void Var::operator-=(Var & other)
{
	if (this->type == t_int && other.type == t_int) {
		this->integ -= other.integ;
		cout << " Result [int -= int] : " << this->integ;
	}
	else if (this->type == t_int && other.type == t_double) {
		this->integ -= other.doub;
		cout << " Result [int -= double] : " << this->integ;
	}
	else if (this->type == t_int && other.type == t_string) {
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		this->integ -= int_string;
		cout << " Result [int -= string] : " << this->integ;
	}

	//////////////////////////////////////////////////////////////////

	else if (this->type == t_double && other.type == t_double) {
		this->doub -= other.doub;
		cout << " Result [double -= double] : " << this->doub;
	}
	else if (this->type == t_double && other.type == t_int) {
		this->doub -= other.integ;
		cout << " Result [double -= int] : " << this->doub;
	}
	else if (this->type == t_double && other.type == t_string) {
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		this->doub -= int_string;
		cout << " Result [double -= string] : " << this->doub;
	}
}

void Var::operator*=(Var & other)
{
	if (this->type == t_int && other.type == t_int) {
		this->integ *= other.integ;
		cout << " Result [int *= int] : " << this->integ;
	}
	else if (this->type == t_int && other.type == t_double) {
		this->integ *= other.doub;
		cout << " Result [int *= double] : " << this->integ;
	}
	else if (this->type == t_int && other.type == t_string) {
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		this->integ *= int_string;
		cout << " Result [int *= string] : " << this->integ;
	}

	//////////////////////////////////////////////////////////////////

	else if (this->type == t_double && other.type == t_double) {
		this->doub *= other.doub;
		cout << " Result [double *= double] : " << this->doub;
	}
	else if (this->type == t_double && other.type == t_int) {
		this->doub *= other.integ;
		cout << " Result [double *= int] : " << this->doub;
	}
	else if (this->type == t_double && other.type == t_string) {
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		this->doub *= int_string;
		cout << " Result [double *= string] : " << this->doub;
	}
}

void Var::operator/=(Var & other)
{
	if (this->type == t_int && other.type == t_int) {
		this->integ /= other.integ;
		cout << " Result [int /= int] : " << this->integ;
	}
	else if (this->type == t_int && other.type == t_double) {
		this->integ /= other.doub;
		cout << " Result [int /= double] : " << this->integ;
	}
	else if (this->type == t_int && other.type == t_string) {
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		this->integ /= int_string;
		cout << " Result [int /= string] : " << this->integ;
	}

	//////////////////////////////////////////////////////////////////

	else if (this->type == t_double && other.type == t_double) {
		this->doub /= other.doub;
		cout << " Result [double /= double] : " << this->doub;
	}
	else if (this->type == t_double && other.type == t_int) {
		this->doub /= other.integ;
		cout << " Result [double /= int] : " << this->doub;
	}
	else if (this->type == t_double && other.type == t_string) {
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		this->doub /= int_string;
		cout << " Result [double /= string] : " << this->doub;
	}
}

bool Var::operator>(Var & other)
{
	if (this->type == t_int && other.type == t_int)			{	return this->integ > other.integ;		}
	else if (this->type == t_int && other.type == t_double) {	return this->integ > other.doub;		}
	else if (this->type == t_int && other.type == t_string) {
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		return this->integ > int_string;		
	}

	else if (this->type == t_double && other.type == t_double) {	return this->doub > other.doub;		}
	else if (this->type == t_double && other.type == t_int)    {	return this->doub > other.integ;	}
	else if (this->type == t_double && other.type == t_string) {
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		return this->doub > int_string;		
	}
	   	 
}

bool Var::operator<(Var & other)
{
	if (this->type == t_int && other.type == t_int)			{ return this->integ < other.integ; }
	else if (this->type == t_int && other.type == t_double) { return this->integ < other.doub; }
	else if (this->type == t_int && other.type == t_string) {
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		return this->integ < int_string;
	}

	else if (this->type == t_double && other.type == t_double)  { return this->doub < other.doub; }
	else if (this->type == t_double && other.type == t_int)		{ return this->doub < other.integ; }
	else if (this->type == t_double && other.type == t_string) {
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		return this->doub < int_string;
	}
}

bool Var::operator>=(Var & other)
{
	if (this->type == t_int && other.type == t_int)			{ return this->integ >= other.integ; }
	else if (this->type == t_int && other.type == t_double) { return this->integ >= other.doub; }
	else if (this->type == t_int && other.type == t_string) {
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		return this->integ >= int_string;
	}

	else if (this->type == t_double && other.type == t_double)	{ return this->doub >= other.doub; }
	else if (this->type == t_double && other.type == t_int)		{ return this->doub >= other.integ; }
	else if (this->type == t_double && other.type == t_string) {
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		return this->doub >= int_string;
	}
}

bool Var::operator<=(Var & other)
{
	if (this->type == t_int && other.type == t_int)			{ return this->integ <= other.integ; }
	else if (this->type == t_int && other.type == t_double) { return this->integ <= other.doub; }
	else if (this->type == t_int && other.type == t_string) {
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		return this->integ < int_string;
	}

	else if (this->type == t_double && other.type == t_double)  { return this->doub <= other.doub; }
	else if (this->type == t_double && other.type == t_int)		{ return this->doub <= other.integ; }
	else if (this->type == t_double && other.type == t_string) {
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		return this->doub <= int_string;
	}
}

bool Var::operator==(Var & other)
{
	if (this->type == t_int && other.type == t_int)			{ return this->integ == other.integ; }
	else if (this->type == t_int && other.type == t_double) { return this->integ == other.doub; }
	else if (this->type == t_int && other.type == t_string) {
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		return this->integ < int_string;
	}

	else if (this->type == t_double && other.type == t_double)  { return this->doub == other.doub; }
	else if (this->type == t_double && other.type == t_int)		{ return this->doub == other.integ; }
	else if (this->type == t_double && other.type == t_string) {
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		return this->doub == int_string;
	}
}

bool Var::operator!=(Var & other)
{
	if (this->type == t_int && other.type == t_int)			{ return this->integ != other.integ; }
	else if (this->type == t_int && other.type == t_double) { return this->integ != other.doub; }
	else if (this->type == t_int && other.type == t_string) {
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		return this->integ != int_string;
	}

	else if (this->type == t_double && other.type == t_double)  { return this->doub != other.doub; }
	else if (this->type == t_double && other.type == t_int)		{ return this->doub != other.integ; }
	else if (this->type == t_double && other.type == t_string) {
		int int_string = other.convert_from_string_to_int(other.str.Get_string());
		return this->doub != int_string;
	}
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
