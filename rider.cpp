#include"rider.h"
#include<iostream>
using namespace std;


void Rider::request_ride(){
    cout<<"Ride Requested...\n";
}
void Rider::display_Info(){
    cout << "Rider: " << name << " (phone: " << phone << ")\n";
}
