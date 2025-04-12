#include<iostream>
using namespace std;
class Employee{
private:
    static int count;

public:  
    Employee(){
        count++;
    }

    static void display(){
        cout<<"Total employee is "<<count<<endl;
    }

};
int Employee :: count =0;
int main(){
    Employee emp1, emp2, emp3;
    
    Employee::display();

return 0;
}