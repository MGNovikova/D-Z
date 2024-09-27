//Установить i-ый бит числа х (0<x<10^9) в 1.
#include <iostream>
#include <bitset>
#include <climits>
using namespace std;

int main() 
{

	int x = 5;
	int i = x << 1;

	std::cout << i << "\n";
}
// (x>>) & 1 cout << x;  cout << (x >> i) %2<< "\n";
// Примерно берём число, раскладываем на бит и меняем одно из его чисел на 1


