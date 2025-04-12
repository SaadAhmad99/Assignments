#include<iostream>
using namespace std;

struct Rectangle{
    float length;
    float width;
};

float CalculateArea(Rectangle rec){
    return rec.length*rec.width;
}
int main(){
    Rectangle rec;
    cout<<"Enter the length: ";
    cin>>rec.length;
    cout<<"Enter the width: ";
    cin>>rec.width;

    cout<<"\nThe Area is "<<CalculateArea(rec)<<" meter square";

return 0;
}