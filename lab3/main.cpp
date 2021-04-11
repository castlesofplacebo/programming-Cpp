#include <iostream>
#include "head.h"

using namespace std;
//Лабораторная работа No3. Перегрузка операторов.

//Согласно варианту описать указанные типы данных и поместить их в отдельный
//заголовочный файл, в нем же описать операторы, указанные в варианте. Реализацию
//функций поместить с отдельный cpp файл.
//Написать программу, проверяющую правильность работы – для наглядности и лучшего
//усвоения материала использовать как явный, так и не явный метод вызова функций
//операторов

//Вариант 23 :
/*1. Комплексное число

Умножение комплексного числа на вещественное число.
Сложение двух комплексных чисел.
Умножение двух комплексных чисел.
Длина комплексного числа (используйте для этого,например, операцию «приведение к double» – operator double (Complex&).*/

/*6. Массив целых чисел (длина не более 100).

Объединение двух массивов в один (operator+)
Сравнение длин массивов (==, >, < !=).*/

int main() {
//комплексные числа
//умножение на число
    cout << "MULTIPLY COMPLEX NUMBER WITH REAL NUMBER\n";
    complex x(1, 2);
    complex res = x * 2;
    cout << res.real << '\t' << res.imagine << '\n';

//сложение двух комплексных чисел
    cout << "ADD COMPLEX NUMBERS\n";
    complex y(2, 3);
    complex res1 = x + y;
    cout << res1.real << '\t' << res1.imagine << '\n';

//умножение двух комплексных чисел
    cout << "MULTIPLY COMPLEX NUMBERS\n";
    complex res2 = x * y;
    cout << res2.real << '\t' << res2.imagine << '\n';

//длина комплексного числа
    cout << "LENGHTH OF COMPLEX NUMBER\n";
    auto res3 = (double) (x);
    cout << res3 << '\n';

//массив целых чисел. Объединение двух массивов
    array arr(2, 4);
    cout << "SUMM OF ARRAY\n";
    array arr1(1, 4);
    array result = arr + arr1;

    for (int i = 0; i < result.len_; ++i)
        cout << result.arr_[i] << '\t';

//Сравнение длин массивов
    cout << "\n result != arr1 : " << (result != arr1);
    cout << "\n result == arr1 : " << (result == arr1);
    cout << "\n result > arr1 : " << (result > arr1);
    cout << "\n result < arr1 : " << (result < arr1);

    return 0;
}