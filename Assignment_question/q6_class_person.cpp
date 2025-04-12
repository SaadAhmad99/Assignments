#include<iostream>
using namespace std;
#include<cstring>
class Person{
public:
    char *name;

    Person(const char *n){
        name= new char[strlen(n)+1];
        strcpy(name,n);
    }

    //shallow copy constructor
    Person(const Person& p){
        name=p.name;
    }

    //deep copy constuctor
    Person & operator=(const Person& p){
        if(this != &p){
            delete[] name;
            name= new char[strlen(p.name)+1];
            strcpy(name,p.name);
        }
        return *this;
    }

    void display(){
        cout<<"The Person Name is "<<name<<endl;
    }

};
int main(){
    Person p1("Saad"); 
    p1.display();

    //shallow copy
    Person p2=p1;
    p2.display();

    //deep copy using assignment operator
    Person p3("Ahmad");
    p3=p1; 
    p3.display();


return 0;
}