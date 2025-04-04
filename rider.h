#include"user.h"
#pragma once
#include<iostream>
using namespace std;

class Rider:public User{

    public:
    Rider(int _id, string _name, string _phone) : User(_id, _name, _phone) {}
    void request_ride();
    void display_Info();
};
