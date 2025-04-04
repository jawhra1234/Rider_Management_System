#include<iostream>
#include<string.h>
#include"user.h"

using namespace std;

User ::User(){
    id=0;
    name="Jawhra";
    phone="8297714786";
}
User ::User(int ID, string s , string e){
    id=ID;
    name=s;
    phone=e;
}
void User::display_Info(){
    cout<<"ID:"<<id;
    cout<<"\n"<<"Name:"<<name;
    cout<<"\n"<<"Phone:"<<phone;
}
