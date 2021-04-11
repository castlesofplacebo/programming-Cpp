#include <iostream>
#include "func.h"
//вариант 22
//задания : 1, 6, 9, 14
using namespace std;

int main() {
    int a, b;
    //1. Меняет значения двух входных переменных друг на друга
    //указатели
    a = 1;
    b = 2;
    cout << "1. Before " << a << '\t' << b << '\n';
    changepointer(&a, &b);
    cout << "After " << a << '\t' << b << '\n';
    //ссылки
    a = 1;
    b = 2;
    cout << "1.1 Before " << a << '\t' << b << '\n';
    changelink(a, b);
    cout << "After " << a << '\t' << b << '\n';

    //6. Округляет вещественное число
    //указатели
    double t = 9.87;
    cout << "2. Before " << t << '\n';
    roundpointer(&t);
    cout << "After " << t << '\n';
    //ссылки
    t = 9.87;
    cout << "2. 2 Before " << t << '\n';
    roundlink(t);
    cout << "After " << t << '\n';

    //9. Умножает комплексную переменную на второй аргумент процедуры – вещественное число
    //указатели
    dots comp = {1, 2};
    t = 2.12;
    cout << "3 Before : real " << comp.re << " imagine " << comp.im << " double " << t << '\n';
    complpointer(&comp.re, &comp.im, &t);
    cout << "After : real " << comp.re << " imagine " << comp.im << " double " << t << '\n';
    //ссылки
    comp = {1, 2};
    t = 2.12;
    cout << "3.1 Before : real " << comp.re << " imagine " << comp.im << " double " << t << '\n';
    compllink(comp.re, comp.im, t);
    cout << "After : real " << comp.re << " imagine " << comp.im << " double " << t << '\n';

    //14. Транспонирует квадратную матрицу 3x3
    //указатели
    matriX m{};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> m.arr[i][j];
        }
    }
    cout << "4 Before : " << '\n';
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << m.arr[i][j] << '\t';
        }
        cout << '\n';
    }
    matrixpointer(&m);
    cout << "After : " << '\n';
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << m.arr[i][j] << '\t';
        }
        cout << '\n';
    }

    //ссылки
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> m.arr[i][j];
        }
    }
    cout << "4 Before : " << '\n';
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << m.arr[i][j] << '\t';
        }
        cout << '\n';
    }
    matrixlink(m);
    cout << "After : " << '\n';
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << m.arr[i][j] << '\t';
        }
        cout << '\n';
    }
    return 0;
}