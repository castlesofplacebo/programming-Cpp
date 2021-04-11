#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

/*функциональные требования :
- Сохранение и чтение состояния кубика рубика из файла
- Проверка корректности текущего состояния (инвариант состояний кубика)
- Вывод в консоль текущего состояния
- Вращение граней кубика рубика с помощью вводимых команд
- Генерация случайного состояния Кубика Рубика, корректного с точки зрения
инварианта состояний
- Нахождения “решения” для текущего состояния в виде последовательности
поворотов граней*/

//https://speedcubing.com.ua/howto/3x3

ifstream in("input.in");
ofstream out("output.out");

struct modification
{
    char a;
    char b;
    char c;
    char d;
    char e;
    char f;
    char g;
    char h;
    char i;
};

class instructions
{
public:
    modification right;
    modification left;
    modification front;
    modification back;
    modification up;
    modification down;

    void changeRotate(char &q, char &w, char &r, char &t)
    {
        char temp1 = q;
        q = w;
        char temp2 = r;
        r = temp1;
        temp1 = t;
        t = temp2;
        w = temp1;
    }

    void RightRotate()
    {
        modification current{};

        /*current = right;*/
        current.a = right.a;
        current.b = right.b;
        current.c = right.c;
        current.d = right.d;
        current.e = right.e;
        current.f = right.f;
        current.g = right.g;
        current.h = right.h;
        current.i = right.i;

        right.a = current.g;
        right.b = current.d;
        right.c = current.a;
        right.d = current.h;
        right.e = current.e;
        right.f = current.b;
        right.g = current.i;
        right.h = current.f;
        right.i = current.c;

        changeRotate(up.c, front.c, back.c, down.c);
        changeRotate(up.f, front.f, back.f, down.f);
        changeRotate(up.i, front.i, back.i, down.i);

        out << "RIGHT ROT; ";
    }

    void RightHatchRotate()
    {
        modification current{};

        /*current = right;*/
        current.a = right.a;
        current.b = right.b;
        current.c = right.c;
        current.d = right.d;
        current.e = right.e;
        current.f = right.f;
        current.g = right.g;
        current.h = right.h;
        current.i = right.i;

        right.a = current.c;
        right.b = current.f;
        right.c = current.i;
        right.d = current.b;
        right.e = current.e;
        right.f = current.h;
        right.g = current.a;
        right.h = current.d;
        right.i = current.g;

        changeRotate(up.c, back.c, front.c, down.c);
        changeRotate(up.f, back.f, front.f, down.f);
        changeRotate(up.i, back.i, front.i, down.i);

        out << "RIGHT HATCH ROT; ";
    }

    void LeftRotate()
    {
        modification current{};

        current.a = left.a;
        current.b = left.b;
        current.c = left.c;
        current.d = left.d;
        current.e = left.e;
        current.f = left.f;
        current.g = left.g;
        current.h = left.h;
        current.i = left.i;

        left.a = current.g;
        left.b = current.d;
        left.c = current.a;
        left.d = current.h;
        left.e = current.e;
        left.f = current.b;
        left.g = current.i;
        left.h = current.f;
        left.i = current.c;

        changeRotate(up.a, back.a, front.a, down.a);
        changeRotate(up.d, back.d, front.d, down.d);
        changeRotate(up.g, back.g, front.g, down.g);

        out << "LEFT ROT; ";
    }

    void LeftHatchRotate()
    {
        modification current{};

        current.a = left.a;
        current.b = left.b;
        current.c = left.c;
        current.d = left.d;
        current.e = left.e;
        current.f = left.f;
        current.g = left.g;
        current.h = left.h;
        current.i = left.i;

        left.a = current.c;
        left.b = current.f;
        left.c = current.i;
        left.d = current.b;
        left.e = current.e;
        left.f = current.h;
        left.g = current.a;
        left.h = current.d;
        left.i = current.g;

        changeRotate(up.a, front.a, back.a, down.a);
        changeRotate(up.d, front.d, back.d, down.d);
        changeRotate(up.g, front.g, back.g, down.g);

        out << "LEFT HATCH ROT; ";
    }

    void UpRotate()
    {
        modification current{};

        current.a = up.a;
        current.b = up.b;
        current.c = up.c;
        current.d = up.d;
        current.e = up.e;
        current.f = up.f;
        current.g = up.g;
        current.h = up.h;
        current.i = up.i;

        up.a = current.g;
        up.b = current.d;
        up.c = current.a;
        up.d = current.h;
        up.e = current.e;
        up.f = current.b;
        up.g = current.i;
        up.h = current.f;
        up.i = current.c;

        changeRotate(front.a, right.a, left.a, back.i);
        changeRotate(front.b, right.b, left.b, back.h);
        changeRotate(front.c, right.c, left.c, back.g);

        out << "UP ROT; ";
    }

    void UpHatchRotate()
    {
        modification current{};

        current.a = up.a;
        current.b = up.b;
        current.c = up.c;
        current.d = up.d;
        current.e = up.e;
        current.f = up.f;
        current.g = up.g;
        current.h = up.h;
        current.i = up.i;

        up.a = current.c;
        up.b = current.f;
        up.c = current.i;
        up.d = current.b;
        up.e = current.e;
        up.f = current.h;
        up.g = current.a;
        up.h = current.d;
        up.i = current.g;

        changeRotate(right.a, front.a, back.i, left.a);
        changeRotate(right.b, front.b, back.h, left.b);
        changeRotate(right.c, front.c, back.g, left.c);

        out << "UP HATCH ROT; ";
    }

    void DownRotate()
    {
        modification current{};

        current.a = down.a;
        current.b = down.b;
        current.c = down.c;
        current.d = down.d;
        current.e = down.e;
        current.f = down.f;
        current.g = down.g;
        current.h = down.h;
        current.i = down.i;

        down.a = current.c;
        down.b = current.f;
        down.c = current.i;
        down.d = current.b;
        down.e = current.e;
        down.f = current.h;
        down.g = current.a;
        down.h = current.d;
        down.i = current.g;

        changeRotate(front.g, right.g, left.g, back.c);
        changeRotate(front.h, right.h, left.h, back.b);
        changeRotate(front.i, right.i, left.i, back.a);

        out << "DOWN ROT; ";
    }

    void DownHatchRotate()
    {
        modification current{};

        current.a = down.a;
        current.b = down.b;
        current.c = down.c;
        current.d = down.d;
        current.e = down.e;
        current.f = down.f;
        current.g = down.g;
        current.h = down.h;
        current.i = down.i;

        down.a = current.g;
        down.b = current.d;
        down.c = current.a;
        down.d = current.h;
        down.e = current.e;
        down.f = current.b;
        down.g = current.i;
        down.h = current.f;
        down.i = current.c;

        changeRotate(right.g, front.g, back.c, left.g);
        changeRotate(right.h, front.h, back.b, left.h);
        changeRotate(right.i, front.i, back.a, left.i);

        out << "DOWN HATCH ROT; ";
    }

    void BackRotate()
    {
        modification current{};

        current.a = back.a;
        current.b = back.b;
        current.c = back.c;
        current.d = back.d;
        current.e = back.e;
        current.f = back.f;
        current.g = back.g;
        current.h = back.h;
        current.i = back.i;

        back.a = current.g;
        back.b = current.d;
        back.c = current.a;
        back.d = current.h;
        back.e = current.e;
        back.f = current.b;
        back.g = current.i;
        back.h = current.f;
        back.i = current.c;

        changeRotate(left.a, up.c, down.g, right.i);
        changeRotate(left.d, up.b, down.h, right.f);
        changeRotate(left.g, up.a, down.i, right.c);

        out << "BACK ROT; ";
    }

    void BackHatchRotate()
    {
        modification current{};

        current.a = back.a;
        current.b = back.b;
        current.c = back.c;
        current.d = back.d;
        current.e = back.e;
        current.f = back.f;
        current.g = back.g;
        current.h = back.h;
        current.i = back.i;

        back.a = current.c;
        back.b = current.f;
        back.c = current.i;
        back.d = current.b;
        back.e = current.e;
        back.f = current.h;
        back.g = current.a;
        back.h = current.d;
        back.i = current.g;

        changeRotate(right.i, up.c, down.g, left.a);
        changeRotate(right.f, up.b, down.h, left.d);
        changeRotate(right.c, up.a, down.i, left.g);

        out << "BACK HATCH ROT; ";
    }

