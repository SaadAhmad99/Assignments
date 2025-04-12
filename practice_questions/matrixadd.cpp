#include<iostream>
using namespace std;

void add(int *A,int *B,int *Sum, int size){
    for(int i=0;i<size;i++){
         Sum[i]=A[i]+B[i];
    }
}

int main(){
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;

    int *matrixA;
    matrixA = new int[size];
     int *matrixB;
    matrixB = new int[size];
    int *Sum;
    Sum = new int[size];

    cout<<"Enter the"<<size <<" element of the Matrix A: ";
    for(int i=0;i<size;i++){
        cin>>matrixA[i];
    }

    cout<<"Enter the"<<size <<" element of the Matrix B: ";
    for(int i=0;i<size;i++){
        cin>>matrixB[i];
    }
    //display matrix B
    cout<<"Matrix A: ";
    for(int i=0;i<size;i++){
        cout<<matrixA[i]<<" ";
    }
    //display matrix A 
    cout<<"\nMatrix A: ";
    for(int i=0;i<size;i++){
        cout<<matrixB[i]<<" ";
    }

    add(matrixA,matrixB,Sum,size);

    cout<<"\nResultant array of A + B is: ";
    for(int i=0;i<size;i++){
        cout<<Sum[i]<<" ";
    }
    cout<<endl;

    delete[] matrixA;
    delete[] matrixB;
    delete[] Sum;

    matrixA=NULL;
    matrixB=NULL;
    Sum=NULL;
    
return 0;
}