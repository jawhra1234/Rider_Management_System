#include<iostream>
#include"ridermanager.h"
#include<vector>
#include<climits>
#include"payment.h"
#include<fstream>
#include<map>
using namespace std;
RideManager* RideManager::instance = nullptr;  


RideManager* RideManager::getInstance() {
    if (!instance) instance = new RideManager();
    return instance;
}

RideManager::RideManager() {
    // Any required initialization
}
void RideManager::addLocationData() {
    locationGraph.addEdge("A", "B", 5);
    locationGraph.addEdge("A", "C", 10);
    locationGraph.addEdge("B", "D", 15);
    locationGraph.addEdge("C", "D", 7);
}

/*void RideManager::assignRide(Rider* rider, vector<Driver*>& drivers) {
   Driver* nearstDriver=findNearestDriver(rider,drivers);
   
   if(nearstDriver){
    int distance = rand() % 10 + 1;
    double fare = Payment::calculateFare(distance);
    cout<<"Ride assigned to:"<<nearstDriver->name<<" At a Distance:"<<distance<<"km/h "<<"At a Fare of $"<<fare<<"\n";
    nearstDriver->available=false;
       
      ofstream file("ride_history.txt",ios::app);
      file<<"Rider: "<<rider->name
          <<"Driver: "<<nearstDriver->name
          <<"Distance: "<<distance
          <<"Fare: "<<fare;
      file.close();    

   }
   else{
    cout<<"no drivers available Please Try Later!..\n";
   }

}
*/
void RideManager::assignRide(Rider* rider, std::vector<Driver*>& drivers) {
    std::vector<std::string> driverLocations;
    for (const auto& driver : drivers) {
        if (driver->available) {
            driverLocations.push_back(driver->name);
        }
    }

    std::string nearestDriverName = locationGraph.findNearestDriver(rider->name, driverLocations);

    Driver* nearestDriver = nullptr;
    for (auto& driver : drivers) {
        if (driver->name == nearestDriverName) {
            nearestDriver = driver;
            break;
        }
    }

    if (nearestDriver) {
        int distance = rand() % 10 + 1;
        double fare = Payment::calculateFare(distance);

        std::cout << "Ride assigned to: " << nearestDriver->name 
                  << " (Distance: " << distance << " km, Fare: ₹" << fare << ")\n";
        nearestDriver->available = false;

        
        std::ofstream file("ride_history.txt", std::ios::app);
        file << "Rider: " << rider->name 
             << " → Driver: " << nearestDriver->name
             << " | Distance: " << distance 
             << " km | Fare: ₹" << fare << "\n";
        file.close();
    } else {
        std::cout << "No available drivers. Please try again later.\n";
    }
}
Driver* RideManager::findNearestDriver(Rider *rider ,std::vector<Driver*>& drivers){
    Driver* nearestDriver=nullptr;
    int minDistance=INT_MAX;

    for(Driver* driver:drivers){
        if(driver->available){
            int distance=rand()%10+1;
            if(distance<minDistance){
                minDistance=distance;
                nearestDriver=driver;
            }
        }
    }
    return nearestDriver;
}
void RideManager::CompleteRide(Driver* driver){
    driver->available=true;
    cout<<driver->name<<" is available for rides now..\n";
}