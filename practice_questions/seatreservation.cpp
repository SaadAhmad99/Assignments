#include<iostream>
using namespace std;
int main(){
    
    int row,col;
    cout<<"Enter the row: ";
    cin>>row;
    cout<<"Enter the col: ";
    cin>>col;
    int **arr= new int*[row];
    for(int i=0;i<row;i++){
        arr[i]=new int[col];
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            arr[i][j]=0;
        }
    }

int choice;
do
{
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
        cout<<arr[i][j]<<"  ";
    }
    cout<<endl;
}

int i,j,length;
cout<<"Enter seat number";
cin>>i;

cout<<"Enter line number";
cin>>j;

    if(arr[i][j]==0){
        arr[i][j]=1;
        cout<<"Seat reserved successfully"<<endl;
        length++;
    }else{
        cout<<"Invalid.Please try again. "<<endl;
    }
    cout<<"Choose option: "<<endl;
    cout<<"1)Reserve another seat. \n2)Exit. "<<endl;
    cin>>choice;

} while (choice!=2);


return 0;
}