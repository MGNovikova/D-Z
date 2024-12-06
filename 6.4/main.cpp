/* 6.4. Сначала введите последовательность. Затем удалите и продублируйте элементы. Затем выведите 
полученную последовательность (каждый элемент по одному разу). 
Используйте в программе только один массив.
Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000). 
Удалить из последовательности числа, произведение цифр которых равно 180, 
а среди оставшихся продублировать числа, начинающиеся и заканчивающиеся цифрой 1.
*/

#include <iostream>
// Функция умножения
int multi(int number)
{
    int a = 1;
    while (number > 0)
    {
        a *= (number % 10);
        number /= 10;
    }
    return a;
}

// Определение первого числа
int firs_nummber(int number)
{
    while (number > 9) { number /= 10; }
    return number;
}

// Определение последнего последовательности
int last_number(int number)
{
    number = number % 10;
    return number;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    const int N_MAX = 20000;
    int mas[N_MAX];
    int n;
    std::cout << "Количество чисел воследовательности:" << std::endl;
    std::cin >> n;

    std::cout << "Введите последовательность:" << std::endl;
    for (int i = 0; i < n; ++i) { std::cin >> mas[i]; }

    //Удаление числа произведение которого равно 180
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        if (multi(mas[i]) == 180)
            continue;
        mas[j] = mas[i];
        j++;
    }
    n = j;
    
    //Дублирование числа с 1 в начале и 1 в конце
    for (int i = 0; i < n; i++)
        if ((firs_nummber(mas[i]) == 1) && (last_number(mas[i]) == 1))
        {
            for (int j = n; j > i; --j)
            {
                mas[j] = mas[j - 1];
            }
            i++; //второй раз увеличиваем i для того чтобы не дублировалось бесконечно
            n++;
        }
    std::cout << "Полученная последовательность:" << std::endl;
    for (int i = 0; i < n; ++i)
        std::cout << mas[i] << std::endl;

    return 0;
}