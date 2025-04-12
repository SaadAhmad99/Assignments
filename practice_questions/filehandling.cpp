#include<iostream>
using namespace std;
#include<string>
#include<fstream>

void info(ofstream &outfile){
    string name;
    cout<<"Enter your Name :";
    getline(cin,name);

    int rollno;
    cout<<"Enter Your Roll No :";
    cin>>rollno;

    string hobbies;
    cout<<"Enter Your Hobbies :";
    cin.ignore();
    getline(cin,hobbies);

    outfile<<"Name :"<<name<<endl;
    outfile<<"Roll No. :"<<rollno<<endl;
    outfile<<"Hobbies :"<<hobbies<<endl;
}
void age(ofstream &outfile){
    int age[1]; // Single-element array (unnecessary but kept as per the question)
    cout<<"Enter your age :";
    cin>>age[0];

    outfile<<"Age : "<<age[0]<<endl;
}

int main(){
string your_rollno;
cout<<"Enter your File Name :";
getline(cin,your_rollno);
ofstream outfile(your_rollno+".txt");
if (outfile.is_open()){
    info(outfile);
    age(outfile);
    cout<<"File with the name "<<your_rollno<<" is created successfully "<<endl;
}else{
    cerr<<"Failed to create the file ";
}
outfile.close();

return 0;
}