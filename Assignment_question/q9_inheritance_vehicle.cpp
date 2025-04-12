#include<iostream>
using namespace std;
class Vehicle{
public:
    void startengine(){
        cout<<"Vehicle engine started "<<endl;
    }

};
class Airplane : public Vehicle{
public:
    void startengine(){ //function overridding
        cout<<"Airplane engine started "<<endl; 
    }

};
int main(){
    Airplane plane;
    plane.startengine();

    //explicitly calling base class function
    plane.Vehicle::startengine();

return 0;
}