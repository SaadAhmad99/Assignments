#include <iostream>
using namespace std;

class Shape {
private:
    float area;

protected:
    virtual void calculateArea(float a) {
        area = a;
    }

    float getArea() const {
        return area;
    }

public:
    void displayArea() {
        cout << "Area: " << area << endl;
    }
};

class Circle : public Shape {
public:
    float radius;
    Circle(float r) {
        radius = r;
        calculateArea();  // Call overridden method
    }

    void calculateArea() {
        float area = 3.14159 * radius * radius;  // π * r²
        Shape::calculateArea(area); 
    }
};

int main() {
    Circle c1(7.0); 
    c1.displayArea();

    return 0;
}
