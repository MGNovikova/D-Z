/*������� 9.
������ ����������� ����� A, B � C. ���� A ������ B � B ������ C, �� ������� A-B-C, ���� B ������ A � B  ������ C,
�� ������� B/�+B-A, � ��������� ������� ������� A+B+C.
������ ����� N, ������� ���������� ��������� ������. ��� ������ ��������� switch ������������ �������� ������.
������ ������:
0 � ��� ������, 1 � ������ ������ �����, 2 � ������ ������ �����, 
3 � �� ��� ���� ����������. ������������� ��������� ���������� ����� N.
���������� x ����� ��������� 2 ��������: -1 � 1. ���� -1, �� ������� � ������� �Negative number�,
���� ������������� - �Positive number�. ���������� ������� ��������� � ��������� ���� �����.
*/
#include "iostream"
#include "math.h"
using namespace std;

int main()
{
	//if...else
	int x, a, b, c;

	setlocale(LC_ALL, "rus");
	cout << "������� �������� a: ";
	cin >> a;
	cout << "������� �������� b: ";
	cin >> b;
	cout << "������� �������� c: ";
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
	case 1: cout << "error ������ ������ ����� " << endl;
		break;
	case 2: cout << "error ������ ������ �����" << endl;
		break;
	case 3: cout << "error �� ��� ���� ����������" << endl;
		break;
	default:cout << "unknown error"<< endl;
	}

	int z;
	cout << "������� �������� z: ";
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