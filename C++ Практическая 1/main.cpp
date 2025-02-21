/*
������� 9. 
������ ������������������ ����������� �����. 
���� ������������������ ����������� �� ���������� (�����������)  
��� �� ������������� (��������) ��������� �����, 
������� �� ������������������ ������� �����, � �������������� ����� ������� 12. 
� ��������� ������ ����������� ������������������ �� ���������� ������ �����. 
������������������ ������� � ���������� ����������� ������ � ��������� ���������.
*/
#include <iostream> 
//���� ����������� ������
struct Node {
	int data;
	Node* left;
	Node* right;

};
//������� ��������� ����� ���� ����� ���������� �������� ������ (`sent`). 
// ��� ����������� �� ���� �������� ������ ���� `p`,
// ������� ����� ����������� ����� ��������� ��������� � ��������� ������ ������ `sent`.
void AddBack(Node* sent, int data) {
	Node* p = new Node;
	p->data = data;
	p->left = sent->left;
	p->right = sent;
	sent->left->right = p;
	sent->left = p;

}
//������� ������� ��� �������� ������, ������� �� ������� �� ����������. ������ ��������� ������, 
// ���� ������� ���� �� ������ ������ ���������� ���� `sent`. 
// ������ ��� ��������� ������ �������� ����.
void Print(Node* sent) {
	Node* p = sent->right;
	while (p != sent) {
		std::cout << p->data << std::endl;
		p = p->right;
	}
}
//������� ������� ������, ������ ������ ����. 
// ������� ����������� ��������� ��������� �� ������� ����, 
// ����� ���������� ������� � ���������� ����, � ������ ���� ���������. 
// ���� ������������ �� ��� ���, ���� �� ����� ��������� ��������� ����, 
// ��������� � ��������� ������ `sent`.
void Clear(Node* sent)
{
	Node* p = sent->right;
	while (p != sent)
	{
		Node* tmp = p;
		p = p->right;
		delete tmp;
	}
}
//������� ��������� ����, � ������� �������� ������ ������� �� 12 ��� �������. 
// ��� ������� ����������� ���� ��������� �����, ������� ����������� ����� ����� ��������� ����.
void Duplicate(Node* sent)
{
    Node* p = sent->right;
    while (p != sent)
    {
        if (p->data % 12 == 0)
        {
            Node* q = new Node;
            q->data = p->data;
            q->left = p;
            q->right = p->right;
            p->right->left = q;
            p->right = q;
            p = p->right;
        }
        p = p->right;
    }
}

//������� ���������, �������� �� ���������� ����� �������.
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= std::sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

//������� ������� �� ������ ��� ����, �������� ������� �������� �������� �������. 
// ���� ������� ���� ����� ������� ��������, �� ���������, 
// � ����� � ��������� ������ ��������������.
void Remove(Node* sent)
{
    Node* p = sent->right;
    while (p != sent)
    {
        if (isPrime(p->data))
        {
            Node* tmp = p;
            p->left->right = p->right;
            p->right->left = p->left;
            p = p->left;
            delete tmp;
        }
        p = p->right;
    }
}

//������� ���������, ������������� �� ��������� ����� ������� ����� � ������. 
// ���� ���� �� ���� ���� ����� �������� ���� �������, ������� ���������� `false`, ����� � `true`.
bool Non_Decreasing(Node* sent)
{
    Node* current = sent->right;
    int lastDigit = current->data % 10;
    while (current != sent)
    {
        if (current->data % 10 < lastDigit)
        {
            return false;
        }
        lastDigit = current->data % 10;
        current = current->right;
    }
    return true;
}

//��� �������� ����, �������� �� ��������� ����� �������� ������ � ����� 
// ������ ������ ��������� ������������������. 
// ������� ���������� � ������ ���������.
bool Non_Increasing(Node* sent)
{
    Node* current = sent->right;
    int lastDigit = current->data % 10;

    while (current != sent)
    {
        if (current->data % 10 > lastDigit)
        {
            return false;
        }
        lastDigit = current->data % 10;
        current = current->right;
    }
    return true;
}

//��� ������� ��������� ������ ����� �����.
int first_D(int n)
{
    while (n >= 10)
    {
        n = n / 10;
    }
    return n;
}

//������� sort() ��������� �������� ����������� ���������� 
// ��� �������������� ��������� ������ �� �� ������ ������. 
void sort(Node* sent)
{
    int c = 1;
    while (c != 0)
    {
        c = 0;
        Node* p = sent->right;
        while (p->right != sent) //���� �������� ���������� ���������� ������� sort(). �� �������� �� ������ � ���������� ������ ����� ���� �������� �����.
        {
            if ((first_D(p->data)) > (first_D(p->right->data)))
            {
                int tmp = p->data;
                p->data = p->right->data;
                p->right->data = tmp;
                c++;
            }
            p = p->right;
        }
    }
}


int main()
{
    Node* sent = new Node;
    sent->right = sent;
    sent->left = sent;
    int n, a;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a;
        AddBack(sent, a);
    }
    if (Non_Decreasing(sent) || Non_Increasing(sent))
    {
        Remove(sent);
        Duplicate(sent);
    }
    else;
    {
        sort(sent);
    }
    Print(sent);
    Clear(sent);

    delete sent;
}
