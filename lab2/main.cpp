#include <iostream>
#include "head.h"

using namespace std;
//лабораторная 2
/*Согласно варианту описать указанные классы (варианты распределяются преподавателем лично). Написать программу, использующую
описанные классы: инициализация переменных (ввод пользователя), выполнение действий с экземплярами класса (в зависимости от
дальнейшего ввода пользователя).
Описания и реализация должны находиться в разных файлах. Доступ к полям класса – только через методы. Внешние функции для работы
с данными класса не допускаются.*/
//Вариант 4. Квадратный многочлен
//Конструкторы : По умолчанию. Копирования три вещественных числа. Квадратный многочлен.
//Функциональность : Вычисления значения в заданной точке. Нахождения количества корней. Нахождение корней. Поиск минимума/максимума. Вывод на экран.

class menu {
public:
    void begin() {
        int numb, point;
        start();
        cin >> numb;

        cout << "ENTER THE COEFFICIENTS OF POLYNOMIAL \n";

        double a, b, c;
        cin >> a >> b >> c;
        squarePolynomial s(a, b, c);
        //s = {a, b, c};

        while (numb != 0) {
            switch (numb) {
                case 1 :
                    cout << "ENTER THE POINT \n";
                    cin >> point;
                    cout << s.inPoint(point) << '\n';
                    break;
                case 2 :
                    cout << s.countOfRoots() << '\n';
                    break;
                case 3 :
                    s.rootsInPolynomial();
                    break;
                case 4 :
                    s.maxOrMin();
                    break;
                case 5:
                    s.onScreen();
                    break;
                default:
                    break;
            }
            cout << "CHOOSE ONE ACTION WITH SQUARE POLYNOMIAL: \n ";
            cin >> numb;
        }
    }
};

int main() {
    menu m;
    m.begin();
    return 0;
};