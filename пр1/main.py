# -- coding: cp1251 --
#Задание 1
#Напишите программу, которая принимает 3 числа, сравнивает между собой и возвращает максимальное 
#и минимальное числа. Программа должна также корректно обрабатывать различные 
#варианты равенств чисел. Функции min и мах не использовать. Только условный оператор.

n = int(input("Введите количество элементов: "))
sequence = [int(input()) for i in range(n)]
max_number = sequence[0]
for num in sequence:
    if num > max_number:
        max_number = num

print("Максимальное число:", max_number)
min_number = sequence[0]
for num in sequence:
    if num < min_number:
        min_number = num

print("Минимальное число:", min_number)

#Задание 2.1 
#Напишите программу, в которой задается  
#натуральное число n и выводится обратная лестница из n ступенек, 
#i-я ступенька должна состоять из чисел от 1 до i без пробелов.

a = int(input("Введите число: "))

for i in range(a, 0, -1):
    print("".join(str(j) for j in range(1, i + 1))) 

#Задание 2.2
#Напишите программу, в которой задается натуральное число n и выводится 
#перевернутая пирамида из n ступенек, i-я ступень должна состоять из чисел 
#от 1 до i и обратно без пробелов.

    
b = int(input("Введите число: "))
for i in range(b, 0, -1):
    spaces = " " * (b - i)  # Добавляем отступы
    numbers = "".join(str(j) for j in range(i, 0, -1)) + "".join(str(j) for j in range(2, i + 1))
    print(spaces + numbers)