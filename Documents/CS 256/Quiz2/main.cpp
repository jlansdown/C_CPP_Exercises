#include <iostream>

using namespace std;

class Circle {
private:
    double radius;
    const double pi = 3.14159;

public:
    Circle();
    Circle(double rad);

    void setRadius(double rad);
    double getRadius();

    double getArea();
    double getDiameter();
    double getCircumference();
};

Circle::Circle() : radius(0.0) {}

Circle::Circle(double rad) {
    radius = rad;
}

void Circle::setRadius(double rad) { radius = rad; }

double Circle::getRadius() { return radius; }

double Circle::getArea() { return pi * radius * radius; }

double Circle::getDiameter() { return 2 * radius; }

double Circle::getCircumference() { return 2 * pi * radius; }

int main() {

    double radius;

    std::cout << "Please enter radius: " << std::endl;

    cin >> radius;

    Circle circle(radius);

    cout << "Circle area: " << circle.getArea() << endl;
    cout << "Circle diameter: " << circle.getDiameter() << endl;
    cout << "Circle circumference: " << circle.getCircumference() << endl;

    return 0;
}
