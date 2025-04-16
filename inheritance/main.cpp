#include <iostream>

using namespace std;

class Person {
    public:
    Person(string name){
        this->name = name;
        this->id = ++last_id;
    }

    void setName(string name){
        this->name = name;
    }

    string getName() const {
        return name;
    }

    int getId() const {
        return id;
    }

    virtual void print() = 0;

    protected:
    string name;
    int id;
    static int last_id;
};

int Person::last_id = 800000000;

class Student : public Person {
    public:
    Student(string name, double gpa) : Person(name) {
        this->gpa = gpa;
    }

    void setGpa(double gpa){
        if(gpa > 4.0 || gpa < 0.0){
            cout << "Invalid GPA!" << endl;
            return;
        }

        this->gpa = gpa;
    }

    double getGpa() const {
        return gpa;
    }

    void print(){
        cout << "Name: " << name << " ID: " << id << " GPA: " << gpa << endl;
    }

    private:
    double gpa;
};

class Faculty : public Person {
    public:
    Faculty(string name, bool tenure) : Person(name) {
        this->tenure = tenure;
    }

    void setTenure(bool tenure){
        this->tenure = tenure;
    }

    bool getTenure() const{
        return tenure;
    }

    void print(){
        cout << "Name: " << name << " ID: " << id << " Tenure: " << tenure << endl;
    }

    private:
    bool tenure;
};

class Staff : public Person {
    public:
    Staff(string name, double salary) : Person(name) {
        this->salary = salary;
    }

    private:
    double salary;
};

int main(){

    Student s("Bob", 3.4);
    Faculty f("Sam", false);
    Person s2("Bob2");

    s.print();
    f.print();

    return 0;
}