#include <iostream>
using namespace std;

class Car {
public:
    string make, model;
    int year;

    Car(string m,string md, int y) {
        make = m;
        model = md;
        year = y;
    }

    void display() {
        cout << "Make: " << make << ", Model: " << model << ", Year: " << year << endl;
    }
};

int main() {
    Car c("supra "," toyota",2025);
    c.display();  // Output: Unknown values

    return 0;
}
