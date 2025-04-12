#include<iostream>
using namespace std;
struct Professor{
    string name;
    string subjects;
};
struct Student{
    string fullname;
    int studentID;
    float marks;
};
struct Course{
   string title;
   Professor prof;
   Student *stud;
   int totalstudent;
};
struct University{
    Course *course;
    int totalcourses;
};

void addNewCourse(University *uni){
    Course *temp=new Course[uni->totalcourses+1];
    for(int i=0;i<uni->totalcourses;i++){
        temp[i]=uni->course[i];
    }
    cout<<"Enter Course Title: ";
    cin.ignore();
    getline(cin,temp[uni->totalcourses].title);

    cout<<"Enter Professor Name: ";
    getline(cin,temp[uni->totalcourses].prof.name);

    cout<<"Enter Subject he taught: ";
    getline(cin,temp[uni->totalcourses].prof.subjects);

    cout<<"Enter Number of Srudents for this course: ";
    cin>>temp[uni->totalcourses].totalstudent;
    cin.ignore();

    temp[uni->totalcourses].stud = new Student[temp[uni->totalcourses].totalstudent];

    for(int i=0;i<temp[uni->totalcourses].totalstudent;i++){
        cout<<"Enter Student "<<i+1<<" Name: ";
        getline(cin,temp[uni->totalcourses].stud[i].fullname);

        cout<<"Enter Student ID: ";
        cin>>temp[uni->totalcourses].stud[i].studentID;

        cout<<"Enter Student's Marks: ";
        cin>>temp[uni->totalcourses].stud[i].marks;
        cin.ignore();
    }
        delete[] uni->course;
        uni->course = temp;
        uni->totalcourses++;
    
}

void enrollStudent(Course *course){
    Student *temp=new Student[course->totalstudent+1];
    for(int i=0;i<course->totalstudent;i++){
        temp[i]=course->stud[i];
    }
    
    cin.ignore();
    cout<<"Enter New Student Name: ";
    getline(cin,temp[course->totalstudent].fullname);

    cout<<"Enter Student ID: ";
    cin>>temp[course->totalstudent].studentID;

    cout<<"Enter Student Marks: ";
    cin>>temp[course->totalstudent].marks;
    cin.ignore();

    delete[] course->stud;
    course->stud=temp;
    course->totalstudent++;
}

void displayAllCourses(const University* uni) {
    cout<<"\n========== Course List =========="<<endl;
    for (int i=0;i<uni->totalcourses;i++){
        cout<<"\nCourse Title: "<<uni->course[i].title<<endl;
        cout<<"Professor: "<<uni->course[i].prof.name<<" (Subject: " << uni->course[i].prof.subjects << ")"<<endl;

        cout<<"======== Students Enrolled ======"<<endl;
        for(int j=0;j<uni->course[i].totalstudent;j++){
            cout<< "  - "<<uni->course[i].stud[j].fullname
            <<" (ID: "<<uni->course[i].stud[j].studentID
            <<", Marks: "<<uni->course[i].stud[j].marks<<")"<<endl;
        }
        cout << "-------------------------------"<<endl;
    }
}

void ModifyStudentMarks(Course *course){
    int searchId;
    cout<<"Enter student ID to search: ";
    cin>>searchId;

    for(int i=0;i<course->totalstudent;i++){
        if(course->stud[i].studentID==searchId){
            cout<<"Enter New marks for "<<course->stud[i].fullname;
            cin>>course->stud[i].marks;
            cout<<"Marks Updated successfully "<<endl;
            return ;
        }
    }
    cout<<"Student with "<<searchId<<" not found "<<endl;
}

void RemoveStudentFromCourse(Course *course){
    int searchId;
    cout<<"Enter Student ID to remove ";
    cin>>searchId;
    int index=-1;
    for(int i=0;i<course->totalstudent;i++){
        if(course->stud[i].studentID==searchId){
            index=i;
            break;
        }

    }
    if(index=-1){
        cout<<"Student not found "<<endl;
        return ;
    }
    Student *temp=new Student[course->totalstudent-1];
    for(int i=0,j=0;course->totalstudent;i++){
        if(i!=index){
            temp[j++]=course->stud[i];
        }
    }

    delete[] course->stud;
    course->stud = temp;
    course->stud--;
    cout<<"Student removed successfully"<<endl;

}


int main(){
    University uni;
    uni.totalcourses=0;
    uni.course=nullptr;
    int choice;
do
{
    cout << "\n========== Course Management System =========="<<endl;
    cout << "1. Add New Course"<<endl;
    cout << "2. Enroll Student in a Course"<<endl;;
    cout << "3. Display All Courses and Students"<<endl;
    cout << "4. Update Student Marks"<<endl;
    cout << "5. Remove Student from a Course"<<endl;
    cout << "6. Exit"<<endl;;
    cout << "Enter Your Choice: ";
    cin >> choice;
    switch(choice){
        case 1:
        addNewCourse(&uni);
        break;
        case 2:
                int courseIndex;
                cout<<"Enter Course Index to Enroll a Student: ";
                cin>>courseIndex;
                if(courseIndex >= 0 && courseIndex < uni.totalcourses)
                    enrollStudent(&uni.course[courseIndex]);
                else
                    cout<<"Invalid Course Index"<<endl;
                break;
        case 3:
                displayAllCourses(&uni);
                break;
        case 4:
                cout<<"Enter Course Index to Update Marks: ";
                cin>>courseIndex;
                if(courseIndex >= 0 && courseIndex < uni.totalcourses)
                ModifyStudentMarks(&uni.course[courseIndex]);
                else
                cout<<"Invalid Course Index"<<endl;
                break;
        case 5:
                cout<<"Enter Course Index to Remove a Student: ";
                cin>>courseIndex;
                if (courseIndex >= 0 && courseIndex < uni.totalcourses)
                RemoveStudentFromCourse(&uni.course[courseIndex]);
                else
                cout << "Invalid Course Index"<<endl;
                break;
        case 6:
                cout<<"Exiting......."<<endl;
                break;
        default:
                cout<<"Invalid Choice Try Again"<<endl;
    }
} while (choice!=6);
delete[] uni.course;

return 0;
}