#include<iostream>
using namespace std;
struct Doctor{
    string name;
    string specialization;
};
struct Hospital{
    string name;
    Doctor doc[3];
};
void display(Hospital*hosp,int n){
    for(int i=0;i<n;i++){
        cout<<"Hospital "<<i+1<<" name is:"<<hosp[i].name<<endl;
        for(int j=0;j<3;j++){
            cout<<"\nDoctor "<<j+1<<" name is: "<<hosp[i].doc[j].name<<endl;
            cout<<"Its specialization is:"<<hosp[i].doc[j].specialization;
        }
    }
}
int main(){
    int n;
    cout<<"Enter number of hospitals: ";
    cin>>n;

    Hospital* hosp=new Hospital[n];
    
    for(int i=0;i<n;i++){
        cout<<"Enter Hospital "<<i+1<<" name:";
        cin>>hosp[i].name;
        for(int j=0;j<3;j++){
            cout<<"Enter doctor "<<j+1<<" name: ";
            cin.ignore();
            cin>>hosp[i].doc[j].name;
            cout<<"Enter its specialization:";
            cin>>hosp[i].doc[j].specialization;
        }
    }

    cout<<"\n----Hospital Details----"<<endl;
    display(hosp,n);

    delete[] hosp;


return 0;
}