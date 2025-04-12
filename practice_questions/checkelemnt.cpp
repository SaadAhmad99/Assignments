#include<iostream>
using namespace std;
//part A
void checking(int *ptr1, int *ptr2, int size ){
int count=0;
    for(int i=0;i<size;i++){
        if(ptr1[i]==ptr2[i]){
            cout<<"Matching element is "<<ptr1[i]<<" and found at "<<i<<" index"<<endl;
            count++;
        }
    }
    cout<<"Total matching element at same index is: "<<count<<endl;
}

//Part B
void checking2(int *ptr1, int *ptr2, int size){
    int count =0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(ptr1[i]==ptr2[j]){
             cout<<"Matching element in both array is "<<ptr1[i];
             count++;
             break;
            }
        }
    }
    cout<<"\nTotal matching element in both arrays is: "<<count<<endl;

}
int main(){
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;
    
    int *ptr1;
    ptr1= new int[size];

    int *ptr2;
    ptr2= new int[size];

    cout<<"Enter the "<<size<<" values of 1st array: ";
    for(int i=0;i<size;i++){
        cin>>ptr1[i];
    }

    cout<<"\nEnter the "<<size<<" values for 2nd array: ";
    for(int i=0;i<size;i++){
        cin>>ptr2[i];
    }

    checking(ptr1,ptr2,size);
    cout<<endl;
    checking2(ptr1,ptr2,size);

    delete[] ptr1;
    delete[] ptr2;

    ptr1=NULL;
    ptr2=NULL;
    
return 0;
}