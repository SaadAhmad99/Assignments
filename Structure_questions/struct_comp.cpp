#include<iostream>
using namespace std;
struct Address{
    string city;
    int zip;
};
struct Company{
    string name;
    float revenue;
    Address add;
};
int main(){
    Company comp[3]={
        {"SpaceX",40000,{"New York",4009}},
        {"Tesla",200000,{"Washington",1600}},
        {"Toyota",12000,{"Sydney",2200}}
    };

    for(int i=0;i<3;i++){
        cout<<comp[i].name<<" revenue is "<<comp[i].revenue<<", located in "<<comp[i].add.city<<" and zip is "<<comp[i].add.zip<<endl;
    }
        


return 0;
}