#include <iostream>
#include <vector>

using namespace std;
//Написать шаблонную функцию или класс согласно варианту. Описать класс-исключение или
//иерархию классов-исключений. Генерировать исключения в соответствующих исключительных
//ситуациях. Если у вас есть другие предложения по исключительным ситуациям – используйте их.

//Вариант 22 : Поиск минимального из двух элементов(Описание). Тип элементов(Параметры шаблона).

//Очередь из макс. N элементов типа T(Описание) int N, class T (Параметры шаблона)
//Переполнение очереди. Изъятие элемента из пустой очереди(Исключения).

template<typename T>
T min(T &x, T &y) {
    if (x > y)
        return y;
    else return x;
}

class Qexception : public exception {
public:
    explicit Qexception(const string &text = "") {
        cerr << text;
    }
};

class overflowException : public Qexception {
public:
    explicit overflowException() :
            Qexception("OVERFLOW\n") {}
};

class emptyException : public Qexception {
public:
    explicit emptyException() :
            Qexception("EMPTY QUEUE\n") {}
};

template<class T, unsigned int maxSize>
class queue {
public:
    vector<T> elements;
    unsigned int start;
    unsigned int end;
    unsigned int size;

    queue() {
        start = end = 0;
        size = 0;
        elements = vector<T>(maxSize);
    }

    void push(T element) {
        if (end == maxSize)
            throw overflowException();
        elements[end] = element;
        ++end;
        ++size;
    }

    T pop() {
        if (size == 0)
            throw emptyException();
        unsigned int top = start;
        ++start;
        --size;
        return elements[top];
    }
};


int main() {
    int x = 1;
    int y = 2;

    cout << "Select min of elements : \n"
         << "x = " << x << "; y = " << y << '\n';
    cout << "Min element is : " << min(x, y) << '\n';
    cout << '\n';

    cout << "Queue; \n";
    queue<int, 1> q;
    q.push(1);
    cout << "Element 1 in queue;\n";

    //cout << "Try to add new element in queue : \n";
    //q.push(2);

    cout << "Element is out of queue : " << q.pop() << '\n';

    //cout << "Try to top element from empty queue : \n";
    //q.pop();

    return 0;
}