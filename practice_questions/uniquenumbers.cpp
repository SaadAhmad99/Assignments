#include<iostream>
using namespace std;

void display(int k[], int unique){
    cout<<"All unique numbers is : ";
    for(int i=0;i<unique;i++){
        cout<<k[i]<<" ";
    }
}

int main(){
int arr[25];
int k[25];
int unique=0;
cout<<"enter 25 numbers : ";
for(int i=0;i<25;i++){
    cin>>arr[i];
     if (arr[i]<10 || arr[i]>100){
            cout << "Invalid. Please enter number between 10 and 100 "<<endl;
            i--;   
        }
    int j;
   for(j=0;j<i;j++){
    if(arr[i]==arr[j]){
        break;
    }
   }
    if(j==i){
        k[unique]=arr[i];
        unique++;
        
    }
}
display(k,unique);

return 0;
}