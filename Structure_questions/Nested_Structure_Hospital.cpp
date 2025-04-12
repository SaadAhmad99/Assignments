#include<iostream>
using namespace std;
struct Doctor{
    string fullname;
    string specialization;
    int experience;
};
struct Patient{
    string name;
    int id;
    string disease;
    Doctor doc;

};
struct Hospital{
    string name;
    string location;
    int totalPat;
    Patient *patient;
};

void AdmitPatient(Hospital *hosp){
    Patient *newpat = new Patient[hosp->totalPat+1];
    for(int i=0;i<hosp->totalPat;i++){
        newpat[i]=hosp->patient[i];
    }
    cin.ignore();
    cout<<"Enter Patient Name: ";
    getline(cin,newpat[hosp->totalPat].name);

    cout<<"Enter Patient ID: ";
    cin>>newpat[hosp->totalPat].id;

    cin.ignore();
    cout<<"Enter the disease of Patient: ";
    getline(cin,newpat[hosp->totalPat].disease);

    cout<<"Enter The Doctor Name: ";
    getline(cin,newpat[hosp->totalPat].doc.fullname);

    cout<<"Enter the Doctor Specilization: ";
    getline(cin,newpat[hosp->totalPat].doc.specialization);

    cout<<"Enter the Doctor Experience: ";
    cin>>newpat[hosp->totalPat].doc.experience;
    cin.ignore();

    delete[] hosp->patient;
    hosp->patient=newpat;
    hosp->totalPat++;

}
void display(Hospital *hosp){
    cout<<"----List of Patients---"<<endl;
    for(int i=0;i<hosp->totalPat;i++){
        cout<<"Patient Name: "<<hosp->patient[i].name<<endl;
        cout<<"Patient ID: "<<hosp->patient[i].id<<endl;
        cout<<"Patient Disease: "<<hosp->patient[i].disease<<endl;
        cout<<"Assigned Doctor Name: "<<hosp->patient[i].doc.fullname<<endl;
        cout<<"Assigned Doctor Specialization: "<<hosp->patient[i].doc.specialization<<endl;
        cout<<"Assigned Doctor Experience: "<<hosp->patient[i].doc.experience<<" years"<<endl;
    }
}

void discharge(Hospital *hosp){
    int patientId;
    cout<<"Enter Patient ID: ";
    cin>>patientId;
    bool found=false;
    for(int i=0;i<hosp->totalPat;i++){
        if(hosp->patient[i].id==patientId){
            found=true;
            Patient *newpat = new Patient[hosp->totalPat-1];
            for(int j=0,k=0;j<hosp->totalPat;j++){
                if (hosp->patient[j].id != patientId){
                    newpat[k++] = hosp->patient[j];
                }
            }
            delete[] hosp->patient;
            hosp->patient=newpat;
            hosp->totalPat--;

            cout<<"Patient Discharged Successfully "<<endl;
            break;

        }
        if(!found){
            cout<<"Patient with "<<patientId<<" ID is not found"<<endl;
        }
    }
}

void clearData(Hospital* hosp) {
    delete[] hosp->patient;
    hosp->patient = nullptr;
    hosp->totalPat = 0;
}

int main(){
Hospital hosp;

cout<<"Enter Hospital Name: ";
getline(cin,hosp.name);

cout<<"Enter Hospital location: ";
getline(cin,hosp.location);

hosp.totalPat=0;
hosp.patient=NULL;

int choice;
    do{
        cout<<"-----Hospital anagement System-----"<<endl;
        cout<<"1. Admit a Patient"<<endl;
        cout<<"2. Display All Patients"<<endl;
        cout<<"3. Discharge a Patient"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            
            case 1:
            AdmitPatient(&hosp);
            cout<<"Patient Admit Successflly "<<endl;
            break;

            case 2:
            display(&hosp);
            break;

            case 3:
            discharge(&hosp);
            break;

            case 4:
            clearData(&hosp);
            cout<<"Exiting..."<<endl;
            break;

            default:
            cout<<"Invalid choice."<<endl;

        }
    }while(choice!=4);

    
return 0;
}