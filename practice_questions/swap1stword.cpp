#include<iostream>
using namespace std;
#include<cstring>
int main(){

char (*str)[10] = new char[5][10];

strcpy(str[0],"Read");
strcpy(str[1],"Bear");
strcpy(str[2],"Hat");
strcpy(str[3],"Beat");
strcpy(str[4]," ");

cout<<"Before Swapping: "<<endl;
for(int i=0;i<5;i++){
    cout<<str[i]<<endl;
}

char temp;

temp=str[0][0];
str[0][0]=str[1][0];
str[1][0]=temp;

temp=str[2][0];
str[2][0]=str[3][0];
str[3][0]=temp;

cout<<"After swapping: \n"<<endl;
for(int i=0;i<5;i++){
    cout<<str[i]<<endl;
}

int total=0;
for(int i=0;i<5;i++){
total=total+strlen(str[i]);
}
cout<<"The total number of characters is "<<total;

delete[] str;
str=NULL;

return 0;
}