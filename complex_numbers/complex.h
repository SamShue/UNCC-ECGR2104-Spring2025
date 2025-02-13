#ifndef COMPLEX_H
#define COMPLEX_H

#include <cmath>
#include <iostream>

struct Complex{
    double real;
    double imag;

    Complex(double real, double imag);
    double getMagnitude();
    Complex add(Complex c);
    Complex operator+(Complex c);
    Complex operator+(double c);
    Complex operator-(Complex c);
    bool operator>(Complex c);
    bool operator==(Complex c);
    void print();
};

#endif