# -- coding: cp1251 --
#������� 1
#�������� ���������, ������� ��������� �� ���� ������ ��������
#(��������� � ��������� ����� ���������� ��������), ������� ����� ����������,
#��������: YYYYggkeeeAAABV . ��������� � �������� ����� �����������.
#��������� ������ ������������� (������������) ������ � ������ ������:
#Y4g2ke3A3BV . ����� ����� ������� � ���������� ����������, ���� ������ �����������
#� �����we �������� �� ����.

def compress_string(s):
    if not s:
        return ""
    
    result = []
    current_char = s[0]
    count = 1
    
    for i in range(1, len(s)):
        if s[i] == current_char:
            count += 1
        else:
            result.append(current_char + (str(count) if count > 1 else ""))
            current_char = s[i]
            count = 1
    
    result.append(current_char + (str(count) if count > 1 else ""))
    
    return "".join(result)

# ���� ������
input_string = input("������� ������: ")
compressed = compress_string(input_string)
print("������ ������:", compressed)



#�1.1
#s = input()
# s2 = ''
# for i in range(len(s)-1):
#     if s[i].isdigit()==False and s[i+1].isdigit() == True:
#         s2 = s2 + s[i]*int(s[i+1])
#     elif s[i].isdigit()==False and s[i+1].isdigit() == False:
#         s2 += s[i]
# if not s[-1].isdigit():
#     s2 += s[-1]
# print(s2)

#�2
#s = input()
# symbols = []
# integer = []
# s = s.replace(' ', '')
# for i in s:
#     if i not in symbols:
#         symbols.append(i)
# for i in symbols:
#     integer.append(s.count(i))
    
# for i in range(len(integer)-1):
#     for j in range(i+1,len(integer)):
#         if integer[i] > integer[j]:
#             integer[i], integer[j] = integer[j], integer[i]
#             symbols[i], symbols[j] = symbols[j], symbols[i]

