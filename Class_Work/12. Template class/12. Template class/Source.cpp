#include <iostream>
#include <string>
#include"CShop.h"
#include"Book.h"
#include"Audio.h"
#include"Megazine.h"
using namespace std;


/*You need to create a template class "CShop" (Store), which works like a regular template array of any type and contains :
fields:
pointer to array type;
the size of the array.
additional methods :
search for the minimum and maximum element of the array;
method for sorting elements of an array in ascending or descending order(for example, by price; by 12 points);
method for finding the arithmetic mean of all elements of an array;
overload indexing operator.
You must also create the following set of classes :
Book containing the following fields :
book title;
publishing house;
author;
price;
a boolean field indicating whether the book is new: true - new, false - no.
Megazine, which contains the following fields :
the name of the journal;
price;
boolean field indicating whether the log is new: true - new, false - no.
An audio disc(Audio) which should contain the following fields :
disk name;
performer;
number of tracks;
price;
a boolean field indicating whether an audio disk is new: true - new, false - no.
For each class write the necessary set of methods.
In the main program, create 3 store template objects for the types that are valid in the program(Books, Magazine, Audio disks).

Необхідно створити шаблонний клас "CShop" (Магазин), який працює як звичайний шаблонний масив будь-якого типу та містить:
поля:
вказівник на тип масиву;
розмір масиву.
дадаткові методи:
пошук мінімального та максимального елемента масиву;
метод для сортування елементів масиву по зростанню або спаданню (наприклад, по ціні; на 12 балів);
метод для пошуку середнього арифметичного всіх елементів масиву;
перенавантажити оператор індексування.
Необхідно також створити наступний набір класів:
Книгa (Book), яка містить наступні поля:
назва книги;
видавництво;
автор;
ціна;
булівське поле, яке вказує чи книга є нова: true – нова, false – ні.
Журнал (Megazine), який містить наступні поля:
назва журналу;
ціна;
булівське поле, яке вказує чи журнал є новим: true – новий, false – ні.
Аудіо диск (Audio), який має містити наступні поля:
назва диску;
виконавець;
кількість треків;
ціна;
булівське поле, яке вказує чи аудіо диск є новим: true – новий, false – ні.
Для кожного класу написати необхідний набір методів.
В основній програмі, створити 3 об’єкти шаблонного класу "Магазин" для допустимих в програмі типів (Книги, Журнал, Аудіо диски). 
*/

int main() {
	

	CShop <Book> shop_b(3);
	shop_b.Show_info();
	cout << "\n=============================================" << endl;
	shop_b.Most_expensive();
	cout << "\n=============================================" << endl;
	shop_b.Cheapest_product();
	cout << "\n=============================================" << endl;
	shop_b.Average_price();

	cout << "----------------->>> Indexing operator";
	shop_b[0];
	
	shop_b.Sort_min_max();
	shop_b.Show_info();

	shop_b.Sort_max_min();
	shop_b.Show_info();
	

	/*CShop <Audio> shop_a(1);
	shop_a.Show_info();

	CShop <Megazine> shop_m(1);
	shop_m.Show_info();*/

	system("pause");
	return 0;
}
