#include <iostream>
using namespace std;

int main_diagnol(int **matrix, int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=matrix[i][i];
    }
    return sum;
}

int sec_diagnol(int **matrix, int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=matrix[i][n-i-1];
    }
    return sum;
}

int main()
{
    int n;
    cout << "Enter the size of the matrix (nxn): ";
    cin >> n;

    int **matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }

    cout<<"Original Matrix "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }


    int mainSum = main_diagnol(matrix,n);
    int secSum = sec_diagnol(matrix,n);
    int AbsDiff = (mainSum > secSum) ? (mainSum - secSum) : (secSum - mainSum);

    cout<<"The Sum of the Main Diagnol: "<<mainSum<<endl;
    cout<<"The Sum of the Secondary Diagnol: "<<secSum<<endl;
    cout<<"Absolute Difference: "<<AbsDiff<<endl;
 
    for(int i=0;i<n;i++){
        delete[] matrix[i];
    }

    delete[] matrix;
    matrix=NULL;

    return 0;
}