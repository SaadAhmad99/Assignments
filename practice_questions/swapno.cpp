#include<iostream>
using namespace std;

void swap(int *num1, int *num2, int size){
    int temp=*num1;
    *num1=*num2;
    *num2=temp;
}

int main(){
    int size=2;
    
    int *num1;
    num1 = new int;
    cout<<"Enter the first number ";
    cin>>*num1;

    int *num2;
    num2= new int;
    cout<<"Enter the second number ";
    cin>>*num2;

    cout<<"Numbers Before swapping "<<endl;
    cout<<"NUM 1 is "<<*num1<<endl;
    cout<<"NUM 2 is "<<*num2<<endl;

    swap(num1,num2,size);

    cout<<"Numbers After swapping "<<endl;
    cout<<"NUM 1 is "<<*num1<<endl;
    cout<<"NUM 2 is "<<*num2<<endl;

    delete num1;
    delete num2;

    num1=NULL;
    num2=NULL;

return 0;
}