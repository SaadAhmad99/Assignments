#include<iostream>
using namespace std;
int Rentalcompany(int days,double miles){
    int feeperday=25;
    double permile=0.15;
    double Basefee=feeperday*days;
    double milecost=permile*miles;
    double total = Basefee+milecost;
    if (days>30){
        double discount = 0.20*Basefee;
        double discbasefee=Basefee-discount;
        double totalcost=discbasefee+milecost;
        cout<<"Total after discount is "<<totalcost<<"$"<<endl;
    }
    else if (days<15){
        double additionalcharges=1.99*days;
        double totalbill=Basefee+milecost+additionalcharges;
        cout<<"So total for "<<days<<" days and "<<miles<<" miles is "<<totalbill<<"$"<<endl;
    }
    else{
        cout<<"So the totals dollar per day for rental company is "<<total<<" $"<<endl;
    }
    return total;
}
int main(){
     int days;
    double miles;
    cout<<"How many days you drive :";
    cin>>days;
    cout<<"How many miles you drive ";
    cin>>miles;
    double totaldollar=Rentalcompany(days,miles);


return 0;
}