#include<iostream>
using namespace std;
struct Book{
    string title;
    string author;
    int price;
};

int main(){
    Book B1[5];
    for(int i=0;i<5;i++){
        cout<<"\nEnter the title of the book "<<i+1<<": ";
        cin.ignore();
        getline(cin,B1[i].title);
        cout<<"Enter the Author Name: ";
        getline(cin,B1[i].author);
        cout<<"Enter the Price of the Book: ";
        cin>>B1[i].price;
    }
    cout<<endl;

    for(int i=0;i<5;i++){
        if(B1[i].price > 500){
            cout<<"The book price graeater than 500 is "<<B1[i].title<<" by "<<B1[i].author<<" price is "<<B1[i].price<<"$"<<endl;
        }
    }


return 0;
}