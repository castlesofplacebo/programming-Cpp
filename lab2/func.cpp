#include "head.h"
#include <iostream>

using namespace std;

//Конструкторы : По умолчанию
squarePolynomial::squarePolynomial()
        : a_(0), b_(0), c_(0) {
}

//Конструкторы :Копирования три вещественных числа
squarePolynomial::squarePolynomial(double a, double b, double c)
        : a_(a), b_(b), c_(c) {
}

squarePolynomial &squarePolynomial::operator=(const squarePolynomial &current) {
    if (this != &current) {
        this->a_ = current.a_;
        this->b_ = current.b_;
        this->c_ = current.c_;
    }
    return *this;
}

//Деструктор
squarePolynomial::~squarePolynomial() = default;

//Функциональность : Вычисления значения в заданной точке
double squarePolynomial::inPoint(double x) {
    return (a_ * x * x) + (b_ * x) + c_;
}

//Функциональность : Нахождения количества корней
unsigned squarePolynomial::countOfRoots() {
    if (((b_ * b_) - (4 * a_ * c_)) > 0)
        return 2;
    else if (((b_ * b_) - (4 * a_ * c_)) == 0)
        return 1;
    else
        return 0;
}

//Функциональность : Нахождение корней
void squarePolynomial::rootsInPolynomial() {
    double d = ((b_ * b_) - (4 * a_ * c_));
    if (d >= 0) {
        if (d == 0)
            cout << -b_ / (2 * a_) << endl;
        else {
            cout << (-b_ + d) / (2 * a_) << '\t';
            cout << (-b_ - d) / (2 * a_) << endl;
        }
    } else cout << "NO REAL ROOTS" << endl;
}

//Функциональность : Нахождение максимума/минимума
void squarePolynomial::maxOrMin() {
    if (a_ == 0)
        cout << "NO MAX OR MIN" << endl;
    else {
        double x = (-b_) / (2 * a_);
        cout << (a_ * x * x + b_ * x + c_) << endl;
    }
}

//Функциональность : Вывод на экран
void squarePolynomial::onScreen() {
    cout << a_ << " * x^2 + " << b_ << " * x + " << c_ << endl;
}

//Конструкторы : Присваивания квадратного многочлена
squarePolynomial::squarePolynomial(const squarePolynomial &s) {
    a_ = s.a_;
    b_ = s.b_;
    c_ = s.c_;
}

void start() {
    cout << "CHOOSE ONE ACTION WITH SQUARE POLYNOMIAL: \n "
         << "1 - CALCULATE A VALUE AT THE POINT \n"
         << "2 - FINDING THE NUMBER OF ROOTS \n"
         << "3 - FINDING THE ROOOTS \n"
         << "4 - FINDING THE EXTREMUMS \n"
         << "5 - OUTPUT POLYNOMIAL ON THE SCREEN \n"
         << "0 - EXIT \n";
}