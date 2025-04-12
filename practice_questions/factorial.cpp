#include <iostream>

using namespace std;

// Recursive function to compute the sum of elements in an array
int sumArray(int arr[], int size) {
    if (size == 0) 
        return 0;  // Base case: sum of an empty array is 0
    return arr[0] + sumArray(arr+1, size - 1);  // Add last element and recurse
}

// Recursive function to compute the factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1) 
        return 1;  // Base case: factorial of 0 or 1 is 1
    return n * factorial(n - 1);  // Multiply n by factorial of (n-1)
}

int main() {
    // Step 1: Declare and initialize an array of size 5
    int arr[5] = {2, 4, 6, 8, 10};  // Example values

    // Step 2: Compute the sum of the array using recursion
    int sum = sumArray(arr, 5);

    // Step 3: Compute the factorial of the length of the array (factorial of 5)
    int fact = factorial(5);

    // Step 4: Display results
    cout << "Sum of the array elements: " << sum << endl;
    cout << "Factorial of 5: " << fact << endl;

    return 0;
}
