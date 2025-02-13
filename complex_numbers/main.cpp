#include <iostream>

using namespace std;

struct Complex{
    double real;
    double imag;

    Complex(double real, double imag){
        this->real = real;
        this->imag = imag;
    }

    Complex add(Complex c){
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator+(Complex c){
        return Complex(real + c.real, imag + c.imag);
    }

    void print(){
        cout << real << " + " << imag << "i" << endl;
    }
};

int main(){
    Complex x(5, 3);
    Complex y(2, 6);
    Complex z = x + y;
    //Complex z = x.add(y);
    /*
    Complex z(0, 0);
    z.real = x.real + y.real;
    z.imag = x.imag + y.imag;
    */

    //Complex z(x.real + y.real, x.imag + y.imag);

    

    cout << "Result: ";
    z.print();

    /*
    double x_real = 5;
    double x_imag = 3;

    double y_real = 2;
    double y_imag = 6;

    // z = x + y
    double z_real = x_real + y_real;
    double z_imag = x_imag + y_imag;

    cout << "Result: " << z_real << " + " << z_imag << "i" << endl;
    */
    return 0;
}