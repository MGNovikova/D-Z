#include <iostream>
#include <math.h>
int main()
{
	setlocale(LC_ALL, "ru");
	float N, X;
	int i = 5;
	 while (i < 7)
	{
		 std::cout << "������� �����:";
		std::cin >> N;
		std::cout << "������� n-�� �������:";
		std::cin >> X;
		std::cout << "����:";
		std::cout << pow(N, X) << std::endl;
	}
}
