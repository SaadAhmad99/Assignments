#include <iostream>
using namespace std;
 
int uniquePaths(int m, int n) {
    int** grid = new int*[m];
    for (int i = 0; i < m; i++) {
        grid[i] = new int[n];
    }

    for (int i = 0; i < m; i++) {
        grid[i][0] = 1;
    }
    for (int j = 0; j < n; j++) {
        grid[0][j] = 1;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            grid[i][j] = grid[i-1][j] + grid[i][j-1];
        }
    }
    int result = grid[m-1][n-1];

    for (int i = 0; i < m; i++) {
        delete[] grid[i];
    }
    delete[] grid;

    return result;
}

int main() {
    int m,n;
    cout<<"Enter the number of rows (m): ";
    cin>>m;
    cout<<"Enter the number of columns (n): ";
    cin>>n;

    cout<<"Unique paths from (0,0) to (" << m-1 << "," << n-1 << ") are: "<<uniquePaths(m,n)<<endl;

    return 0;
}
