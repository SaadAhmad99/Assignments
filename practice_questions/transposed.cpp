#include<iostream>
using namespace std;

int **trans(int **A,int rows,int cols){
    int **trans=new int *[cols];
    for(int i=0;i<cols;i++){
        trans[i]= new int [rows];
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            *(*(trans+j)+i)=*(*(A+i)+j);
        }
    }
    return trans;
}
int main(){
    int rows,cols;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    cout<<"Enter the number of cols: ";
    cin>>cols;

    int **A = new int*[rows];
    for(int i=0;i<rows;i++){
        A[i]=new int[cols];
    }

    cout<<"Enter the Values of the "<<rows<<" X "<<cols<<" Matrix A : ";
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>*(*(A+i)+j);
        }
    }

    cout<<"\nOriginal Matrix A elements: "<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<*(*(A+i)+j)<<" ";
        }
        cout<<endl;
    }

    int **transposed=trans(A,rows,cols);

    cout<<"\nAfter transposed of the Matrix A: "<<endl;
    for(int i=0;i<cols;i++){
        for(int j=0;j<rows;j++){
            cout<<*(*(transposed+i)+j)<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<rows;i++){
        delete[] A[i];
    }

    for(int i=0;i<cols;i++){
        delete[] transposed[i];
    }

    delete[] A;
    delete[] transposed;

    A=NULL;
    transposed=NULL;

return 0;
}   