#include<iostream>
using namespace std;
class Employee{
public:
    const float salary;
    int empID;

    Employee(int id) {
        empID=id;
        salary=50000;
        cout << "Address of current object: " << this<<endl;
    
        }
    
    void display(){
        cout<<"Employee ID: "<<empID<<" ,Employee Salary: "<<salary<<endl;
        cout << "Address of current object: " << this<<endl;

    }
};

int main(){
    Employee emp1(3009),emp2(3039);
    emp1.display();
    emp2.display();

return 0;
}