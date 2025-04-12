#include <iostream>
using namespace std;
const int n = 5;
char maze[n][n] = {
    {'.', '.', '#', '.', '.'},
    {'.', '#', '.', '#', '.'},
    {'.', '.', '.', '.', '.'},
    {'.', '#', '#', '#', '.'},
    {'.', '.', '.', '.', '.'}
};

int countPaths(int x, int y, int dx, int dy) {
    if(x<0 || y<0 || x>=n || y>=n || maze[x][y]=='#')
        return 0;
    if(x == dx && y == dy)
        return 1;
    
    maze[x][y] = '#';
    int paths = countPaths(x + 1, y, dx, dy) + countPaths(x - 1, y, dx, dy) +
                countPaths(x, y + 1, dx, dy) + countPaths(x, y - 1, dx, dy);
    maze[x][y] = '.';
    return paths;
}

int main() {
    cout << "Total paths: " << countPaths(0, 0, 4, 4) << endl;
    return 0;
}