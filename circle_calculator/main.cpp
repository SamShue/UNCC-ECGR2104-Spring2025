#include <iostream>

#define PI 3.14

using namespace std;

//const double PI = 3.14;

double circleArea(double radius);
double cylinderVolume(double radius, double length);
double sphereVolume(double radius);

int main(){
    double r = 2.5;
    double a = circleArea(r);
    cout << "Area of the circle is " << a << endl;

    double r2 = 3.3;
    double l = 4.0;
    double v = cylinderVolume(r2, l);
    cout << "Volume of the cylinder is " << v << endl;

    double r3 = 3.3;
    double v2 = sphereVolume(r3);
    cout << "Volume of the sphere is " << v2 << endl;

    return 0;
}

double cylinderVolume(double radius, double length){
    double volume = circleArea(radius) * length;
    return volume;
}

double circleArea(double radius){
    double area = PI * radius * radius;
    return area;
}

double sphereVolume(double radius){
    double volume = (4.0/3.0) * PI * radius * radius * radius;
    return volume;
}