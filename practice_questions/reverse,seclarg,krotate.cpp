#include <iostream>
using namespace std;

void reverse(int *array, int size)
{
    int i = 0;
    int j = size - 1;
    while (i < j)
    {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }

    cout << "The reverse of the array is ";
}

void sec_largest(int *array, int size)
{
    int first = 0;
    int second = 0;
    for (int i = 0; i < size; i++)
    {
        if (*(array + i) > first)
        {
            second = first;
            first = *(array + i);
        }
        else if (*(array + i) > second && *(array + i) != first)
        {
            second = *(array + i);
        }
    }
    cout << "The second largest elment in the array is " << second << endl;
}
 
void rotate(int *array, int size, int k)
{
    k = k % size;
    int temp[size];

    for (int i = 0; i < size; i++)
    {
        temp[i] = *(array + size - k + i);
    }

    for (int i = size - 1; i >= k; i--)
    {
        *(array + i) = *(array + i - k);
    }

    for (int i = 0; i < k; i++)
    {
        *(array + i) = temp[i];
    }
}

void display(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(array + i) << " ";
    }
    cout << endl;
}
int main()
{
    int size = 10;
    int array[size] = {3, 2, 4, 1, 5, 1, 3, 7, 8, 5};
    int *ptr = array;

    cout << "Original Array: ";
    display(array, size);

    reverse(array, size);
    display(array, size);

    sec_largest(array, size);

    int k;
    cout << "Enter k for right rotation: ";
    cin >> k;
    rotate(array, size, k);
    cout << "Array after " << k << " rotation";
    display(array, size);

    return 0;
}