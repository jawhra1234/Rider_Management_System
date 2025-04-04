#include"location.h"
#include<iostream>
#include<queue>
#include<limits>
using namespace std;

void LocationGraph::addEdge(const string& from, const string& to, int distance) {
    adjList[from].push_back({to, distance});
    adjList[to].push_back({from, distance});  
}

string LocationGraph::findNearestDriver(const string& riderLocation ,const vector<string>&driverLocations){
          unordered_map<string,int>distances;
          priority_queue<pair<int,string>, vector<pair<int,string>>,greater<>>pq;

         for(const auto& node :adjList){
            distances[node.first]=numeric_limits<int>::max();
         }
         distances[riderLocation]=0;
         pq.push({0,riderLocation});
         int currentDistance;
         string currentLocation;
         while (!pq.empty())
         {
            pair<int,string>topElement=pq.top();
            currentDistance=topElement.first;
            currentLocation=topElement.second;
            pq.pop();
            
            for(auto& pair:adjList[currentLocation]){
               string neighbour=pair.first;
               int weight= pair.second;

               if(currentDistance+weight<distances[neighbour]){
                  distances[neighbour]=currentDistance+weight;
                  pq.push({distances[neighbour],neighbour});
               }
            }
         }
           string nearstDriver="";
           int minDistance=numeric_limits<int>::max();

           for(const string& driverLocation:driverLocations){
                 if(distances[driverLocation]<minDistance){
                  minDistance=distances[driverLocation];
                  nearstDriver=driverLocation;
                 }
           }
            
         return nearstDriver;
          
}
