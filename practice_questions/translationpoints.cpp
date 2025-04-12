#include <iostream>

using namespace std;

// Step 1: Define the Point struct
struct Point {
    int x, y;
};

// Function to input points dynamically
void inputPoints(Point* points, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter x and y for Point " << i + 1 << ": ";
        cin >> points[i].x >> points[i].y;
    }
}

// Function to translate points by dx and dy
void translatePoints(Point* points, int n, int dx, int dy) {
    for (int i = 0; i < n; i++) {
        points[i].x += dx;
        points[i].y += dy;
    }
}

// Function to print points
void printPoints(const Point* points, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Point " << i + 1 << ": (" << points[i].x << ", " << points[i].y << ")" << endl;
    }
}

int main() {
    int n, dx, dy;

    // Step 2: Input the number of points
    cout << "Enter the number of points: ";
    cin >> n;

    // Step 3: Dynamically allocate memory for points
    Point* points = new Point[n];

    // Step 4: Input points
    inputPoints(points, n);

    // Display original points
    cout << "\nOriginal Points:\n";
    printPoints(points, n);

    // Step 5: Input translation values
    cout << "\nEnter translation values (dx dy): ";
    cin >> dx >> dy;

    // Step 6: Translate points
    translatePoints(points, n, dx, dy);

    // Display translated points
    cout << "\nTranslated Points:\n";
    printPoints(points, n);

    // Step 7: Free dynamically allocated memory
    delete[] points;

    return 0;
}
