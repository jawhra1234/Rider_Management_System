#include<iostream>
#include"rider.h"
#include"driver.h"
#include<vector>
#include"location.h"

#pragma once
class RideManager {
    private:
        static RideManager* instance; 
        RideManager();
        LocationGraph locationGraph;
    
    public:
        static RideManager* getInstance();
        void assignRide(Rider* rider,std::vector<Driver*>& drivers);
        Driver* findNearestDriver(Rider* rider, std::vector<Driver*>& drivers);
        void CompleteRide(Driver* driver);
        void addLocationData();
    };
    