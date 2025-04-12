#include <iostream>
using namespace std;

class School{
public:
    char name[10];
    int rollNo[30];
    int marks[10][3];

void addstudent(int n){
    for(int i=0;i<n;i++){
        cout<<"Enter Student "<<i+1<<" Name: ";
        cin>>name[i];
        cout<<"Enter Roll No: ";
        cin>>rollNo[i];
        cout<<"Enter marks for 3 subjects: ";
        for(int j=0;j<3;j++){
            cout<<"Subject "<<j+1<<" marks:";
            cin>>marks[i][j];
        }
    }
}

void display(int n){
    for(int i=0;i<n;i++){
        cout<<"-----Student "<<i+1<<" Details------"<<endl;
        cout<<"Name: "<<name[i]<<endl;
        cout<<"Roll No: "<<rollNo[i]<<endl;
        cout<< "Marks of 3 subjects: ";
        for(int j=0;j<3;j++){
            cout<<marks[i][j]<<" ";
        }
        cout<<endl;
    }
}

void average(int n){
    for(int i=0;i<n;i++){
        int total=0;
        for(int j=0;j<3;j++){
            total=total+marks[i][j];
        }
        float avg=total/3.0;
        cout<<"Student "<<i+1<<" Average Marks: "<<avg<<endl;
    }
}

void highest(int n){
    int highestTotal = 0, topStudentIndex = 0;
    for(int i=0;i<n;i++){
        int total=0;
        for(int j=0;j<3;j++){
            total=total+marks[i][j];
        }
        if(total>highestTotal){
            highestTotal=total;
            topStudentIndex=i;
        }
    }
    cout<<"\n-----Topper Student-----"<<endl;
    cout<<"Name: "<<name[topStudentIndex]<<endl;
    cout<<"Roll No: "<<rollNo[topStudentIndex]<<endl;
    cout<<"Total Marks: "<< highestTotal<<endl;
}
};
int main() {
    int n;
    cout<<"Enter number of students: ";
    cin>>n;

    School sch;

    sch.addstudent(n);
    sch.display(n);
    sch.average(n);
    sch.highest(n);

    return 0;
}
