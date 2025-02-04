#include <iostream>
using namespace std;

// Abstract base class
class Shape {
protected:
    double width;
    double height;
public:
    Shape(double w = 0, double h = 0) {
        width = w;
        height = h;
    }
    
    // Pure virtual function making Shape an abstract class
    virtual double area() = 0;
    
    // Virtual destructor
    virtual ~Shape() {}
};

// Derived class Rectangle
class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : Shape(w, h) {}
    
    double area() override {
        return width * height;
    }
};

// Derived class Triangle  
class Triangle : public Shape {
public:
    Triangle(double w, double h) : Shape(w, h) {}
    
    double area() override {
        return (width * height) / 2;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    
    double area() override {
        return 3.14159 * radius * radius;
    }
};

int main() {
    // Shape shape(10, 10); // Cannot create instance of abstract class
    
    Rectangle rectangle(5, 3);
    Triangle triangle(4, 6);
    Circle circle(5);
    
    cout << "Rectangle area: " << rectangle.area() << endl;
    cout << "Triangle area: " << triangle.area() << endl;
    cout << "Circle area: " << circle.area() << endl;
    
    // Using base class pointer
    Shape* shape1 = &rectangle;
    Shape* shape2 = &triangle;
    Shape* shape3 = &circle;
    
    cout << "\nUsing base class pointers:" << endl;
    cout << "Rectangle area: " << shape1->area() << endl;
    cout << "Triangle area: " << shape2->area() << endl;
    cout << "Circle area: " << shape3->area() << endl;
    
    return 0;
}
