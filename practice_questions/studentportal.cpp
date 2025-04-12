#include<iostream>
using namespace std;
#include<string>

void addstudent(string &name,int &rollno){
    cout<<"Enter the name of the student ";
    cin>>name;
    cout<<"Enter the roll no of the new student ";
    cin>>rollno;
}

void Display(string names[],int rollnos[],int marks[][3],int student){
    cout<<"Displaying All students "<<endl;
    for(int i=0;i<student;i++){
        cout<<"Student "<<i+1<<" :"<<endl;
        cout<<"Name :"<<names[i]<<endl;
        cout<<"Roll No. :"<<rollnos[i]<<endl;
        cout<<"Marks :";
        for(int j=0;j<3;j++){
            cout<<marks[i][j]<<" ";
        }
    cout<<endl;
    }
}

void Average(int marks[][3],int student){
    cout<<"Calculating averge marks for each student "<<endl;
    for(int i=0;i<student;i++){
        int total=0;
        for(int j=0;j<3;j++){
        total = total+marks[i][j];
        }
        double average=total/3.0;
        cout<<"Student "<<i+1<<"average marks "
        <<average<<endl;
        
    }
}

void highest(int marks[][3], string name[],int student){
int highesttotal=0,highestindex=0;
    for(int i=0;i<student;i++){
        int total=0;
        for(int j=0;j<3;j++){
            total = total+marks[i][j];
        }
        if(total>highesttotal){
            highesttotal = total;
            highestindex = i;
        }
    }
    cout<<"Student with the highest total marks:"<<endl;
    cout<<"Name: "<< name[highestindex]<<endl;
    cout<<"Total Marks: "<<highesttotal<<endl;
}

int main(){

    int maxstudent=5;
    string name[maxstudent];
    int rollno[maxstudent];
    int marks[maxstudent][3];
    int student=0;

while (true){

    cout<<"---- Student Information Portal---- "<<endl;
    cout<<"1. Add student "<<endl;
    cout<<"2. Display All Student "<<endl;
    cout<<"3. Calculating Average "<<endl;
    cout<<"4. Find Highest Marks "<<endl;
    cout<<"5. Exit "<<endl;
    int choice;
    cout<<"Enter your choice ";
    cin>>choice;

    switch (choice)
    {
        case 1:
            addstudent(name[student], rollno[student]);
                cout << "Enter marks for 3 subjects:\n";
                    for(int j=0;j<3;j++){
                        cout<<"Subject "<<j+1<<": ";
                        cin>>marks[student][j];
                    }
                    student++;
            break;

        case 2:
            Display(name, rollno,marks,student);
            break;

        case 3:
            Average(marks, student);
            break;

        case 4:
            highest(marks, name, student);
            break;

        case 5:
            cout<<"Exiting the program"<<endl;
            return 0;

        default:
            cout<<"Invalid choice. Please try again"<<endl;
    }
}

return 0;
}