# -- coding: cp1251 --
#������� 1
#�������� ���������, ������� ��������� 3 �����, ���������� ����� ����� � ���������� ������������ 
#� ����������� �����. ��������� ������ ����� ��������� ������������ ��������� 
#�������� �������� �����. ������� min � ��� �� ������������. ������ �������� ��������.

n = int(input("������� ���������� ���������: "))
sequence = [int(input()) for i in range(n)]
max_number = sequence[0]
for num in sequence:
    if num > max_number:
        max_number = num

print("������������ �����:", max_number)
min_number = sequence[0]
for num in sequence:
    if num < min_number:
        min_number = num

print("����������� �����:", min_number)

#������� 2.1 
#�������� ���������, � ������� ��������  
#����������� ����� n � ��������� �������� �������� �� n ��������, 
#i-� ��������� ������ �������� �� ����� �� 1 �� i ��� ��������.

a = int(input("������� �����: "))

for i in range(a, 0, -1):
    print("".join(str(j) for j in range(1, i + 1))) 

#������� 2.2
#�������� ���������, � ������� �������� ����������� ����� n � ��������� 
#������������ �������� �� n ��������, i-� ������� ������ �������� �� ����� 
#�� 1 �� i � ������� ��� ��������.

    
b = int(input("������� �����: "))
for i in range(b, 0, -1):
    spaces = " " * (b - i)  # ��������� �������
    numbers = "".join(str(j) for j in range(i, 0, -1)) + "".join(str(j) for j in range(2, i + 1))
    print(spaces + numbers)