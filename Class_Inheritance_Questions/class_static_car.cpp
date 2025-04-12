#include<iostream>
using namespace std;

class Car{

public:   
    static int maxspeed;
    int currentspeed=0;

    void setspeed(int speed){
        currentspeed = speed;
        
        if(speed>maxspeed){
            maxspeed=speed;
        }
    }
    
    static int getmaxSpeed(){
        return maxspeed;
    }

    void display(){
        cout << "Current Speed: " << currentspeed << " km/h" << endl;

    }
};

int Car::maxspeed=0;

int main(){

    Car c1,c2,c3;

    c1.setspeed(200);
    c2.setspeed(350);
    c3.setspeed(300);

    c1.display();
    c2.display();
    c3.display();

    cout<<"Highest speed record "<<Car::getmaxSpeed()<<" km/h "<<endl;

return 0;
}