#include <iostream>

using namespace std;

int main(){
    int x = 5;

    int* p = &x;

    *p = 7;

    cout << x << endl;

    return 0;
}