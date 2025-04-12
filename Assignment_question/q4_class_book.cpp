#include<iostream>
using namespace std;
class Book{
public:
    string book_title;
    string author_name;

    Book(string title,string name){
        book_title=title;
        author_name=name;
    }

    void display(){
        cout<<"Title of Book is "<<book_title<<" and the Author name is "<<author_name<<endl;
    }
};
int main(){
    Book *ptr=new Book("Hero To Zero","Saad");
    ptr->display();

    delete ptr;
    ptr=nullptr;

return 0;
}