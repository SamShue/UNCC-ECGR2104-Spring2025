#include <iostream>

using namespace std;

int main(){

    int x = 0x00050002;
    short* p = (short*)&x;
    cout << *p << endl;

    cout << p << endl;
    cout << &x << endl;
    cout << &p << endl;

    return 0;
}