/*
Вариант 9. 
Ввести последовательность натуральных чисел. 
Если последовательность упорядочена по неубыванию (возрастание)  
или по невозрастанию (убывание) последней цифры, 
удалить из последовательности простые числа, и продублировать числа кратные 12. 
В противном случае упорядочить последовательность по неубыванию первой цифры. 
Последовательность хранить в двусвязном циклическом списке с фиктивным элементом.
*/
#include <iostream> 
//узел двусвязного списка
struct Node {
	int data;
	Node* left;
	Node* right;

};
//Функция добавляет новый узел после последнего элемента списка (`sent`). 
// Это достигается за счет создания нового узла `p`,
// который затем вставляется между последним элементом и отправной точкой списка `sent`.
void AddBack(Node* sent, int data) {
	Node* p = new Node;
	p->data = data;
	p->left = sent->left;
	p->right = sent;
	sent->left->right = p;
	sent->left = p;

}
//Функция выводит все элементы списка, начиная от первого до последнего. Список обходится циклом, 
// пока текущий узел не станет равным отправному узлу `sent`. 
// Каждый раз выводятся данные текущего узла.
void Print(Node* sent) {
	Node* p = sent->right;
	while (p != sent) {
		std::cout << p->data << std::endl;
		p = p->right;
	}
}
//Функция очищает список, удаляя каждый узел. 
// Сначала сохраняется временный указатель на текущий узел, 
// затем происходит переход к следующему узлу, а старый узел удаляется. 
// Цикл продолжается до тех пор, пока не будет достигнут последний узел, 
// связанный с отправной точкой `sent`.
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
//Функция дублирует узлы, у которых значение данных делится на 12 без остатка. 
// Для каждого подходящего узла создается копия, которая вставляется сразу после исходного узла.
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

//Функция проверяет, является ли переданное число простым.
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

//Функция удаляет из списка все узлы, значения которых являются простыми числами. 
// Если текущий узел имеет простое значение, он удаляется, 
// а связи с соседними узлами корректируются.
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

//Функция проверяет, увеличивается ли последняя цифра каждого числа в списке. 
// Если хотя бы одна пара чисел нарушает этот порядок, функция возвращает `false`, иначе — `true`.
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

//для проверки того, образуют ли последние цифры значений данных в узлах 
// списка строго убывающую последовательность. 
// Давайте рассмотрим её работу подробнее.
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

//Эта функция извлекает первую цифру числа.
int first_D(int n)
{
    while (n >= 10)
    {
        n = n / 10;
    }
    return n;
}

//Функция sort() реализует алгоритм пузырьковой сортировки 
// для упорядочивания элементов списка по их первым цифрам. 
void sort(Node* sent)
{
    int c = 1;
    while (c != 0)
    {
        c = 0;
        Node* p = sent->right;
        while (p->right != sent) //Этот фрагмент продолжает реализацию функции sort(). Он проходит по списку и сравнивает первые цифры двух соседних узлов.
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
