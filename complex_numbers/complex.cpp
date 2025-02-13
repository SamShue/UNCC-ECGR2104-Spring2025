#include "complex.h"

Complex::Complex(double real, double imag){
    this->real = real;
    this->imag = imag;
}

double Complex::getMagnitude(){
    return std::sqrt(real*real + imag*imag);
}

Complex Complex::add(Complex c){
    return Complex(real + c.real, imag + c.imag);
}

Complex Complex::operator+(Complex c){
    return Complex(real + c.real, imag + c.imag);
}

Complex Complex::operator+(double c){
    return Complex(real + c, imag);
}

Complex Complex::operator-(Complex c){
    return Complex(real - c.real, imag - c.imag);
}

bool Complex::operator>(Complex c){
    return getMagnitude() > c.getMagnitude();
}

bool Complex::operator==(Complex c){
    return (real == c.real) && (imag == c.imag);
}

void Complex::print(){
    std::cout << real << " + " << imag << "i" << std::endl;
}