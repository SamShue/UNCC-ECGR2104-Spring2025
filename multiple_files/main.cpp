#include <iostream>
#include "utils.h"

using namespace std;

int main(){
    int size = 5;
    double quizzes[] = {90.0, 95.0, 100.0, 80.0, 85.0};

    cout << average(quizzes, size) << endl;

    return 0;
}