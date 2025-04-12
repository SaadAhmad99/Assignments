#include<iostream>
using namespace std;
class Employee{
public:
    string name;
    int empId;
    float salary;

    Employee(string n,int id, float s){
        name=n;
        empId=id;
        salary=s;
    }

};
class Manager : public Employee{
public: 
    string department;

    Manager(string n,int id,float s,string dep) : Employee(n,id,s),department(dep){}

    void display(){
        cout<<"Employee Name: "<<name<<endl;
        cout<<"Employee Id: "<<empId<<endl;
        cout<<"Employee Salary: "<<salary<<endl;
        cout<<"Department is: "<<department<<endl;
    }
};
int main(){
    Manager m1("Saad Ahmad",3009,50000.0,"Software Engineering");
    m1.display();

return 0;
}