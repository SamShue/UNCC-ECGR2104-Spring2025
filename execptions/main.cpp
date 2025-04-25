#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

int main(){
    int x = 5;
    try{
        throw runtime_error("Error message");
    } catch (const exception& e){
        cout << e.what() << endl;
    }

    cout << "Here" << endl;

    return 0;
}