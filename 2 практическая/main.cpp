#include <iostream>
#include <math.h>
int main()
{
	setlocale(LC_ALL, "ru");
	float N, X;
	int i = 5;
	 while (i < 7)
	{
		 std::cout << "¬ведите число:";
		std::cin >> N;
		std::cout << "¬ведите n-ую степень:";
		std::cin >> X;
		std::cout << "»тог:";
		std::cout << pow(N, X) << std::endl;
	}
}