    void FrontRotate()
    {
        modification current{};

        current.a = front.a;
        current.b = front.b;
        current.c = front.c;
        current.d = front.d;
        current.e = front.e;
        current.f = front.f;
        current.g = front.g;
        current.h = front.h;
        current.i = front.i;

        front.a = current.g;
        front.b = current.d;
        front.c = current.a;
        front.d = current.h;
        front.e = current.e;
        front.f = current.b;
        front.g = current.i;
        front.h = current.f;
        front.i = current.c;

        changeRotate(right.g, up.i, down.a, left.c);
        changeRotate(right.d, up.h, down.b, left.f);
        changeRotate(right.a, up.g, down.c, left.i);

        out << "FRONT ROT; ";
    }

    void FrontHatchRotate()
    {
        modification current{};

        current.a = front.a;
        current.b = front.b;
        current.c = front.c;
        current.d = front.d;
        current.e = front.e;
        current.f = front.f;
        current.g = front.g;
        current.h = front.h;
        current.i = front.i;

        front.a = current.c;
        front.b = current.f;
        front.c = current.i;
        front.d = current.b;
        front.e = current.e;
        front.f = current.h;
        front.g = current.a;
        front.h = current.d;
        front.i = current.g;

        changeRotate(up.i, right.g, left.c, down.a);
        changeRotate(up.h, right.d, left.f, down.b);
        changeRotate(up.g, right.a, left.i, down.c);

        out << "FRONT HATCH ROT; ";
    }
};

int Color[6];
void getColor(char c)
{
    if (c == 'R')
        ++Color[0];
    else if (c == 'O')
        ++Color[1];
    else if (c == 'B')
        ++Color[2];
    else if (c == 'G')
        ++Color[3];
    else if (c == 'Y')
        ++Color[4];
    else if (c == 'W')
        ++Color[5];
}

void read(instructions &current)
{
    char q;

    in >> q;
    getColor(q);
    current.front.a = q;
    in >> q;
    getColor(q);
    current.front.b = q;
    in >> q;
    getColor(q);
    current.front.c = q;
    in >> q;
    getColor(q);
    current.front.d = q;
    in >> q;
    getColor(q);
    current.front.e = q;
    in >> q;
    getColor(q);
    current.front.f = q;
    in >> q;
    getColor(q);
    current.front.g = q;
    in >> q;
    getColor(q);
    current.front.h = q;
    in >> q;
    getColor(q);
    current.front.i = q;

    in >> q;
    getColor(q);
    current.back.a = q;
    in >> q;
    getColor(q);
    current.back.b = q;
    in >> q;
    getColor(q);
    current.back.c = q;
    in >> q;
    getColor(q);
    current.back.d = q;
    in >> q;
    getColor(q);
    current.back.e = q;
    in >> q;
    getColor(q);
    current.back.f = q;
    in >> q;
    getColor(q);
    current.back.g = q;
    in >> q;
    getColor(q);
    current.back.h = q;
    in >> q;
    getColor(q);
    current.back.i = q;

    in >> q;
    getColor(q);
    current.left.a = q;
    in >> q;
    getColor(q);
    current.left.b = q;
    in >> q;
    getColor(q);
    current.left.c = q;
    in >> q;
    getColor(q);
    current.left.d = q;
    in >> q;
    getColor(q);
    current.left.e = q;
    in >> q;
    getColor(q);
    current.left.f = q;
    in >> q;
    getColor(q);
    current.left.g = q;
    in >> q;
    getColor(q);
    current.left.h = q;
    in >> q;
    getColor(q);
    current.left.i = q;

    in >> q;
    getColor(q);
    current.right.a = q;
    in >> q;
    getColor(q);
    current.right.b = q;
    in >> q;
    getColor(q);
    current.right.c = q;
    in >> q;
    getColor(q);
    current.right.d = q;
    in >> q;
    getColor(q);
    current.right.e = q;
    in >> q;
    getColor(q);
    current.right.f = q;
    in >> q;
    getColor(q);
    current.right.g = q;
    in >> q;
    getColor(q);
    current.right.h = q;
    in >> q;
    getColor(q);
    current.right.i = q;

    in >> q;
    getColor(q);
    current.up.a = q;
    in >> q;
    getColor(q);
    current.up.b = q;
    in >> q;
    getColor(q);
    current.up.c = q;
    in >> q;
    getColor(q);
    current.up.d = q;
    in >> q;
    getColor(q);
    current.up.e = q;
    in >> q;
    getColor(q);
    current.up.f = q;
    in >> q;
    getColor(q);
    current.up.g = q;
    in >> q;
    getColor(q);
    current.up.h = q;
    in >> q;
    getColor(q);
    current.up.i = q;

    in >> q;
    getColor(q);
    current.down.a = q;
    in >> q;
    getColor(q);
    current.down.b = q;
    in >> q;
    getColor(q);
    current.down.c = q;
    in >> q;
    getColor(q);
    current.down.d = q;
    in >> q;
    getColor(q);
    current.down.e = q;
    in >> q;
    getColor(q);
    current.down.f = q;
    in >> q;
    getColor(q);
    current.down.g = q;
    in >> q;
    getColor(q);
    current.down.h = q;
    in >> q;
    getColor(q);
    current.down.i = q;
}

void show(instructions &current)
{
    out << endl;
    out << current.front.a << current.front.b << current.front.c << current.front.d << current.front.e
        << current.front.f << current.front.g << current.front.h << current.front.i << endl;

    out << current.back.a << current.back.b << current.back.c << current.back.d << current.back.e
        << current.back.f << current.back.g << current.back.h << current.back.i << endl;

    out << current.left.a << current.left.b << current.left.c << current.left.d << current.left.e
        << current.left.f << current.left.g << current.left.h << current.left.i << endl;

    out << current.right.a << current.right.b << current.right.c << current.right.d << current.right.e
        << current.right.f << current.right.g << current.right.h << current.right.i << endl;

    out << current.up.a << current.up.b << current.up.c << current.up.d << current.up.e
        << current.up.f << current.up.g << current.up.h << current.up.i << endl;

    out << current.down.a << current.down.b << current.down.c << current.down.d << current.down.e
        << current.down.f << current.down.g << current.down.h << current.down.i << endl;
}

bool checking(instructions &current)
{
    //сохранение расположения центров - напротив белого - желтый
    //синего - зеленый
    // красного - оранжевый
    if (current.front.e == 'R' && current.back.e == 'O' && current.up.e == 'Y' && current.down.e == 'W' && current.left.e == 'B' && current.right.e == 'G')
    {
    }
    else
        return false;

    //проверка на соответствие количества цветов в кубике
    for (int i : Color)
        if (i != 9)
            return false;

    return true;
}

void random(instructions &current)
{
    srand((unsigned)time(NULL));
    int comandsCount = rand() % 10 + 1;
    int comands[comandsCount];

    cout << "NEW CUBE CREATING " << endl;

    for (int i = 0; i < comandsCount; ++i)
    {
        comands[i] = rand() % 12 + 1;
        if (comands[i] == 1)
            current.RightRotate();
        else if (comands[i] == 2)
            current.RightHatchRotate();
        else if (comands[i] == 3)
            current.LeftRotate();
        else if (comands[i] == 4)
            current.LeftHatchRotate();
        else if (comands[i] == 5)
            current.UpRotate();
        else if (comands[i] == 6)
            current.UpHatchRotate();
        else if (comands[i] == 7)
            current.DownRotate();
        else if (comands[i] == 8)
            current.DownHatchRotate();
        else if (comands[i] == 9)
            current.BackRotate();
        else if (comands[i] == 10)
            current.BackHatchRotate();
        else if (comands[i] == 11)
            current.FrontRotate();
        else if (comands[i] == 12)
            current.FrontHatchRotate();
    }
}

