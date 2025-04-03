#include <iostream>

using namespace std;

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}

void timesTwo(int* x){
    *x = *x * 2;
}

int main(){
    int a = 5;
    int b = 10;

    swap(a, b);

    timesTwo(&a);

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    return 0;
}