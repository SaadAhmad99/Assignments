#include<iostream>
using namespace std;
struct Student{
    char name[50];
    int numsubjects;
    int *marks;

    double average(){
        int sum=0;
        for(int i=0;i<numsubjects;i++){
            sum+=marks[i];
        }
        int average=sum/numsubjects;
        return (numsubjects > 0) ? (double)sum / numsubjects : 0.0;
    }

};

void studdentInput(Student students[], int numStudents){
    for(int i=0;i<numStudents;i++){
        cout<<"Enter the name of the student "<<i+1<<" :";
        cin.ignore();
        cin.getline(students[i].name,50);

        cout<<"Enter Number of Subjects: ";
        cin>>students[i].numsubjects;

        students[i].marks=new int [students[i].numsubjects];

        cout<<"Enter "<<students[i].numsubjects<<" Subject Marks: ";
        for(int j=0;j<students[i].numsubjects;j++){
            cin >> students[i].marks[j];
        }
    }
}

void SortStudents(Student students[],int numstudents){
    for(int i=0;i<numstudents;i++){
        for(int j=i+1;j<numstudents;j++){
            if(students[j].average()> students[i].average()){
               swap(students[i],students[j]);
            }
        }
    }
}
int main(){
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;
    Student* students = new Student[numStudents];
    
    studdentInput(students,numStudents);

    SortStudents(students,numStudents);

    cout << "\nStudent Averages:\n";
    for (int i = 0; i < numStudents; i++) {
        cout << students[i].name << " - Average Score: " << students[i].average() << endl;
    }

    cout << "\nTop Student:\n";
    cout << students[0].name << " - Highest Average Score: " << students[0].average() << endl;

    for (int i = 0; i < numStudents; i++) {
        delete[] students[i].marks;
    }

return 0;
}