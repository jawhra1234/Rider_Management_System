#include<iostream>
#include"driver.h"
#include"rider.h"
#include"ridermanager.h"
#include<vector>
#include<thread>
#include"location.h"

using namespace std;


void handleRide(RideManager *manager,Rider* rider,vector<Driver*> &drivers){
   manager->assignRide(rider,drivers);
}

int main() {
    RideManager* rm = RideManager::getInstance();
    rm->addLocationData();
   vector<Driver*>drivers={
       new Driver(1,"Ramu","8787292038"),
       new Driver(2,"Srinu","023093898"),
       new Driver(3,"Raju","9934567890")
   };

   Rider r1(101, "John", "8297714786");
   Rider r2(102, "Jane", "9988776655");
   rm->assignRide(&r1,drivers); 
   rm->CompleteRide(drivers[0]);
   rm->assignRide(&r2,drivers);
   rm->CompleteRide(drivers[1]);
   
   /*thread t1(handleRide,rm,&r1,ref(drivers));
   thread t2(handleRide,rm,&r2,ref(drivers));

   t1.join();
   t2.join();*/
   
   for (auto d : drivers) delete d;
    return 0;
}