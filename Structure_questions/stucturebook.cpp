#include<iostream>
using namespace std;
#include<string>
struct Book{
    string title;
    string author;
    int pages;
    float price;
};

int main(){
    Book yourbook;

    cout<<"Enter The Title of the book: ";
    getline(cin, yourbook.title);

    cout<<"Name of the Author: ";
    getline(cin, yourbook.author);

    cout<<"Enter number of Pages: ";
    cin>>yourbook.pages;

    cout<<"Enter The Price of the book: ";
    cin>>yourbook.price;

    cout<<"\n----Book Details----"<<endl;
    cout<<"Title: "<<yourbook.title<<endl;
    cout<<"Author: "<<yourbook.author<<endl;
    cout<<"Pages: "<<yourbook.pages<<endl;
    cout<<"Price: "<<yourbook.price<<endl;

return 0;
}