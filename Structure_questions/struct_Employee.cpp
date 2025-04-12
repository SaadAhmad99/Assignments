#include<iostream>
using namespace std;
struct Employee{
    string name;
    int id;
    int salary;
};
int main(){
    Employee emp1, *p1;
    p1=&emp1;

    cout<<"Enter Employee name: ";
    getline(cin,p1->name);
    cout<<"Enter Employee ID: ";
    cin>>p1->id;
    cout<<"Enter Employee Salary: ";
    cin>>p1->salary;

    cout<<"\n------Employee Information------\n "<<endl;
    cout<<"Name is "<<p1->name<<", ID is "<<p1->id<<", Salary is "<<p1->salary<<endl;

return 0;
}