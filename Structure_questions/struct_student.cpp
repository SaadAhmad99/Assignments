#include<iostream>
using namespace std;
struct Student{
    string name;
    int rollNo;
    int marks;

};
int main(){
    int n;
    cout<<"Enter the number of students ";
    cin>>n;

    Student *std=new Student[n];

    for(int i=0;i<n;i++){
        cout<<"\n-----Student "<<i+1<<" informtion----- "<<endl;
        cout<<"Enter the name of the student: ";
        cin>>std[i].name;
        cout<<"Enter the rollNo of the student: ";
        cin>>std[i].rollNo;
        cout<<"Enter the Marks of the student: ";
        cin>>std[i].marks;

    }
    cout<<endl;

    for(int i=0;i<n;i++){
        cout<<"The name of the student "<<i+1<<" is: "<<std[i].name<<" \nHis Roll No is: "<<std->rollNo<<" \nHis Marks is: "<<std->marks<<endl;
    }

return 0;
}