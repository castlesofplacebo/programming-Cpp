#ifndef LAB3_HEAD_H
#define LAB3_HEAD_H

#include <iostream>

using namespace std;

class complex {
public:
    double real;
    double imagine;

    complex(double re, double im);

    complex operator*(double x);

    complex operator+(const complex &c1);

    complex operator*(const complex &c1);

    explicit operator double();
};

class array {
public:
    int arr_[100];
    int len_;

    array(const int arr[], int len);

    array(int arr, int len);

    array &operator+(const array &a);

    bool operator==(const array &a);

    bool operator!=(const array &a);

    bool operator<(const array &a);

    bool operator>(const array &a);

};

#endif //LAB3_HEAD_H