bool cornerCheck(instructions &current)
{
    return ((current.up.i == 'Y' && current.front.c == 'R' && current.right.a == 'G') || (current.up.i == 'Y' && current.front.c == 'G' && current.right.a == 'R') || (current.up.i == 'R' && current.front.c == 'Y' && current.right.a == 'G') || (current.up.i == 'R' && current.front.c == 'G' && current.right.a == 'Y') || (current.up.i == 'G' && current.front.c == 'R' && current.right.a == 'Y') || (current.up.i == 'G' && current.front.c == 'Y' && current.right.a == 'R')) && ((current.front.a == 'R' && current.left.c == 'B' && current.up.g == 'Y') || (current.front.a == 'R' && current.left.c == 'Y' && current.up.g == 'B') || (current.front.a == 'B' && current.left.c == 'Y' && current.up.g == 'R') || (current.front.a == 'B' && current.left.c == 'R' && current.up.g == 'Y') || (current.front.a == 'Y' && current.left.c == 'B' && current.up.g == 'R') || (current.front.a == 'Y' && current.left.c == 'R' && current.up.g == 'B')) && ((current.up.c == 'Y' && current.right.c == 'G' && current.back.i == 'O') || (current.up.c == 'Y' && current.right.c == 'O' && current.back.i == 'G') || (current.up.c == 'G' && current.right.c == 'Y' && current.back.i == 'O') || (current.up.c == 'G' && current.right.c == 'O' && current.back.i == 'Y') || (current.up.c == 'O' && current.right.c == 'G' && current.back.i == 'Y') || (current.up.c == 'O' && current.right.c == 'Y' && current.back.i == 'G')) && ((current.up.a == 'Y' && current.back.g == 'O' && current.left.a == 'B') || (current.up.a == 'Y' && current.back.g == 'B' && current.left.a == 'O') || (current.up.a == 'B' && current.back.g == 'O' && current.left.a == 'Y') || (current.up.a == 'B' && current.back.g == 'Y' && current.left.a == 'O') || (current.up.a == 'O' && current.back.g == 'Y' && current.left.a == 'B') || (current.up.a == 'O' && current.back.g == 'B' && current.left.a == 'Y'));
}

bool oneCornerCheck(instructions &current)
{
    return ((current.up.i == 'Y' && current.front.c == 'R' && current.right.a == 'G') ||
            (current.up.i == 'Y' && current.front.c == 'G' && current.right.a == 'R') || (current.up.i == 'R' && current.front.c == 'Y' && current.right.a == 'G') ||
            (current.up.i == 'R' && current.front.c == 'G' && current.right.a == 'Y') || (current.up.i == 'G' && current.front.c == 'R' && current.right.a == 'Y') ||
            (current.up.i == 'G' && current.front.c == 'Y' && current.right.a == 'R')) ||
           ((current.front.a == 'R' && current.left.c == 'B' && current.up.g == 'Y') ||
            (current.front.a == 'R' && current.left.c == 'Y' && current.up.g == 'B') || (current.front.a == 'B' && current.left.c == 'Y' && current.up.g == 'R') ||
            (current.front.a == 'B' && current.left.c == 'R' && current.up.g == 'Y') || (current.front.a == 'Y' && current.left.c == 'B' && current.up.g == 'R') ||
            (current.front.a == 'Y' && current.left.c == 'R' && current.up.g == 'B')) ||
           ((current.up.c == 'Y' && current.right.c == 'G' && current.back.i == 'O') ||
            (current.up.c == 'Y' && current.right.c == 'O' && current.back.i == 'G') || (current.up.c == 'G' && current.right.c == 'Y' && current.back.i == 'O') ||
            (current.up.c == 'G' && current.right.c == 'O' && current.back.i == 'Y') || (current.up.c == 'O' && current.right.c == 'G' && current.back.i == 'Y') ||
            (current.up.c == 'O' && current.right.c == 'Y' && current.back.i == 'G')) ||
           ((current.up.a == 'Y' && current.back.g == 'O' && current.left.a == 'B') ||
            (current.up.a == 'Y' && current.back.g == 'B' && current.left.a == 'O') || (current.up.a == 'B' && current.back.g == 'O' && current.left.a == 'Y') ||
            (current.up.a == 'B' && current.back.g == 'Y' && current.left.a == 'O') || (current.up.a == 'O' && current.back.g == 'Y' && current.left.a == 'B') ||
            (current.up.a == 'O' && current.back.g == 'B' && current.left.a == 'Y'));
}

bool isFull(instructions &current)
{
    return current.front.a == 'R' && current.front.b == 'R' && current.front.c == 'R' && current.front.d == 'R' && current.front.e == 'R' &&
           current.front.f == 'R' && current.front.g == 'R' && current.front.h == 'R' && current.front.i == 'R' &&
           current.back.a == 'O' && current.back.b == 'O' && current.back.c == 'O' && current.back.d == 'O' && current.back.e == 'O' &&
           current.back.f == 'O' && current.back.g == 'O' && current.back.h == 'O' && current.back.i == 'O' &&
           current.right.a == 'G' && current.right.b == 'G' && current.right.c == 'G' && current.right.d == 'G' && current.right.e == 'G' &&
           current.right.f == 'G' && current.right.g == 'G' && current.right.h == 'G' && current.right.i == 'G' &&
           current.left.a == 'B' && current.left.b == 'B' && current.left.c == 'B' && current.left.d == 'B' && current.left.e == 'B' &&
           current.left.f == 'B' && current.left.g == 'B' && current.left.h == 'B' && current.left.i == 'B' &&
           current.up.a == 'Y' && current.up.b == 'Y' && current.up.c == 'Y' && current.up.d == 'Y' && current.up.e == 'Y' &&
           current.up.f == 'Y' && current.up.g == 'Y' && current.up.h == 'Y' && current.up.i == 'Y' &&
           current.down.a == 'W' && current.down.b == 'W' && current.down.c == 'W' && current.down.d == 'W' && current.down.e == 'W' &&
           current.down.f == 'W' && current.down.g == 'W' && current.down.h == 'W' && current.down.i == 'W';
}

