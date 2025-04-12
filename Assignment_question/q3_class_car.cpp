#include<iostream>
using namespace std;
class Car{
public:
    string model;
    int year;

    Car(string mod,int y){
        model=mod;
        year=y;
        cout<<"Object of Car Model "<<model<<" of "<<year<<" is created"<<endl;
    }

    ~Car(){
        cout<<"Object of Car Model "<<model<<" of "<<year<<" is Destroyed"<<endl;
    }
};
int main(){
    Car c1("BMW i7", 2023);
    Car c2("Audi R8", 2024);

return 0;
}