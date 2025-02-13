#include <iostream>
#include <vector>

using namespace std;

class Student {
    public:
    string name;
    int id;

    Student();
    Student(string name, double gpa) ;

    void computeGpa(double grades[], int num_grades);

    void setGpa(double gpa);
    double getGpa() const;

    private:
    double gpa;
    static int last_id;
};

int Student::last_id = 800000000;

Student::Student(){
    cout << "Constructor called!" << endl;
    name = " ";
    gpa = 4.0;
    id = last_id + 1;
    last_id = id;
}

Student::Student(string name, double gpa) {
    cout << "Overloaded constructor called!" << endl;
    this->name = name;
    this->id = last_id + 1;
    last_id = this->id;
    setGpa(gpa);
}

void Student::computeGpa(double grades[], int num_grades){
    double avg = 0.0;
    for(int i = 0; i < num_grades; i++){
        avg = avg + grades[i];
    }
    avg = avg / num_grades;
    gpa = avg;
}

void Student::setGpa(double gpa){
    if(gpa <= 4.0 && gpa >= 0.0){
        this->gpa = gpa;
    } else {
        cout << "Invalid GPA!" << endl;
        this->gpa = -1.0;
    }
}

double Student::getGpa() const {
    return gpa;
}

int main(){

    double grades_s[] = {3.0, 2.0, 2.0};
    Student s;
    s.name = "Sam";
    s.computeGpa(grades_s, 3);

    Student s2("Bob", 8.0);
    //s2.name = "Bob";
    //s2.setGpa(8.0);
    //s2.id = 801231285;
    /*
    cout << "Name: " << s.name << endl;
    cout << "ID: " << s.id << endl;
    cout << "GPA: " << s.getGpa() << endl;

    cout << "Name: " << s2.name << endl;
    cout << "ID: " << s2.id << endl;
    cout << "GPA: " << s2.getGpa() << endl;
    */
    vector<Student> student_database;
    student_database.push_back(s);
    student_database.push_back(s2);
    student_database.push_back(Student("Joe", 2.0));


    for(int i = 0; i < student_database.size(); i++){
        cout << "Name: " << student_database.at(i).name << endl;
        cout << "ID: " << student_database.at(i).id << endl;
        cout << "GPA: " << student_database.at(i).getGpa() << endl;
    }

    /*
    vector<string> names = {"Sam", "Bob", "Joe", "Bob2"};
    vector<double> gpas = {2.5, 3.4, 4.0, 2.3};
    vector<int> ids = {800123456, 801456789, 801224556};

    for(int i = 0; i < names.size(); i++){
        cout << "Name: " << names[i] << endl;
        cout << "ID: " << ids[i] << endl;
        cout << "GPA: " << gpas[i] << endl;
    }
    */
    return 0;
}