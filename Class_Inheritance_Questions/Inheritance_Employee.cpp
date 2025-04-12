#include<iostream>
using namespace std;
class Person{
private:
    string name;
    string address;
public:
    Person(string n,string add): name(n),address(add){}

    void setperson(string n,string add){
        name=n;
        address=add;
    }

    string getname(){
        return name;
    }
    string getAddress(){
        return address;
    }

};
class Employee: public Person{
private:
    int Emp_num;
    int hours_work;
public:
    Employee(string n,string add, int emp,int work):
        Person(n,add),Emp_num(emp),hours_work(work){}
    
    void setemployee(string n,string add, int emp,int work){
        setperson(n,add);
        Emp_num=emp;
        hours_work=work;
        
    }

    int getHoursworked(){
        return hours_work;
    }
    int getEmpNumber(){
         return Emp_num; 
        }

};
class ProductionWorker : public Employee{
private: 
    int shift;
    double hourly_pay_rate;
    double salary;
public:
    ProductionWorker(string n,string add, int emp,int work,int shf,double rate):
        Employee(n,add,emp,work),shift(shf),hourly_pay_rate(rate),salary(0){}

    void setworker(string n,string add, int emp,int work,int shf,double rate){
        setemployee(n,add,emp,work);
        shift=shf;
        hourly_pay_rate=rate;
        salary=0;
    }

    double calculatesalary(){
        salary=hourly_pay_rate*getHoursworked();
        if(shift==2 && getHoursworked()>5){
            salary=salary+1000;
            cout<<"\nBonus of 1000 is added for night shift"<<endl;
        }
        return salary;
    }

    void displaydetails(){
        cout<<"Employee Name     : "<<getname()<<endl;
        cout<<"Employee Address  : "<<getAddress()<<endl;
        cout<<"Employee Number   : "<<getEmpNumber()<<endl;
        cout<<"Total Work Hours  : "<<getHoursworked()<<endl;
        cout<<"Shift Time        : "<<(shift==1 ? "Day" : "Night")<<endl;
        cout<<"Hourly Pay Rate   : "<<hourly_pay_rate<<"$"<<endl;
        cout<<"Total Salary      : "<<salary<<"$"<<endl;
        cout<<endl;
    }
};
int main(){
    ProductionWorker emp("Saad", "Swat", 1, 6, 2, 20);
    emp.calculatesalary();
    emp.displaydetails();

return 0;
}