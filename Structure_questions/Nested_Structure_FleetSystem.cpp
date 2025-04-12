#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct VehicleRecord {
    int vehicleID;
    float fuelStatus;
    time_t lastReportedTime;
    string vehicleCategory;

    VehicleRecord(int id, float fuel, const string &category) {
        vehicleID = id;
        fuelStatus = fuel;
        lastReportedTime = time(0);
        vehicleCategory = category;
    }
};

struct RegionRecord {
    int regionCode;
    int totalVehicles;
    VehicleRecord **vehicleList;

    RegionRecord(int code) {
        regionCode = code;
        totalVehicles = 0;
        vehicleList = nullptr;
    }

    ~RegionRecord() {
        for (int i = 0; i < totalVehicles; i++) {
            delete vehicleList[i];
        }
        delete[] vehicleList;
    }

    void insertVehicle(VehicleRecord *newVehicle) {
        VehicleRecord **updatedList = new VehicleRecord *[totalVehicles + 1];
        int i = 0;
        while (i < totalVehicles && vehicleList[i]->fuelStatus <= newVehicle->fuelStatus) {
            updatedList[i] = vehicleList[i];
            i++;
        }
        updatedList[i] = newVehicle;
        for (i; i < totalVehicles; i++) {
            updatedList[i + 1] = vehicleList[i];
        }
        delete[] vehicleList;
        vehicleList = updatedList;
        totalVehicles++;
    }

    VehicleRecord *getLowestFuelVehicle() {
        if (totalVehicles == 0)
            return nullptr;
        return vehicleList[0];
    }

    void purgeInactiveVehicles(int duration) {
        time_t currentTime = time(0);
        int activeCount = 0;
        VehicleRecord **updatedList = new VehicleRecord *[totalVehicles];

        for (int i = 0; i < totalVehicles; i++) {
            double timeElapsed = (currentTime - vehicleList[i]->lastReportedTime) / 3600.0;
            if (timeElapsed < duration) {
                updatedList[activeCount++] = vehicleList[i];
            } else {
                delete vehicleList[i];
            }
        }

        delete[] vehicleList;
        vehicleList = updatedList;
        totalVehicles = activeCount;
    }
};

struct FleetControl {
    int totalRegions;
    RegionRecord **regionList;

    FleetControl() {
        totalRegions = 0;
        regionList = nullptr;
    }

    ~FleetControl() {
        for (int i = 0; i < totalRegions; i++) {
            delete regionList[i];
        }
        delete[] regionList;
    }

    void createRegion(int code) {
        for (int i = 0; i < totalRegions; i++) {
            if (regionList[i]->regionCode == code) return;
        }
        RegionRecord **updatedList = new RegionRecord *[totalRegions + 1];
        for (int i = 0; i < totalRegions; i++) {
            updatedList[i] = regionList[i];
        }
        updatedList[totalRegions] = new RegionRecord(code);
        delete[] regionList;
        regionList = updatedList;
        totalRegions++;
    }

    RegionRecord *locateRegion(int code) {
        for (int i = 0; i < totalRegions; i++) {
            if (regionList[i]->regionCode == code)
                return regionList[i];
        }
        return nullptr;
    }
};

int main() {
    FleetControl fleetSystem;
    int userChoice;
    while (true) {
        cout << "\n--- Select Option ---\n";
        cout << "1: Register A New Region" << endl;
        cout << "2: Register A Vehicle" << endl;
        cout << "3: Retrieve Vehicle with Lowest Fuel" << endl;
        cout << "4: Remove Inactive Vehicles" << endl;
        cout << "5: Exit" << endl;
        cout << "Enter your choice: ";
        cin >> userChoice;
        if (userChoice == 5) break;

        if (userChoice == 1) {
            int code;
            cout << "Enter region code: ";
            cin >> code;
            fleetSystem.createRegion(code);
        } else if (userChoice == 2) {
            int code, id;
            float fuel;
            string category;
            cout << "Enter region code: ";
            cin >> code;
            cout << "Enter vehicle ID: ";
            cin >> id;
            cout << "Enter fuel level: ";
            cin >> fuel;
            cout << "Enter vehicle category: ";
            cin >> category;

            RegionRecord *region = fleetSystem.locateRegion(code);
            if (!region) {
                fleetSystem.createRegion(code);
                region = fleetSystem.locateRegion(code);
            }
            region->insertVehicle(new VehicleRecord(id, fuel, category));
        } else if (userChoice == 3) {
            int code;
            cout << "Enter region code: ";
            cin >> code;
            RegionRecord *region = fleetSystem.locateRegion(code);
            if (region) {
                VehicleRecord *lowFuelVehicle = region->getLowestFuelVehicle();
                if (lowFuelVehicle) {
                    cout << "Lowest Fuel Vehicle - ID: " << lowFuelVehicle->vehicleID << ", Fuel: " << lowFuelVehicle->fuelStatus << "L, Category: " << lowFuelVehicle->vehicleCategory << endl;
                } else {
                    cout << "No vehicles in this region." << endl;
                }
            } else {
                cout << "Region not found." << endl;
            }
        } else if (userChoice == 4) {
            int code, duration;
            cout << "Enter region code: ";
            cin >> code;
            cout << "Enter inactive duration (hours): ";
            cin >> duration;

            RegionRecord *region = fleetSystem.locateRegion(code);
            if (region) {
                region->purgeInactiveVehicles(duration);
                cout << "Inactive vehicles removed." << endl;
            } else {
                cout << "Region not found." << endl;
            }
        }
    }
    return 0;
}
