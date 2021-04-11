#ifndef PROG2_1_FUNC_H
#define PROG2_1_FUNC_H

//указатели
void changepointer(int *x, int *y);

//ссылки
void changelink(int &x, int &y);

//указатели
void roundpointer(double *x);

//ссылки
void roundlink(double &x);

struct dots {
    double re;
    double im;
};

//указатели
void complpointer(double *x, double *y, double *t);

//ссылки
void compllink(double &x, double &y, double &t);

struct matriX {
    int arr[3][3];
};

//указатели
void matrixpointer(matriX *m);

//ссылки
void matrixlink(matriX &m);

#endif //PROG2_1_FUNC_H
