#include<iostream> 
#include<vector> 
#include<queue>
#include<unordered_set>
#include<numeric> 
#include<algorithm> 
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int timeElapsed = 0;
        int freshCount = 0;
        queue<pair<int,int>> rottenQueue;

        // Count fresh oranges and enqueue all rotten oranges initially
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == 1) {
                    freshCount++;
                } else if (grid[row][col] == 2) {
                    rottenQueue.push({row, col});
                }
            }
        }

        // Directions for adjacent cells (up, down, left, right)
        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        // Process rotting spread in BFS manner
        while (!rottenQueue.empty() && freshCount > 0) {
            int currentLevelSize = rottenQueue.size();
            bool hasNewRotten = false;

            for (int i = 0; i < currentLevelSize; ++i) {
                auto [r, c] = rottenQueue.front();
                rottenQueue.pop();

                for (auto& dir : directions) {
                    int newRow = r + dir.first;
                    int newCol = c + dir.second;

                    // Check bounds and if orange is fresh
                    if (newRow >= 0 && newRow < grid.size() &&
                        newCol >= 0 && newCol < grid[0].size() &&
                        grid[newRow][newCol] == 1) {

                        // Mark this orange as rotten
                        grid[newRow][newCol] = 2;
                        rottenQueue.push({newRow, newCol});
                        freshCount--;
                        hasNewRotten = true;
                    }
                }
            }

            // Increment time only if some fresh orange turned rotten this round
            if (hasNewRotten) {
                timeElapsed++;
            }
        }

        // If there are still fresh oranges, return -1, else return elapsed time
        return freshCount == 0 ? timeElapsed : -1;
    }
};
