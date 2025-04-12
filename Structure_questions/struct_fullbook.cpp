#include<iostream>
using namespace std;
struct Book{
    string title;
    string author;
    float price;
};
void details(Book *b1, int n){
    cout<<"\n----Enter Book Details----"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter the title of the book "<<i+1<<": ";
        cin.ignore();
        getline(cin,b1[i].title);
        cout<<"Enter the Author Name: ";
        getline(cin,b1[i].author);
        cout<<"Enter the Price of the Book: ";
        cin>>b1[i].price;
    }
}
void display(Book *b1, int n){
    for(int i=0;i<n;i++){
        cout<<"\nThe title of the book "<<i+1<<": "<<b1[i].title<<endl;        
        cout<<"The Author Name: "<<b1[i].author<<endl;
        cout<<"The Price of the Book: "<<b1[i].price<<endl;
    }
}
void expensive(Book *b1,int n){
    for(int i=0;i<n;i++){
        Book expensive=b1[0];
        if(b1[i].price>expensive.price){
            expensive=b1[i];
        }
    }
    cout<<"The expensive book is Book Number: "<<expensive<<endl;
}

int main(){
    int n;
    cout<<"Enter number of Books: ";
    cin>>n;
    Book *b1=new Book[n];

    details(b1,n);

    cout<<"\n-----Book Details----- "<<endl;
    display(b1,n);

    expensive(b1,n);

    delete[] b1;
    b1=NULL;

return 0;
}