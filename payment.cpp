#include"payment.h"
#include<iostream>

double Payment::calculateFare(int distance){
    return 50+(distance*10);
}