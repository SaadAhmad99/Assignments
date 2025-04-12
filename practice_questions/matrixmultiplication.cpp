#include <iostream>
using namespace std;

void multiplication(int **A,int **B,int **R, int row1, int col1,int row2, int col2){
    if(col1==row2){
        for(int i=0;i<row1;i++){
            for(int j=0;j<col2;j++){
                R[i][j]=0;
                for(int k=0;k<col1;k++){
                    R[i][j] +=A[i][k]*B[k][j];
                }
            }
        }
    }else{
        cout<<"Multiplication is not Possible. "<<endl;
    }

}


int main(){

    int row1,col1,row2,col2;
    
    cout<<"Enter number of rows of matrix A: ";
    cin>>row1;
    cout<<"Enter number of col of matrix A: ";
    cin>>col1;

    cout<<"Enter number of rows of matrix B: ";
    cin>>row2;
    cout<<"Enter number of col of matrix B: ";
    cin>>col2;

    if(col1 != row2){
        cout<<"Matrices cannot be multiplied. Number of columns in A must be equal to number of rows in B."<<endl;
        return 0;
    }

    int **A = new int*[row1];
    for(int i=0;i<row1;i++){
        A[i]=new int[col1];
    }

    int **B = new int*[row2];
    for(int i=0;i<row2;i++){
        B[i]=new int[col2];
    }

    int **R = new int*[row1];
    for(int i=0;i<row1;i++){
        R[i]=new int[col2];
    }

    cout<<"Enter Matrix A element: ";
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            cin>>A[i][j];
        }
    }

    cout<<"Enter Matrix B element: ";
    for(int i=0;i<row2;i++){
        for(int j=0;j<col2;j++){
            cin>>B[i][j];
        }
    }

    cout<<"Matrix A:"<<endl;
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Matrix B:"<<endl;
    for(int i=0;i<row2;i++){
        for(int j=0;j<col2;j++){
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }

    multiplication(A,B,R,row1,col1,row2,col2);

    cout<<"Result Matrix (A x B) "<<endl;
    for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
            cout<<R[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<row1;i++){
        delete[] A[i];
    }    
        delete[] A;
    for(int i=0; i<row2;i++){
        delete[] B[i];
    } 
        delete[] B;
    for(int i=0; i<row1;i++){
        delete[] R[i];
    }
        delete[] R;

        A=NULL;
        B=NULL;
        R=NULL;


    return 0;
}