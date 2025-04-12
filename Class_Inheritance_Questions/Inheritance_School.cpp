#include<iostream>
using namespace std;
class Student{
public:   
    int rollNo;
    string name;

    Student(int no,string stname){
        rollNo=no;
        name=stname;
        cout<<"Student constructor called "<<endl;
    }

};
class Marks{
public:   
    int sub1,sub2,sub3;

    Marks(int m1,int m2, int m3){
        sub1=m1;
        sub2=m2;
        sub3=m3;
        cout<<"Marks constructor called "<<endl;
    }

};
class Show: public Marks,public Student{
public:
    Show(int no,string stname,int m1,int m2, int m3):Marks(m1,m2,m3),Student(no,stname){
        cout<<"show constructor called "<<endl;
    }
    void display(){
        cout<<"Name "<<name<<endl;
        cout<<"roll no "<<rollNo<<endl;
        cout<<"subject 1 marks"<<sub1<<endl;
        cout<<"subject 2 marks"<<sub2<<endl;
        cout<<"subject 3 marks"<<sub3<<endl;
        int total=sub1+sub2+sub3;
        float percentage=total/3.0;
        cout<<"The total marks is "<<total<<endl;
        cout<<"The percentage is "<<percentage<<" %"<<endl;
    }
};
int main(){
    Show obj(3009,"saad",34,56,76);
    obj.display();

return 0;
}