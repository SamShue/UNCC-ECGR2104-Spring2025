#include <iostream>

using namespace std;

int main(){
    int a[] = {5, 7, 9};

    cout << *(a + 1) << " " << a[1] << endl;

    return 0;
}