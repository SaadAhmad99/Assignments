#include<iostream>
using namespace std;
class Person{
private:
    string name;
    int age;
public:
    void setperson(string n,int a){
        name=n;
        age=a;
    }
    void getperson(){
        cout<<"Name: "<<name<<", Age: "<<age<<endl;
    }

};
class Student : public Person{
public:
     string grade;

     void setStudent(string n,int a, string g){
        setperson(n,a);
        grade=g;
     }

     void getStudent(){
        getperson();
        cout<<"Grade: "<<grade<<endl;
     }

};
int main(){
    Student s1;
    s1.setStudent("Saad",19,"A");
    s1.getStudent();

return 0;
}