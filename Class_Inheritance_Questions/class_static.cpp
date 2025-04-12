#include<iostream>
#include<string>
using namespace std;
class Logger{
public:
    static string logs[10];
    static int count;

    static void log(const string &message){
        if(count<10){
            logs[count]=message;
            count++;
        }else{
            cout<<"Log storage Full "<<endl;
        }
    }

    static void printlogs(){
        cout<<"Stored log Messages "<<endl;
        for(int i=0;i<count;i++){
            cout<<i+1<<". "<<logs[i]<<endl;
        }
    }
};

string Logger::logs[10];
int Logger::count=0;

int main(){
    Logger::log("App Started. ");
    Logger::log("User Logged In. ");
    Logger::log("Wifi Connected. ");
    Logger::log("User Logged Out. ");
    Logger::log("Shutdown. ");

    Logger::printlogs();

return 0;
}