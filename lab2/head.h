//Конструкторы : По умолчанию. Копирования три вещественных числа. Копирования квадратного многочлен.
//Функциональность : Вычисления значения в заданной точке. Нахождения количества корней. Нахождение корней. Поиск минимума/максимума. Вывод на экран.

#ifndef LAB2_2_HEAD_H
#define LAB2_2_HEAD_H

#include <iostream>

using namespace std;

class squarePolynomial {
public:
    squarePolynomial();

    squarePolynomial(double a, double b, double c);

    squarePolynomial(const squarePolynomial &);

    squarePolynomial &operator=(const squarePolynomial &);

    ~squarePolynomial();

    double inPoint(double);

    unsigned countOfRoots();

    void rootsInPolynomial();

    void maxOrMin();

    void onScreen();

private:
    double a_;
    double b_;
    double c_;
};

void start();

#endif //LAB2_2_HEAD_H
