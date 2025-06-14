#include<iostream> 
#include<vector> 
#include<queue>
#include<unordered_set>
#include<numeric> 
#include<algorithm> 
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        //if we’re already at the destination, exit 
        if (source == target) return 0;

        int routeCount = routes.size();

        // Map each bus stop to all the routes passing through it
        unordered_map<int, vector<int>> stopToRoutesMap;
        for (int r = 0; r < routeCount; ++r) {
            for (int stop : routes[r]) {
                stopToRoutesMap[stop].push_back(r);
            }
        }

        unordered_set<int> visitedStops;     // to avoid revisiting stops
        vector<bool> routeUsed(routeCount, false);  // to avoid taking the same bus again

        queue<pair<int,int>> bfsQueue;  
        bfsQueue.push({source, 0});
        visitedStops.insert(source);

        while (!bfsQueue.empty()) {
            auto currentPair = bfsQueue.front();
            bfsQueue.pop();

            int currentStop = currentPair.first;
            int busesTaken = currentPair.second;

            if (currentStop == target) {
                return busesTaken; // reached destination
            }

            // For each bus route going through this stop
            for (int routeIdx : stopToRoutesMap[currentStop]) {
                if (routeUsed[routeIdx]) {
                    continue;
                }

                
                for (int stopOnRoute : routes[routeIdx]) {
                    if (visitedStops.find(stopOnRoute) == visitedStops.end()) {
                        visitedStops.insert(stopOnRoute);
                        bfsQueue.push({stopOnRoute, busesTaken + 1});
                    }
                }

                routeUsed[routeIdx] = true;
            }
        }

        // If queue empties and target isn’t found, return -1
        return -1;
    }
};
