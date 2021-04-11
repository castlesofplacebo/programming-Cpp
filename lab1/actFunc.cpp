#include <iostream>
#include <cmath>
#include "func.h"

using namespace std;

void changepointer(int *x, int *y) {
    swap(*x, *y);
}

void changelink(int &x, int &y) {
    swap(x, y);
}

void roundpointer(double *x) {
    *x = round(*x);
}

void roundlink(double &x) {
    x = round(x);
}

void complpointer(double *x, double *y, double *t) {
    *x = (*x) * (*t);
    *y = (*y) * (*t);
}

void compllink(double &x, double &y, double &t) {
    x = x * t;
    y = y * t;
}

void matrixpointer(matriX *m) {
    for (int i = 0; i < 3; ++i) {
        for (int j = i; j < 3; ++j) {
            swap(m->arr[i][j], m->arr[j][i]);
        }
    }
}

void matrixlink(matriX &m) {
    for (int i = 0; i < 3; ++i) {
        for (int j = i; j < 3; ++j) {
            swap(m.arr[i][j], m.arr[j][i]);
        }
    }
}