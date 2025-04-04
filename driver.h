#include"user.h"
using namespace std;
#pragma once
class Driver : public User {
    public:
    bool available;
    Driver(int _id, string _name, string _phone) : User(_id, _name, _phone), available(true) {};
    void acceptRide();
    void completeRide();
    void display_Info ();
};