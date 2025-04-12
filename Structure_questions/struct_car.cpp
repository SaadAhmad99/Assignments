#include<iostream>
using namespace std;
struct Car{
    string brand;
    int year;
    float price;


};
void updatePrice(Car *c,float discount){
    c->price=c->price-(c->price*(discount/100));
}
int main(){
    Car c;
    float discount;
    cout<<"Enter the Car Brand: ";
    getline(cin,c.brand);
    cout<<"Enter the year: ";
    cin>>c.year;
    cout<<"Enter the price of the car: ";
    cin>>c.price;
    cout<<"Enter for discount percentage: ";
    cin>>discount;

    updatePrice(&c,discount);
    cout<<"Updated Price of Car "<<c.brand<<" after discount is: "<<c.price<<" $"<<endl;

return 0;
}