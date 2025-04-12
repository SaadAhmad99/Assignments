#include <iostream>
using namespace std;
class Rectangle
{
public:
    double length;
    double breadth;

    Rectangle(double l, double b)
    {
        length = l;
        breadth = b;
    };

    // copy constructor
    Rectangle(const Rectangle &r)
    {
        length = r.length;
        breadth = r.breadth;
    }

    void display()
    {
        cout << "length: " << length << " and breadth: " << breadth << " so Area is: " << length * breadth << endl;
    }
};
int main()
{
    Rectangle r1(13.4, 12.3);
    r1.display();
    Rectangle r2 = r1;
    r2.display();

    return 0;
}