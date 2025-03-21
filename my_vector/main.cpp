#include <iostream>

using namespace std;

template <typename T>
class vector{
    public:
    vector(){
        a = new T[3];
        nextIndex = 0;
        allocatedSize = 3;

        cout << "a's address: " << a << endl;
    }

    vector(const vector<T>& other){
        cout << "Copy Constructor Called!" << endl;
        a = new T[other.size()];
        allocatedSize = other.allocatedSize;
        nextIndex = other.nextIndex;

        for(int i = 0; i < other.size(); i++){
            a[i] = other.at(i);
        }
    }

    ~vector(){
        cout << "Destructor called!" << endl;
        delete[] a;
    }

    void operator=(const vector<T>& other){
        cout << "Copy Assignment Override Called!" << endl;
        delete[] a;

        a = new T[other.size()];
        allocatedSize = other.allocatedSize;
        nextIndex = other.nextIndex;

        for(int i = 0; i < other.size(); i++){
            a[i] = other.at(i);
        }
    }

    void push_back(T d){
        if(nextIndex < allocatedSize){
            a[nextIndex] = d;
            nextIndex++;
        } else {
            T* larger_a = new T[allocatedSize + 3];
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

    T& at(int index) const {
        return a[index];
    }

    int size() const {
        return nextIndex;
    }

    private:
    T* a;
    int nextIndex;
    int allocatedSize;
};

void createsProblem(){
    vector<double> v;
    v.push_back(5);
    v.push_back(3);
    v.push_back(7);

    vector<double> v2 = v;

    v2.push_back(1);

    v = v2;

    v2.at(1) = 9;

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