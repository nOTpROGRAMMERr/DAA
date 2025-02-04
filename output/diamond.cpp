#include <iostream>
using namespace std;

// Base class
class Animal {
protected:
    string name;
public:
    Animal(string n) : name(n) {}
    virtual void display() {
        cout << "Name: " << name << endl;
    }
};

// First derived class
class Mammal : virtual public Animal {
protected:
    int legs;
public:
    Mammal(string n, int l) : Animal(n), legs(l) {}
    void display() {
        Animal::display();
        cout << "Legs: " << legs << endl;
    }
};

// Second derived class  
class WingedAnimal : virtual public Animal {
protected:
    int wings;
public:
    WingedAnimal(string n, int w) : Animal(n), wings(w) {}
    void display() {
        Animal::display();
        cout << "Wings: " << wings << endl;
    }
};

// Class inheriting from both Mammal and WingedAnimal
class Bat : public Mammal, public WingedAnimal {
public:
    Bat(string n, int l, int w) : Animal(n), Mammal(n, l), WingedAnimal(n, w) {}
    void display() {
        Animal::display();
        cout << "Legs: " << legs << endl;
        cout << "Wings: " << wings << endl;
    }
};

int main() {
    cout << "Demonstrating Diamond Inheritance:" << endl << endl;
    
    Bat bat("Bat", 2, 2);
    cout << "Bat Details:" << endl;
    bat.display();

    return 0;
}
