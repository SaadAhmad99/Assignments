#include<iostream>
using namespace std;
#include<string>
int main(){
string name1,name2;
cout<<"Enter the first name: ";
getline(cin,name1);
cout<<"Enter the second name :";
getline(cin,name2);
if(name1.length()!=name2.length()){
    cout<<"Invalid. Enter Equal length strings "<<endl;
    return 0;
}
int size = name1.length();
for(int i=0;i<size/2;i++){
    if(name1[i]!=name2[size-i-1]){
        cout<<"The two strings are not reverse of each other"<<endl;
        return 0;
    }
}
    cout<<"The two strings are reverse of each other "<<endl;


return 0;
}