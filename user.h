#include<iostream>
#pragma once
using namespace std;
class User{
    public:
   int id;
   string name;
   string phone;
   public:
    User();
    User(int , string , string);
   virtual void display_Info();
};