int main()
{
    instructions current{};

    read(current);
    random(current);

    if (checking(current))
        cout << "EVERYTHING IS CORRECT" << endl;
    else
    {
        cout << "INPUT IS NOT CORRECT" << endl;
        return 1;
    }

    show(current);
    out << "START TO SOLVE: " << endl;

    //собираем "цветок"
    while (current.up.b != 'W' || current.up.d != 'W' || current.up.f != 'W' || current.up.h != 'W')
    {
        if (current.front.f == 'W')
        {
            while (current.up.f == 'W')
                current.UpRotate();
            current.RightRotate();
        }

        if (current.front.d == 'W')
        {
            while (current.up.d == 'W')
                current.UpRotate();
            current.LeftHatchRotate();
        }

        if (current.right.d == 'W')
        {
            while (current.up.h == 'W')
            {
                current.UpRotate();
            }
            current.FrontHatchRotate();
        }

        if (current.right.f == 'W')
        {
            while (current.up.b == 'W')
                current.UpRotate();
            current.BackRotate();
        }

        if (current.left.f == 'W')
        {
            while (current.up.h == 'W')
                current.UpRotate();
            current.FrontRotate();
        }

        if (current.left.d == 'W')
        {
            while (current.up.b == 'W')
                current.UpRotate();
            current.BackHatchRotate();
        }

        if (current.back.f == 'W')
        {
            while (current.up.f == 'W')
                current.UpRotate();
            current.RightHatchRotate();
        }

        if (current.back.d == 'W')
        {
            while (current.up.d == 'W')
                current.UpRotate();
            current.LeftRotate();
        }

        if (current.down.f == 'W')
        {
            while (current.up.f == 'W')
                current.UpRotate();
            current.RightRotate();
            current.RightRotate();
        }

        if (current.down.h == 'W')
        {
            while (current.up.b == 'W')
                current.UpRotate();
            current.BackHatchRotate();
            current.BackHatchRotate();
        }

        if (current.down.d == 'W')
        {
            while (current.up.d == 'W')
                current.UpRotate();
            current.LeftHatchRotate();
            current.LeftHatchRotate();
        }

        if (current.down.b == 'W')
        {
            while (current.up.h == 'W')
                current.UpRotate();
            current.FrontRotate();
            current.FrontRotate();
        }

        if (current.front.h == 'W')
        {
            current.FrontRotate();
            while (current.up.d == 'W')
                current.UpRotate();
            current.LeftHatchRotate();
        }

        if (current.front.b == 'W')
        {
            current.FrontRotate();
            while (current.up.f == 'W')
                current.UpRotate();
            current.RightRotate();
        }

        if (current.right.h == 'W')
        {
            current.RightRotate();
            while (current.up.h == 'W')
                current.UpRotate();
            current.FrontHatchRotate();
        }

        if (current.right.b == 'W')
        {
            current.RightRotate();
            while (current.up.b == 'W')
                current.UpRotate();
            current.BackRotate();
        }

        if (current.back.b == 'W')
        {
            current.BackHatchRotate();
            while (current.up.d == 'W')
                current.UpRotate();
            current.LeftRotate();
        }

        if (current.back.h == 'W')
        {
            current.BackHatchRotate();
            while (current.up.f == 'W')
                current.UpRotate();
            current.RightHatchRotate();
        }

        if (current.left.h == 'W')
        {
            current.LeftHatchRotate();
            while (current.up.h == 'W')
                current.UpRotate();
            current.FrontRotate();
        }

        if (current.left.b == 'W')
        {
            current.LeftHatchRotate();
            while (current.up.b == 'W')
                current.UpRotate();
            current.BackHatchRotate();
        }
    }

    //правильный крест
    while (current.front.b != current.front.e || current.up.h != 'W')
        current.UpRotate();
    current.FrontRotate();
    current.FrontRotate();

    while (current.right.b != current.right.e || current.up.f != 'W')
        current.UpRotate();
    current.RightRotate();
    current.RightRotate();

    while (current.back.h != current.back.e || current.up.b != 'W')
        current.UpRotate();
    current.BackRotate();
    current.BackRotate();

    while (current.left.b != current.left.e || current.up.d != 'W')
        current.UpRotate();
    current.LeftRotate();
    current.LeftRotate();

    //первый слой
    //сбор уголков первого слоя, которые дополнят построенный крест
    while (current.down.a != 'W' || current.down.c != 'W' || current.down.g != 'W' || current.down.i != 'W')
    {
        //случай первого угла
        if (current.back.i == 'W')
        {
            if ((current.up.c == 'G' && current.right.c == 'O') || (current.up.c == 'O' && current.right.c == 'G'))
            {
                while (current.down.i != 'W' || current.right.i != 'G' || current.back.c != 'O')
                {
                    current.BackRotate();
                    current.UpRotate();
                    current.BackHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.up.c == 'G' && current.right.c == 'R' && current.back.i == 'W') || (current.up.c == 'R' && current.right.c == 'G' && current.back.i == 'W'))
            {
                current.UpRotate();
                while (current.down.c != 'W' || current.front.i != 'R' || current.right.g != 'G')
                {
                    current.RightRotate();
                    current.UpRotate();
                    current.RightHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.up.c == 'R' && current.right.c == 'B' && current.back.i == 'W') || (current.up.c == 'B' && current.right.c == 'R' && current.back.i == 'W'))
            {
                current.UpRotate();
                current.UpRotate();
                while (current.down.a != 'W' || current.left.i != 'B' || current.front.g != 'R')
                {
                    current.FrontRotate();
                    current.UpRotate();
                    current.FrontHatchRotate();
                    current.UpHatchRotate();
                }
            }
            if ((current.up.c == 'B' && current.right.c == 'O' && current.back.i == 'W') || (current.up.c == 'O' && current.right.c == 'B' && current.back.i == 'W'))
            {
                current.UpHatchRotate();
                while (current.down.g != 'W' || current.back.a != 'O' || current.left.g != 'B')
                {
                    current.LeftRotate();
                    current.UpRotate();
                    current.LeftHatchRotate();
                    current.UpHatchRotate();
                }
            }
        }

        if (current.up.c == 'W')
        {
            if ((current.back.i == 'G' && current.right.c == 'O') || (current.back.i == 'O' && current.right.c == 'G'))
            {
                while (current.down.i != 'W' || current.right.i != 'G' || current.back.c != 'O')
                {
                    current.BackRotate();
                    current.UpRotate();
                    current.BackHatchRotate();
                    current.UpHatchRotate();
                }
            }
            if ((current.back.i == 'G' && current.right.c == 'R' && current.up.c == 'W') || (current.back.i == 'R' && current.right.c == 'G' && current.up.c == 'W'))
            {
                current.UpRotate();
                while (current.down.c != 'W' || current.front.i != 'R' || current.right.g != 'G')
                {
                    current.RightRotate();
                    current.UpRotate();
                    current.RightHatchRotate();
                    current.UpHatchRotate();
                }
            }
            if ((current.back.i == 'R' && current.right.c == 'B' && current.up.c == 'W') || (current.back.i == 'B' && current.right.c == 'R' && current.up.c == 'W'))
            {
                current.UpRotate();
                current.UpRotate();
                while (current.down.a != 'W' || current.left.i != 'B' || current.front.g != 'R')
                {
                    current.FrontRotate();
                    current.UpRotate();
                    current.FrontHatchRotate();
                    current.UpHatchRotate();
                }
            }
            if ((current.back.i == 'B' && current.right.c == 'O' && current.up.c == 'W') || (current.back.i == 'O' && current.right.c == 'B' && current.up.c == 'W'))
            {
                current.UpHatchRotate();
                while (current.down.g != 'W' || current.back.a != 'O' || current.left.g != 'B')
                {
                    current.LeftRotate();
                    current.UpRotate();
                    current.LeftHatchRotate();
                    current.UpHatchRotate();
                }
            }
        }

        if (current.right.c == 'W')
        {
            if ((current.up.c == 'G' && current.back.i == 'O') || (current.up.c == 'O' && current.back.i == 'G'))
            {
                while (current.down.i != 'W' || current.right.i != 'G' || current.back.c != 'O')
                {
                    current.BackRotate();
                    current.UpRotate();
                    current.BackHatchRotate();
                    current.UpHatchRotate();
                }
            }
            if ((current.up.c == 'G' && current.back.i == 'R' && current.right.c == 'W') || (current.up.c == 'R' && current.back.i == 'G' && current.right.c == 'W'))
            {
                current.UpRotate();
                while (current.down.c != 'W' || current.front.i != 'R' || current.right.g != 'G')
                {
                    current.RightRotate();
                    current.UpRotate();
                    current.RightHatchRotate();
                    current.UpHatchRotate();
                }
            }
            if ((current.up.c == 'R' && current.back.i == 'B' && current.right.c == 'W') || (current.up.c == 'B' && current.back.i == 'R' && current.right.c == 'W'))
            {
                current.UpRotate();
                current.UpRotate();
                while (current.down.a != 'W' || current.left.i != 'B' || current.front.g != 'R')
                {
                    current.FrontRotate();
                    current.UpRotate();
                    current.FrontHatchRotate();
                    current.UpHatchRotate();
                }
            }
            if ((current.up.c == 'B' && current.back.i == 'O' && current.right.c == 'W') || (current.up.c == 'O' && current.back.i == 'B' && current.right.c == 'W'))
            {
                current.UpHatchRotate();
                while (current.down.g != 'W' || current.back.a != 'O' || current.left.g != 'B')
                {
                    current.LeftRotate();
                    current.UpRotate();
                    current.LeftHatchRotate();
                    current.UpHatchRotate();
                }
            }
        }
        //второй угол
        if (current.back.g == 'W')
        {
            if ((current.up.a == 'G' && current.left.a == 'O') || (current.up.a == 'O' && current.left.a == 'G'))
            {
                current.UpRotate();
                while (current.down.i != 'W' || current.right.i != 'G' || current.back.c != 'O')
                {
                    current.BackRotate();
                    current.UpRotate();
                    current.BackHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.up.a == 'G' && current.left.a == 'R' && current.back.g == 'W') || (current.up.a == 'R' && current.left.a == 'G' && current.back.g == 'W'))
            {
                current.UpRotate();
                current.UpRotate();
                while (current.down.c != 'W' || current.front.i != 'G' || current.right.g != 'G')
                {
                    current.RightRotate();
                    current.UpRotate();
                    current.RightHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.up.a == 'R' && current.left.a == 'B' && current.back.g == 'W') || (current.up.a == 'B' && current.left.a == 'R' && current.back.g == 'W'))
            {
                current.UpHatchRotate();
                while (current.down.a != 'W' || current.left.i != 'B' || current.front.g != 'R')
                {
                    current.FrontRotate();
                    current.UpRotate();
                    current.FrontHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.up.a == 'B' && current.left.a == 'O' && current.back.g == 'W') || (current.up.a == 'O' && current.left.a == 'B' && current.back.g == 'W'))
            {
                while (current.down.g != 'W' || current.back.a != 'O' || current.left.g != 'B')
                {
                    current.LeftRotate();
                    current.UpRotate();
                    current.LeftHatchRotate();
                    current.UpHatchRotate();
                }
            }
        }

        if (current.up.a == 'W')
        {
            if ((current.back.g == 'G' && current.left.a == 'O') || (current.back.g == 'O' && current.left.a == 'G'))
            {
                current.UpRotate();
                while (current.down.i != 'W' || current.right.i != 'G' || current.back.c != 'O')
                {
                    current.BackRotate();
                    current.UpRotate();
                    current.BackHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.back.g == 'G' && current.left.a == 'R' && current.up.a == 'W') || (current.back.g == 'R' && current.left.a == 'G' && current.up.a == 'W'))
            {
                current.UpRotate();
                current.UpRotate();
                while (current.down.c != 'W' || current.front.i != 'R' || current.right.g != 'G')
                {
                    current.RightRotate();
                    current.UpRotate();
                    current.RightHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.back.g == 'R' && current.left.a == 'B' && current.up.a == 'W') || (current.back.g == 'B' && current.left.a == 'R' && current.up.a == 'W'))
            {
                current.UpHatchRotate();
                while (current.down.a != 'W' || current.left.i != 'B' || current.front.g != 'R')
                {
                    current.FrontRotate();
                    current.UpRotate();
                    current.FrontHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.back.g == 'B' && current.left.a == 'O' && current.up.a == 'W') || (current.back.g == 'O' && current.left.a == 'B' && current.up.a == 'W'))
            {
                while (current.down.g != 'W' || current.back.a != 'O' || current.left.g != 'B')
                {
                    current.LeftRotate();
                    current.UpRotate();
                    current.LeftHatchRotate();
                    current.UpHatchRotate();
                }
            }
        }

        if (current.left.a == 'W')
        {
            if ((current.up.a == 'G' && current.back.g == 'O') || (current.up.a == 'O' && current.back.g == 'G'))
            {
                current.UpRotate();
                while (current.down.i != 'W' || current.right.i != 'G' || current.back.c != 'O')
                {
                    current.BackRotate();
                    current.UpRotate();
                    current.BackHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.up.a == 'G' && current.back.g == 'R' && current.left.a == 'W') || (current.up.a == 'R' && current.back.g == 'G' && current.left.a == 'W'))
            {
                current.UpRotate();
                current.UpRotate();
                while (current.down.c != 'W' || current.front.i != 'R' || current.right.g != 'G')
                {
                    current.RightRotate();
                    current.UpRotate();
                    current.RightHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.up.a == 'R' && current.back.g == 'B' && current.left.a == 'W') || (current.up.a == 'B' && current.back.g == 'R' && current.left.a == 'W'))
            {
                current.UpHatchRotate();
                while (current.down.a != 'W' || current.left.i != 'B' || current.front.g != 'R')
                {
                    current.FrontRotate();
                    current.UpRotate();
                    current.FrontHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.up.a == 'B' && current.back.g == 'O' && current.left.a == 'W') || (current.up.a == 'O' && current.back.g == 'B' && current.left.a == 'W'))
            {
                while (current.down.g != 'W' || current.back.a != 'O' || current.left.g != 'B')
                {
                    current.LeftRotate();
                    current.UpRotate();
                    current.LeftHatchRotate();
                    current.UpHatchRotate();
                }
            }
        }

        //третий угол
        if (current.front.a == 'W')
        {
            if ((current.up.g == 'G' && current.left.c == 'O') || (current.up.g == 'O' && current.left.c == 'G'))
            {
                current.UpRotate();
                current.UpRotate();
                while (current.down.i != 'W' || current.right.i != 'G' || current.back.c != 'O')
                {
                    current.BackRotate();
                    current.UpRotate();
                    current.BackHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.up.g == 'G' && current.left.c == 'R' && current.front.a == 'W') || (current.up.g == 'R' && current.left.c == 'G' && current.front.a == 'W'))
            {
                current.UpHatchRotate();
                while (current.down.c != 'W' || current.front.i != 'R' || current.right.g != 'G')
                {
                    current.RightRotate();
                    current.UpRotate();
                    current.RightHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.up.g == 'R' && current.left.c == 'B' && current.front.a == 'W') || (current.up.g == 'B' && current.left.c == 'R' && current.front.a == 'W'))
            {
                while (current.down.a != 'W' || current.left.i != 'B' || current.front.g != 'R')
                {
                    current.FrontRotate();
                    current.UpRotate();
                    current.FrontHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.up.g == 'B' && current.left.c == 'O' && current.front.a == 'W') || (current.up.g == 'O' && current.left.c == 'B' && current.front.a == 'W'))
            {
                current.UpRotate();
                while (current.down.g != 'W' || current.back.a != 'O' || current.left.g != 'B')
                {
                    current.LeftRotate();
                    current.UpRotate();
                    current.LeftHatchRotate();
                    current.UpHatchRotate();
                }
            }
        }

        if (current.up.g == 'W')
        {
            if ((current.front.a == 'G' && current.left.c == 'O') || (current.front.a == 'O' && current.left.c == 'G'))
            {
                current.UpRotate();
                current.UpRotate();
                while (current.down.i != 'W' || current.right.i != 'G' || current.back.c != 'O')
                {
                    current.BackRotate();
                    current.UpRotate();
                    current.BackHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.front.a == 'G' && current.left.c == 'R' && current.up.g == 'W') || (current.front.a == 'R' && current.left.c == 'G' && current.up.g == 'W'))
            {
                current.UpHatchRotate();
                while (current.down.c != 'W' || current.front.i != 'R' || current.right.g != 'G')
                {
                    current.RightRotate();
                    current.UpRotate();
                    current.RightHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.front.a == 'R' && current.left.c == 'B' && current.up.g == 'W') || (current.front.a == 'B' && current.left.c == 'R' && current.up.g == 'W'))
            {
                while (current.down.a != 'W' || current.left.i != 'B' || current.front.g != 'R')
                {
                    current.FrontRotate();
                    current.UpRotate();
                    current.FrontHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.front.a == 'B' && current.left.c == 'O' && current.up.g == 'W') || (current.front.a == 'O' && current.left.c == 'B' && current.up.g == 'W'))
            {
                current.UpRotate();
                while (current.down.g != 'W' || current.back.a != 'O' || current.left.g != 'B')
                {
                    current.LeftRotate();
                    current.UpRotate();
                    current.LeftHatchRotate();
                    current.UpHatchRotate();
                }
            }
        }

        if (current.left.c == 'W')
        {
            if ((current.up.g == 'G' && current.front.a == 'O') || (current.up.g == 'O' && current.front.a == 'G'))
            {
                current.UpRotate();
                current.UpRotate();
                while (current.down.i != 'W' || current.right.i != 'G' || current.back.c != 'O')
                {
                    current.BackRotate();
                    current.UpRotate();
                    current.BackHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.up.g == 'G' && current.front.a == 'R' && current.left.c == 'W') || (current.up.g == 'R' && current.front.a == 'G' && current.left.c == 'W'))
            {
                current.UpHatchRotate();
                while (current.down.c != 'W' || current.front.i != 'R' || current.right.g != 'G')
                {
                    current.RightRotate();
                    current.UpRotate();
                    current.RightHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.up.g == 'R' && current.front.a == 'B' && current.left.c == 'W') || (current.up.g == 'B' && current.front.a == 'R' && current.left.c == 'W'))
            {
                while (current.down.a != 'W' || current.left.i != 'B' || current.front.g != 'R')
                {
                    current.FrontRotate();
                    current.UpRotate();
                    current.FrontHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.up.g == 'B' && current.front.a == 'O' && current.left.c == 'W') || (current.up.g == 'O' && current.front.a == 'B' && current.left.c == 'W'))
            {
                current.UpRotate();
                while (current.down.g != 'W' || current.back.a != 'O' || current.left.g != 'B')
                {
                    current.LeftRotate();
                    current.UpRotate();
                    current.LeftHatchRotate();
                    current.UpHatchRotate();
                }
            }
        }
        //четвертый угол
        if (current.front.c == 'W')
        {
            if ((current.up.i == 'G' && current.right.a == 'O') || (current.up.i == 'O' && current.right.a == 'G'))
            {
                current.UpHatchRotate();
                while (current.down.i != 'W' || current.right.i != 'G' || current.back.c != 'O')
                {
                    current.BackRotate();
                    current.UpRotate();
                    current.BackHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.up.i == 'G' && current.right.a == 'R' && current.front.c == 'W') || (current.up.i == 'R' && current.right.a == 'G' && current.front.c == 'W'))
            {
                while (current.down.c != 'W' || current.front.i != 'R' || current.right.g != 'G')
                {
                    current.RightRotate();
                    current.UpRotate();
                    current.RightHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.up.i == 'R' && current.right.a == 'B' && current.front.c == 'W') || (current.up.i == 'B' && current.right.a == 'R' && current.front.c == 'W'))
            {
                current.UpRotate();
                while (current.down.a != 'W' || current.left.i != 'B' || current.front.g != 'R')
                {
                    current.FrontRotate();
                    current.UpRotate();
                    current.FrontHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.up.i == 'B' && current.right.a == 'O' && current.front.c == 'W') || (current.up.i == 'O' && current.right.a == 'B' && current.front.c == 'W'))
            {
                current.UpRotate();
                current.UpRotate();
                while (current.down.g != 'W' || current.back.a != 'O' || current.left.g != 'B')
                {
                    current.LeftRotate();
                    current.UpRotate();
                    current.LeftHatchRotate();
                    current.UpHatchRotate();
                }
            }
        }

        if (current.up.i == 'W')
        {
            if ((current.front.c == 'G' && current.right.a == 'O') || (current.front.c == 'O' && current.right.a == 'G'))
            {
                current.UpHatchRotate();
                while (current.down.i != 'W' || current.right.i != 'G' || current.back.c != 'O')
                {
                    current.BackRotate();
                    current.UpRotate();
                    current.BackHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.front.c == 'G' && current.right.a == 'R' && current.up.i == 'W') || (current.front.c == 'R' && current.right.a == 'G' && current.up.i == 'W'))
            {
                while (current.down.c != 'W' || current.front.i != 'R' || current.right.g != 'G')
                {
                    current.RightRotate();
                    current.UpRotate();
                    current.RightHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.front.c == 'R' && current.right.a == 'B' && current.up.i == 'W') || (current.front.c == 'B' && current.right.a == 'R' && current.up.i == 'W'))
            {
                current.UpRotate();
                while (current.down.a != 'W' || current.left.i != 'B' || current.front.g != 'R')
                {
                    current.FrontRotate();
                    current.UpRotate();
                    current.FrontHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.front.c == 'B' && current.right.a == 'O' && current.up.i == 'W') || (current.front.c == 'O' && current.right.a == 'B' && current.up.i == 'W'))
            {
                current.UpRotate();
                current.UpRotate();
                while (current.down.g != 'W' || current.back.a != 'O' || current.left.g != 'B')
                {
                    current.LeftRotate();
                    current.UpRotate();
                    current.LeftHatchRotate();
                    current.UpHatchRotate();
                }
            }
        }

        if (current.right.a == 'W')
        {
            if ((current.front.c == 'G' && current.up.i == 'O' && current.right.a == 'W') || (current.front.c == 'O' && current.up.i == 'G' && current.right.a == 'W'))
            {
                current.UpHatchRotate();
                while (current.down.i != 'W' || current.right.i != 'G' || current.back.c != 'O')
                {
                    current.BackRotate();
                    current.UpRotate();
                    current.BackHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.front.c == 'G' && current.up.i == 'R' && current.right.a == 'W') || (current.front.c == 'R' && current.up.i == 'G' && current.right.a == 'W'))
            {
                while (current.down.c != 'W' || current.front.i != 'R' || current.right.g != 'G')
                {
                    current.RightRotate();
                    current.UpRotate();
                    current.RightHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.front.c == 'R' && current.up.i == 'B' && current.right.a == 'W') || (current.front.c == 'B' && current.up.i == 'R' && current.right.a == 'W'))
            {
                current.UpRotate();
                while (current.down.a != 'W' || current.left.i != 'B' || current.front.g != 'R')
                {
                    current.FrontRotate();
                    current.UpRotate();
                    current.FrontHatchRotate();
                    current.UpHatchRotate();
                }
            }

            if ((current.front.c == 'B' && current.up.i == 'O' && current.right.a == 'W') || (current.front.c == 'O' && current.up.i == 'B' && current.right.a == 'W'))
            {
                current.UpRotate();
                current.UpRotate();
                while (current.down.g != 'W' || current.back.a != 'O' || current.left.g != 'B')
                {
                    current.LeftRotate();
                    current.UpRotate();
                    current.LeftHatchRotate();
                    current.UpHatchRotate();
                }
            }
        }

        if ((current.front.i == 'W' && current.right.g == 'G' && current.down.c == 'R') || (current.front.i == 'W' && current.right.g == 'R' && current.down.c == 'G') ||
            (current.front.i == 'G' && current.right.g == 'W' && current.down.c == 'R') || (current.front.i == 'R' && current.right.g == 'W' && current.down.c == 'G') ||
            (current.front.i == 'G' && current.right.g == 'R' && current.down.c == 'W'))
        {
            while (current.down.c != 'W' || current.front.i != 'R' || current.right.g != 'G')
            {
                current.RightRotate();
                current.UpRotate();
                current.RightHatchRotate();
                current.UpHatchRotate();
            }
        }
        if ((current.back.c == 'W' && current.right.i == 'G' && current.down.i == 'O') || (current.back.c == 'W' && current.right.i == 'O' && current.down.i == 'G') ||
            (current.back.c == 'G' && current.right.i == 'W' && current.down.i == 'O') || (current.back.c == 'O' && current.right.i == 'W' && current.down.i == 'G') ||
            (current.back.c == 'G' && current.right.i == 'O' && current.down.i == 'W'))
        {
            while (current.down.i != 'W' || current.back.c != 'O' || current.right.i != 'G')
            {
                current.BackRotate();
                current.UpRotate();
                current.BackHatchRotate();
                current.UpHatchRotate();
            }
        }
        if ((current.back.a == 'W' && current.left.g == 'B' && current.down.g == 'O') || (current.back.a == 'W' && current.left.g == 'O' && current.down.g == 'B') ||
            (current.back.a == 'B' && current.left.g == 'W' && current.down.g == 'O') || (current.back.a == 'O' && current.left.g == 'W' && current.down.g == 'B') ||
            (current.back.a == 'B' && current.left.g == 'O' && current.down.g == 'W'))
        {
            while (current.down.g != 'W' || current.back.a != 'O' || current.left.g != 'B')
            {
                current.LeftRotate();
                current.UpRotate();
                current.LeftHatchRotate();
                current.UpHatchRotate();
            }
        }
        if ((current.left.i == 'W' && current.front.g == 'R' && current.down.a == 'B') || (current.left.i == 'W' && current.front.g == 'B' && current.down.a == 'R') ||
            (current.left.i == 'R' && current.front.g == 'W' && current.down.a == 'B') || (current.left.i == 'B' && current.front.g == 'W' && current.down.a == 'R') ||
            (current.left.i == 'R' && current.front.g == 'B' && current.down.a == 'W'))
        {
            while (current.down.a != 'W' || current.left.i != 'B' || current.front.g != 'R')
            {
                current.FrontRotate();
                current.UpRotate();
                current.FrontHatchRotate();
                current.UpHatchRotate();
            }
        }

        if ((current.down.c == 'W' && (current.front.i != 'R' && current.front.i != 'G')) || (current.down.c == 'W' && (current.right.g != 'R' && current.right.g != 'G')))
        {
            current.RightRotate();
            current.UpRotate();
            current.RightHatchRotate();
            current.UpHatchRotate();
        }

        if ((current.down.i == 'W' && (current.right.i != 'O' && current.right.i != 'G')) || (current.down.i == 'W' && (current.back.c != 'O' && current.back.c != 'G')))
        {
            current.BackRotate();
            current.UpRotate();
            current.BackHatchRotate();
            current.UpHatchRotate();
        }

        if ((current.down.g == 'W' && (current.back.a != 'O' && current.back.a != 'B')) || (current.down.g == 'W' && (current.left.g != 'O' && current.left.g != 'B')))
        {
            current.LeftRotate();
            current.UpRotate();
            current.LeftHatchRotate();
            current.UpHatchRotate();
        }

        if ((current.down.a == 'W' && (current.front.g != 'R' && current.front.g != 'B')) || (current.down.a == 'W' && (current.left.i != 'R' && current.left.i != 'B')))
        {
            current.FrontRotate();
            current.UpRotate();
            current.FrontHatchRotate();
            current.UpHatchRotate();
        }
    }
    //средний слой
    int pred;
    while (current.front.d != 'R' || current.front.f != 'R' || current.right.d != 'G' || current.right.f != 'G' ||
           current.back.f != 'O' || current.back.d != 'O' || current.left.d != 'B' || current.left.f != 'B')
    {
        int count = 0;
        pred = -1;
        //сборка двух нижних рядов
        while (count > pred)
        {
            pred = count;
            if (current.front.b == 'R' || current.right.b == 'R' || current.back.h == 'R' || current.left.b == 'R')
            {
                while (current.front.b != 'R')
                    current.UpRotate();
                if (current.up.h == 'G')
                {
                    count++;
                    current.UpRotate();
                    current.RightRotate();
                    current.UpRotate();
                    current.RightHatchRotate();
                    current.UpHatchRotate();
                    current.FrontHatchRotate();
                    current.UpHatchRotate();
                    current.FrontRotate();
                    current.UpRotate();
                }
                else
                {
                    if (current.up.h == 'B')
                    {
                        count++;
                        current.UpHatchRotate();
                        current.LeftHatchRotate();
                        current.UpHatchRotate();
                        current.LeftRotate();
                        current.UpRotate();
                        current.FrontRotate();
                        current.UpRotate();
                        current.FrontHatchRotate();
                        current.UpHatchRotate();
                    }
                }
            }

            if (current.front.b == 'G' || current.right.b == 'G' || current.back.h == 'G' || current.left.b == 'G')
            {
                while (current.right.b != 'G')
                    current.UpRotate();
                if (current.up.f == 'O')
                {
                    count++;
                    current.UpRotate();
                    current.BackRotate();
                    current.UpRotate();
                    current.BackHatchRotate();
                    current.UpHatchRotate();
                    current.RightHatchRotate();
                    current.UpHatchRotate();
                    current.RightRotate();
                    current.UpRotate();
                }
                else
                {
                    if (current.up.f == 'R')
                    {
                        count++;
                        current.UpHatchRotate();
                        current.FrontHatchRotate();
                        current.UpHatchRotate();
                        current.FrontRotate();
                        current.UpRotate();
                        current.RightRotate();
                        current.UpRotate();
                        current.RightHatchRotate();
                        current.UpHatchRotate();
                    }
                }
            }

            if (current.front.b == 'O' || current.right.b == 'O' || current.back.h == 'O' || current.left.b == 'O')
            {
                while (current.back.h != 'O')
                    current.UpRotate();
                if (current.up.b == 'B')
                {
                    count++;
                    current.UpRotate();
                    current.LeftRotate();
                    current.UpRotate();
                    current.LeftHatchRotate();
                    current.UpHatchRotate();
                    current.BackHatchRotate();
                    current.UpHatchRotate();
                    current.BackRotate();
                    current.UpRotate();
                }
                else
                {
                    if (current.up.b == 'G')
                    {
                        count++;
                        current.UpHatchRotate();
                        current.RightHatchRotate();
                        current.UpHatchRotate();
                        current.RightRotate();
                        current.UpRotate();
                        current.BackRotate();
                        current.UpRotate();
                        current.BackHatchRotate();
                        current.UpHatchRotate();
                    }
                }
            }

            if (current.front.b == 'B' || current.right.b == 'B' || current.back.h == 'B' || current.left.b == 'B')
            {
                while (current.left.b != 'B')
                    current.UpRotate();
                if (current.up.d == 'R')
                {
                    count++;
                    current.UpRotate();
                    current.FrontRotate();
                    current.UpRotate();
                    current.FrontHatchRotate();
                    current.UpHatchRotate();
                    current.LeftHatchRotate();
                    current.UpHatchRotate();
                    current.LeftRotate();
                    current.UpRotate();
                }
                else
                {
                    if (current.up.d == 'O')
                    {
                        count++;
                        current.UpHatchRotate();
                        current.BackHatchRotate();
                        current.UpHatchRotate();
                        current.BackRotate();
                        current.UpRotate();
                        current.LeftRotate();
                        current.UpRotate();
                        current.LeftHatchRotate();
                        current.UpHatchRotate();
                    }
                }
            }
        }
        // добавляем ребра из 2 ряда
        if (current.front.f != 'R')
        {
            current.RightRotate();
            current.UpRotate();
            current.RightHatchRotate();
            current.UpHatchRotate();
            current.FrontHatchRotate();
            current.UpHatchRotate();
            current.FrontRotate();
            current.UpRotate();
        }
        if (current.right.f != 'G')
        {
            current.BackRotate();
            current.UpRotate();
            current.BackHatchRotate();
            current.UpHatchRotate();
            current.RightHatchRotate();
            current.UpHatchRotate();
            current.RightRotate();
            current.UpRotate();
        }
        if (current.back.d != 'O')
        {
            current.LeftRotate();
            current.UpRotate();
            current.LeftHatchRotate();
            current.UpHatchRotate();
            current.BackHatchRotate();
            current.UpHatchRotate();
            current.BackRotate();
            current.UpRotate();
        }
        if (current.left.f != 'B')
        {
            current.FrontRotate();
            current.UpRotate();
            current.FrontHatchRotate();
            current.UpHatchRotate();
            current.LeftHatchRotate();
            current.UpHatchRotate();
            current.LeftRotate();
            current.UpRotate();
        }
    }
    //сборка желтого креста
    while (current.up.d != 'Y' || current.up.b != 'Y' || current.up.f != 'Y' || current.up.h != 'Y')
    {
        if ((current.up.f == 'Y' && current.up.b == 'Y') || (current.up.b == 'Y' && current.up.h == 'Y'))
        {
            current.LeftRotate();
            current.FrontRotate();
            current.UpRotate();
            current.FrontHatchRotate();
            current.UpHatchRotate();
            current.LeftHatchRotate();
        }
        else
        {
            if (current.up.f == 'Y' && current.up.h == 'Y')
            {
                current.BackRotate();
                current.LeftRotate();
                current.UpRotate();
                current.LeftHatchRotate();
                current.UpHatchRotate();
                current.BackHatchRotate();
            }
            else
            {
                if (current.up.d == 'Y' && current.up.h == 'Y')
                {
                    current.RightRotate();
                    current.BackRotate();
                    current.UpRotate();
                    current.BackHatchRotate();
                    current.UpHatchRotate();
                    current.RightHatchRotate();
                }
                else
                {
                    current.FrontRotate();
                    current.RightRotate();
                    current.UpRotate();
                    current.RightHatchRotate();
                    current.UpHatchRotate();
                    current.FrontHatchRotate();
                }
            }
        }
    }
    //проверка на правильный желтый крест
    bool checkY = false;
    if (current.front.b == 'R' && current.right.b == 'G' && current.back.h == 'O' && current.left.b == 'B')
        checkY = true;
    else
    {
        current.UpRotate();
        if (current.front.b == 'R' && current.right.b == 'G' && current.back.h == 'O' && current.left.b == 'B')
            checkY = true;
        else
        {
            current.UpRotate();
            if (current.front.b == 'R' && current.right.b == 'G' && current.back.h == 'O' && current.left.b == 'B')
                checkY = true;
            else
            {
                current.UpRotate();
                if (current.front.b == 'R' && current.right.b == 'G' && current.back.h == 'O' && current.left.b == 'B')
                    checkY = true;
            }
        }
    }
    //в случае, если правильый желтый крест не готов :
    if (!checkY)
    {
        while (current.front.b != 'R' || current.right.b != 'G' || current.back.h != 'O' || current.left.b != 'B')
        {
            current.UpRotate();
            if (current.right.b == 'G' && current.back.h == 'O')
            {
                current.RightRotate();
                current.UpRotate();
                current.RightHatchRotate();
                current.UpRotate();
                current.RightRotate();
                current.UpRotate();
                current.UpRotate();
                current.RightHatchRotate();
                current.UpRotate();
                break;
            }
            if (current.right.b == 'G' && current.front.b == 'R')
            {
                current.FrontRotate();
                current.UpRotate();
                current.FrontHatchRotate();
                current.UpRotate();
                current.FrontRotate();
                current.UpRotate();
                current.UpRotate();
                current.FrontHatchRotate();
                current.UpRotate();
                break;
            }
            if (current.front.b == 'R' && current.left.b == 'B')
            {
                current.LeftRotate();
                current.UpRotate();
                current.LeftHatchRotate();
                current.UpRotate();
                current.LeftRotate();
                current.UpRotate();
                current.UpRotate();
                current.LeftHatchRotate();
                current.UpRotate();
                break;
            }
            if (current.left.b == 'B' && current.back.h == 'O')
            {
                current.BackRotate();
                current.UpRotate();
                current.BackHatchRotate();
                current.UpRotate();
                current.BackRotate();
                current.UpRotate();
                current.UpRotate();
                current.BackHatchRotate();
                current.UpRotate();
                break;
            }
            if (current.right.b == 'G' && current.left.b == 'B')
            {
                current.BackRotate();
                current.UpRotate();
                current.BackHatchRotate();
                current.UpRotate();
                current.BackRotate();
                current.UpRotate();
                current.UpRotate();
                current.BackHatchRotate();
            }
            if (current.front.b == 'R' && current.back.h == 'O')
            {
                current.RightRotate();
                current.UpRotate();
                current.RightHatchRotate();
                current.UpRotate();
                current.RightRotate();
                current.UpRotate();
                current.UpRotate();
                current.RightHatchRotate();
            }
        }
    }
    //проверка на правильность расположения углов
    while (!cornerCheck(current))
    {
        if ((current.up.i == 'Y' && current.front.c == 'R' && current.right.a == 'G') || (current.up.i == 'Y' && current.front.c == 'G' && current.right.a == 'R') ||
            (current.up.i == 'R' && current.front.c == 'Y' && current.right.a == 'G') || (current.up.i == 'R' && current.front.c == 'G' && current.right.a == 'Y') ||
            (current.up.i == 'G' && current.front.c == 'R' && current.right.a == 'Y') || (current.up.i == 'G' && current.front.c == 'Y' && current.right.a == 'R'))
        {
            while (!cornerCheck(current))
            {
                current.UpRotate();
                current.RightRotate();
                current.UpHatchRotate();
                current.LeftHatchRotate();
                current.UpRotate();
                current.RightHatchRotate();
                current.UpHatchRotate();
                current.LeftRotate();
            }
        }
        else
        {
            if ((current.front.a == 'R' && current.left.c == 'B' && current.up.g == 'Y') || (current.front.a == 'R' && current.left.c == 'Y' && current.up.g == 'B') ||
                (current.front.a == 'B' && current.left.c == 'Y' && current.up.g == 'R') || (current.front.a == 'B' && current.left.c == 'R' && current.up.g == 'Y') ||
                (current.front.a == 'Y' && current.left.c == 'B' && current.up.g == 'R') || (current.front.a == 'Y' && current.left.c == 'R' && current.up.g == 'B'))
            {
                while (!cornerCheck(current))
                {
                    current.UpRotate();
                    current.FrontRotate();
                    current.UpHatchRotate();
                    current.BackHatchRotate();
                    current.UpRotate();
                    current.FrontHatchRotate();
                    current.UpHatchRotate();
                    current.BackRotate();
                }
            }
            else
            {
                if ((current.up.c == 'Y' && current.right.c == 'G' && current.back.i == 'O') || (current.up.c == 'Y' && current.right.c == 'O' && current.back.i == 'G') ||
                    (current.up.c == 'G' && current.right.c == 'Y' && current.back.i == 'O') || (current.up.c == 'G' && current.right.c == 'O' && current.back.i == 'Y') ||
                    (current.up.c == 'O' && current.right.c == 'G' && current.back.i == 'Y') || (current.up.c == 'O' && current.right.c == 'Y' && current.back.i == 'G'))
                {
                    while (!cornerCheck(current))
                    {
                        current.UpRotate();
                        current.BackRotate();
                        current.UpHatchRotate();
                        current.FrontHatchRotate();
                        current.UpRotate();
                        current.BackHatchRotate();
                        current.UpHatchRotate();
                        current.FrontRotate();
                    }
                }
                else
                {
                    if ((current.up.a == 'Y' && current.back.g == 'O' && current.left.a == 'B') || (current.up.a == 'Y' && current.back.g == 'B' && current.left.a == 'O') ||
                        (current.up.a == 'B' && current.back.g == 'O' && current.left.a == 'Y') || (current.up.a == 'B' && current.back.g == 'Y' && current.left.a == 'O') ||
                        (current.up.a == 'O' && current.back.g == 'Y' && current.left.a == 'B') || (current.up.a == 'O' && current.back.g == 'B' && current.left.a == 'Y'))
                    {
                        while (!cornerCheck(current))
                        {
                            current.UpRotate();
                            current.LeftRotate();
                            current.UpHatchRotate();
                            current.RightHatchRotate();
                            current.UpRotate();
                            current.LeftHatchRotate();
                            current.UpHatchRotate();
                            current.RightRotate();
                        }
                    }
                    else
                    {
                        while (!oneCornerCheck(current))
                        {
                            current.UpRotate();
                            current.RightRotate();
                            current.UpHatchRotate();
                            current.LeftHatchRotate();
                            current.UpRotate();
                            current.RightHatchRotate();
                            current.UpHatchRotate();
                            current.LeftRotate();
                        }
                    }
                }
            }
        }
    }
    //разворот углов
    if (current.up.c != 'Y')
    {
        while (current.up.c != 'Y')
        {
            current.BackRotate();
            current.RightHatchRotate();
            current.BackHatchRotate();
            current.RightRotate();
        }
    }
    current.UpRotate();

    if (current.up.c != 'Y')
    {
        while (current.up.c != 'Y')
        {
            current.BackRotate();
            current.RightHatchRotate();
            current.BackHatchRotate();
            current.RightRotate();
        }
    }
    current.UpRotate();

    if (current.up.c != 'Y')
    {
        while (current.up.c != 'Y')
        {
            current.BackRotate();
            current.RightHatchRotate();
            current.BackHatchRotate();
            current.RightRotate();
        }
    }
    current.UpRotate();

    if (current.up.c != 'Y')
    {
        while (current.up.c != 'Y')
        {
            current.BackRotate();
            current.RightHatchRotate();
            current.BackHatchRotate();
            current.RightRotate();
        }
    }

    while (!isFull(current))
    {
        current.UpRotate();
    }

    show(current);

    return 0;
}