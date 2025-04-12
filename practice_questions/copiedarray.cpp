#include<iostream>
using namespace std;

void copyarray(int *array1, int *array2, int size1,int size2){
    for(int i=0;i<size1;i++){
        array2[i]=array1[i];
    }

    cout<<"\nCopied Array "<<endl;
    for(int i=0;i<size2;i++){
        cout<<array2[i]<<" ";
    }

    cout<<endl;

}
int main(){
    int size1=3;
    int size2=5;
    int array1[]={3,4,6};
    int *array2;
    array2 = new int[size2];

    cout<<"Original Array "<<endl;
    for(int i=0;i<3;i++){
        cout<<array1[i]<<" ";
    }

    copyarray(array1,array2,size1,size2);

    delete[] array2;

    array2=NULL;

    
return 0;
}