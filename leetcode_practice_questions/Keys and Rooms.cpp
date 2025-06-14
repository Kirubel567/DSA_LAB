#include<iostream> 
#include<vector> 
#include<queue>
#include<unordered_set>
using namespace std; 

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> unlockedRooms;
        queue<int> roomsToCheck;
        roomsToCheck.push(0);

        while (!roomsToCheck.empty()) {
            int currentRoom = roomsToCheck.front();
            roomsToCheck.pop();

            unlockedRooms.insert(currentRoom);

            for (int key : rooms[currentRoom]) {
                if (unlockedRooms.find(key) == unlockedRooms.end()) {
                    roomsToCheck.push(key);
                }
            }
        }

        return unlockedRooms.size() == rooms.size();
    }
};
