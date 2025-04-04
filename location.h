#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<climits>
#include<map>
#pragma once
using namespace std;

class LocationGraph{
    
    private:
      unordered_map<string , vector<pair<string , int>>>adjList;

      public:

      void addEdge(const string& from, const string& to,int distance);
      string findNearestDriver(const string &riderLocation,const vector<string>&driverLocations);
     
};