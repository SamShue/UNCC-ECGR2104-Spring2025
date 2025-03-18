#include <iostream>

using namespace std;

class vector{
    public:
    vector(){
        a = new int[3];
        nextIndex = 0;
        allocatedSize = 3;

        cout << a << endl;
    }

    ~vector(){
        cout << "Destructor called!" << endl;
        delete[] a;
    }

    void push_back(int d){
        if(nextIndex < allocatedSize){
            a[nextIndex] = d;
            nextIndex++;
        } else {
            int* larger_a = new int[allocatedSize + 3];
            for(int i = 0; i < nextIndex; i++){
                larger_a[i] = a[i];
            }
            larger_a[nextIndex] = d;
            nextIndex++;
            allocatedSize = allocatedSize + 3;
            delete[] a;
            a = larger_a;
        }
    }

    void pop_back(){
        if(nextIndex == 0)
            return;

        nextIndex--;
    }

    int& at(int index) const {
        return a[index];
    }

    int size() const {
        return nextIndex;
    }

    private:
    int* a;
    int nextIndex;
    int allocatedSize;
};

void createsProblem(){
    vector v;
    v.push_back(5);
    v.push_back(3);
    v.push_back(7);

    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << ", ";
    }
    cout << endl;
}

int main(){
    createsProblem();
    createsProblem();
    createsProblem();

    return 0;
}