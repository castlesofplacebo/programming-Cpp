#include "head.h"
#include <iostream>
#include <cmath>

using namespace std;

complex::complex(double re, double im)
        : real(re), imagine(im) {
}

complex complex::operator*(double x) {
    return complex(real * x, imagine * x);
}

complex complex::operator+(const complex &c1) {
    return complex(this->real + c1.real, this->imagine + c1.imagine);
}

complex complex::operator*(const complex &c1) {
    return complex(this->real * c1.real, this->imagine * c1.imagine);
}

complex::operator double() {
    return sqrt(real * real + imagine * imagine);
}

array::array(const int *arr, int len)
        : len_(len) {
    for (int i = 0; i < len; ++i) {
        arr_[i] = arr[i];
    }
}

array::array(const int arr, int len)
        : len_(len) {
    for (int i = 0; i < len; ++i) {
        arr_[i] = arr;
    }
}

array &array::operator+(const array &a) {
    if (len_ + a.len_ > 100)
        exit(1);
    for (int i = 0; i < a.len_; ++i) {
        arr_[i + len_] = a.arr_[i];
    }
    len_ = len_ + a.len_;
    return *this;
}

bool array::operator==(const array &a) {
    return this->len_ == a.len_;
}

bool array::operator>(const array &a) {
    return this->len_ > a.len_;
}

bool array::operator<(const array &a) {
    return this->len_ < a.len_;
}

bool array::operator!=(const array &a) {
    return this->len_ != a.len_;
}


