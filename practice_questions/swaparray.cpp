#include<iostream>
using namespace std;
void swap(int a[],int b[]){
    for(int i=0;i<5;i++){
        int temp=a[i];
        a[i]=b[i];
        b[i]=temp;
    }
    cout<<endl;
    cout<<"Array A after swapping"<<endl;
    for(int i=0;i<5;i++){
    cout<<" "<<a[i];
    }
    cout<<endl;
    cout<<"Array B after swapping"<<endl;
    for(int i=0;i<5;i++){
    cout<<" "<<b[i];
    }
}
int main(){

int a[]={2,1,4,5,6};
int b[]={5,6,9,55,76};

cout<<"Array A before swapping"<<endl;
for(int i=0;i<5;i++){
    cout<<" "<<a[i];
}
cout<<endl;
cout<<"Array B before swapping"<<endl;
for(int i=0;i<5;i++){
    cout<<" "<<b[i];
}
swap(a,b);

    return 0;
}

