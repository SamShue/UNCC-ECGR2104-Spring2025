#include <iostream>

using namespace std;

int* growArray(int* currentArrayPtr, int currentSize, int newSize){
    int* newArrayPtr = new int[newSize]; 
    for (int i = 0; i < currentSize; i++){	 
          newArrayPtr[i] = currentArrayPtr[i];
    }
    delete[] currentArrayPtr; 
    return newArrayPtr;
}

int main(){

    int x = 9;
    int* a = new int[3] {5, 2, 7};
    int y = 13;
    
    a = growArray(a, 3, 4);
    a[3] = 9;

    for(int i = 0; i < 4; i++){
        cout << a[i] << endl;
        
    }


    return 0;
}