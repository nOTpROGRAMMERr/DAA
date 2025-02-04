#include <iostream>
using namespace std;

class ConstructorDemo {
private:
    int x, y;
    string name;

public:
    // 1. Default Constructor
    ConstructorDemo() {
        x = 0;
        y = 0;
        name = "Default";
        cout << "Default Constructor called" << endl;
    }

    // 2. Parameterized Constructor
    ConstructorDemo(int a, int b, string n) {
        x = a;
        y = b;
        name = n;
        cout << "Parameterized Constructor called" << endl;
    }

    // 3. Copy Constructor
    ConstructorDemo(const ConstructorDemo &obj) {
        x = obj.x;
        y = obj.y;
        name = obj.name;
        cout << "Copy Constructor called" << endl;
    }

    // 4. Conversion Constructor
    ConstructorDemo(int value) {
        x = value;
        y = value;
        name = "Converted";
        cout << "Conversion Constructor called" << endl;
    }

    // 5. Destructor
    ~ConstructorDemo() {
        cout << "Destructor called for " << name << endl;
    }

    void display() {
        cout << "x: " << x << ", y: " << y << ", name: " << name << endl;
    }
};

int main() {
    // Testing different constructors
    cout << "\n1. Creating object with default constructor:" << endl;
    ConstructorDemo obj1;
    obj1.display();

    cout << "\n2. Creating object with parameterized constructor:" << endl;
    ConstructorDemo obj2(10, 20, "Parameterized");
    obj2.display();

    cout << "\n3. Creating object with copy constructor:" << endl;
    ConstructorDemo obj3 = obj2;
    obj3.display();

    cout << "\n4. Creating object with conversion constructor:" << endl;
    ConstructorDemo obj4 = 100;  // Implicit conversion
    obj4.display();

    cout << "\nObjects will be destroyed in reverse order of creation" << endl;
    return 0;
}

