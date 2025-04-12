#include<iostream>
using namespace std;
void reverse(int *arr, int size){
    int i=0; int j=size-1;
    while(i<j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
}
int main(){
    int size;
    cout<<"Enter the size of Array ";
    cin>>size;

    int *arr;
    arr = new int[size];
    cout<<"Enter the array elements ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    cout<<"Original Array "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    reverse(arr,size);
    cout<<"Reverse Array "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    delete[] arr;

    arr=NULL;
    
return 0;
}