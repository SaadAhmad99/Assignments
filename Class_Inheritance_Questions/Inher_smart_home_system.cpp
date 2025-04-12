#include<iostream>
using namespace std;
class Device{
public:
    string deviceName;
    bool powerStatus;
    string location;

    Device(string name,string loc): deviceName(name),location(loc),powerStatus(false){}

    void turnOn(){
        powerStatus=true;
        cout<<"\n"<<deviceName<<" is On Now "<<endl;
    }

    void turnOff(){
        powerStatus=false;
        cout<<deviceName<<" is Off Now "<<endl;
    }

    void ShowStatus(){
      cout<<"Device: "<<deviceName<<", Location "<<location
      <<", Status: "<<(powerStatus?"ON":"OFF")<<endl;
    }
};
class SmartLight : public Device{
public:
    int brightness;
    string color;

    SmartLight(string name,string loc,int bright,string col)
    :Device(name,loc),brightness(bright),color(col){}

    void adjustBrightness(int level){
        brightness=level;
        cout<<deviceName<<" Brightness level cjange to "<<level<<" %"<<endl;
    }

    void changeColor(string newcolor){
        color=newcolor;
        cout<<deviceName<<" Color Change to "<<color<<endl;
    }
};
class SmartThermostate : public Device{
public:
    float temperature;
    string mode;

    SmartThermostate(string name,string loc,float temp,string mod)
    :Device(name,loc),temperature(temp),mode(mod){}

    void setTemperature(float temp){
        temperature=temp;
        cout<<deviceName<<" temperature is set to "<<temperature<<" C"<<endl;

        if (temperature<18){
            switchMode("Heat");
        }else{
            switchMode("Cool");
        }
    }

    void switchMode(string newMode){
        mode=newMode;
        cout<<deviceName<<" switched to "<<mode<<" mode"<<endl;
    }
};
class SmartSecurityCamera : public Device{
public:
    string resolution;
    bool recordingStatus;

    SmartSecurityCamera(string name,string loc,string resol)
    : Device(name,loc),resolution(resol),recordingStatus(false){}

    void StartRecording(){
        recordingStatus=true;
        cout<<deviceName<<" Starts Recording in "<<resolution<<endl;
    }

    void StopRecording(){
        recordingStatus=false;
        cout<<deviceName<<" Stopped Recording."<<endl;
    }

    void viewFeed(){
        if(powerStatus){
            cout<<"Live Feed from "<<deviceName<<" ("<<resolution<<" resolution)"<<endl;
        }else{
            cout<<"Cannot view feed! "<<deviceName<<" is OFF"<<endl;
        }

    }

};
int main(){
    SmartLight light("Bedroom Light","Bedroom",100,"Yellow");
    light.turnOn();
    light.adjustBrightness(50);
    light.changeColor("White");
    light.ShowStatus();
    light.turnOff();

    cout<<"----------------------"<<endl;

    SmartThermostate thermostate("House Thermostate","Dining Room",18,"Auto");
    thermostate.turnOn();
    thermostate.setTemperature(16);
    thermostate.setTemperature(22);
    thermostate.ShowStatus();
    thermostate.turnOff();

    cout<<"----------------------"<<endl;

    SmartSecurityCamera camera("Main Gate Camera","Entrance","8k");
    camera.turnOn();
    camera.viewFeed();
    camera.StartRecording();
    camera.StopRecording();
    camera.turnOff();



return 0;
}