
#include<iostream>
using namespace std;
#include<cstring>
int main(){
    char *str1=new char[30];
    cout<<"Enter the first string: ";
    cin.getline(str1,30);

    char *str2=new char[30];
    cout<<"Enter the second string: ";
    cin.getline(str2,30);

    if(strlen(str1)!=strlen(str2)){
        cout<<"The two strings are not reverse of each other. "<<endl;
        return 0;
    }

    int size=strlen(str1);
    for(int i=0;i<size;i++){
        if(str1[i]!=str2[size-i-1]){
            cout<<"Both Strings are not reverse of each other. "<<endl;
            return 0;
        }
    }
    cout<<"The Two strings are reverse of each other. ";

return 0;
}