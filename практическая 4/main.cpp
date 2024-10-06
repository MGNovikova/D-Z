/*¬ариант 9.
¬вести натуральные числа A, B и C. ≈сли A больше B и B больше C, то вывести A-B-C, если B больше A и B  кратно C,
то вывести B/—+B-A, в остальных случа€х вывести A+B+C.
¬вести число N, которое обозначает некоторую ошибку. ѕри помощи оператора switch расшифровать значение ошибки.
—писок ошибок:
0 Ц все хорошо, 1 Ц ошибка чтени€ файла, 2 Ц ошибка записи файла, 
3 Ц не все пол€ определены. ѕредусмотреть обработку ошибочного ввода N.
ѕеременна€ x может принимать 2 значени€: -1 и 1. ≈сли -1, то вывести в консоль УNegative numberФ,
если положительное - УPositive numberФ. ѕредложить вариант программы и объ€снить свой выбор.
*/
#include "iostream"
#include "math.h"
using namespace std;

int main()
{
	//if...else
	int x, a, b, c;

	setlocale(LC_ALL, "rus");
	cout << "¬ведите значемне a: ";
	cin >> a;
	cout << "¬ведите значемне b: ";
	cin >> b;
	cout << "¬ведите значемне c: ";
	cin >> c;


	if (a > b && b > c)
	{
		x = a - b - c;
		cout << x << endl;

	}
	else if ((a < b) && b % c == 0)
	{
		x = ((b / c) + b - a);
		cout << x << endl;
	}
	else
	{ 
		x = a + b + c;
		cout << x << endl;
	}
	
	int N;
	cin >> N;
	switch (N)
	{
	case 1: cout << "error ошибка чтени€ файла " << endl;
		break;
	case 2: cout << "error ошибка записи файла" << endl;
		break;
	case 3: cout << "error не все пол€ определены" << endl;
		break;
	default:cout << "unknown error"<< endl;
	}

	int z;
	cout << "¬ведите значение z: ";
	cin >> z;
	if (z >= 0)
	{
		cout << "Positive number";
	}
	else if (z<0)
	{ 
		cout << "Negative number";
	}
}