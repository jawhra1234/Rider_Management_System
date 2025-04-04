#include"driver.h"
#include<iostream>
using namespace std;


void Driver::acceptRide(){
    available=false;
    cout<<name<<"accepted a ride..\n";
}
void Driver::completeRide(){
    available=true;
    cout<<name<<"completed a ride..\n";
}
void Driver::display_Info(){
    cout << "Driver: " << name << " (Phone: " << phone << ")\n";
}