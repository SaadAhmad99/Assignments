#include<iostream>
using namespace std;

class CoffeOrder{
public:
    void ProcessOrder(int size,int price){
        cout<<"The total cost is: $"<<size*price<<endl;
    }
};
class CustomOrder : public CoffeOrder{
public:
    void ProcessOrder(int size,int price){
        cout<<"Thank you for choosing us. Enjoy your coffee."<<endl;
        CoffeOrder::ProcessOrder(size,price);
    }

};
int main(){
    int size,price;
    cout<<"Enter drink size in ounces: ";
    cin>>size;
    cout<<"Enter the price of drink in dollars: ";
    cin>>price;
    CoffeOrder standardorder;
    cout<<"\nStandard order "<<endl;
    standardorder.ProcessOrder(size,price);
    
    CustomOrder order;
    cout<<"Custom order "<<endl;
    order.ProcessOrder(size,price);

return 0;
}