#include "utils.h"

double average(double a[], int size){
    double sum = 0;
    for(int i = 0; i < size; i++){
        sum = sum + a[i];
    }
    return sum / (double)size;
}