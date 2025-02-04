#include <iostream>
#include <string>
using namespace std;


class Student {
private:
    string name;
    int age;
    float gpa;

public:

    Student(string n, int a, float g) {
        name = n;
        age = a;
        gpa = g;
    }

    Student() {
        name = "Unknown";
        age = 0;
        gpa = 0.0;
    }

    void setName(string n) {
        name = n;
    }

    void setAge(int a) {
        age = a;
    }

    void setGPA(float g) {
        gpa = g;
    }

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "GPA: " << gpa << endl;
    }
};


int main() {
    
    Student student1("Dohn joe", 20, 3.8);
    Student student2;

    cout << "Student 1 Information:" << endl;
    student1.displayInfo();

    cout << "\nStudent 2 Information (default):" << endl;
    student2.displayInfo();

    
    student2.setName("Sane Jmith");
    student2.setAge(22);
    student2.setGPA(3.9);

    cout << "\nUpdated Student 2 Information:" << endl;
    student2.displayInfo();

    

    return 0;
}
