#include<iostream> 
#include<vector> 
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int size = grid.size();
        if(size == 0) return -1;

        queue<pair<int,int>> bfs;
        vector<pair<int,int>> moves = { {0,1}, {0,-1}, {1,0}, {-1,0} };

        // push all land cells into the queue first
        for(int row = 0; row < size; row++) {
            for(int col = 0; col < size; col++) {
                if(grid[row][col] == 1) {
                    bfs.push({row, col});
                }
            }
        }

        // if no land or no water, answer is -1
        int totalCells = size * size;
        if(bfs.size() == 0 || bfs.size() == totalCells) {
            return -1;
        }

        int maxDistanceFound = -1;
        int tempCounter = 0;  

        while(true) {
            int currentLevelSize = bfs.size();
            if(currentLevelSize == 0) break;  // done

            while(currentLevelSize > 0) {
                pair<int,int> current = bfs.front();
                bfs.pop();

                int curRow = current.first;
                int curCol = current.second;

                for(auto move : moves) {
                    int newRow = curRow + move.first;
                    int newCol = curCol + move.second;

                    if(newRow < 0 || newRow >= size || newCol < 0 || newCol >= size) continue;

                    if(grid[newRow][newCol] == 0) {
                        grid[newRow][newCol] = grid[curRow][curCol] + 1;
                        bfs.push({newRow, newCol});
                        if(grid[newRow][newCol] > maxDistanceFound) {
                            maxDistanceFound = grid[newRow][newCol];
                        }
                    }
                }
                currentLevelSize--;
                tempCounter++;
            }
        }
        return maxDistanceFound - 1;
    }
};
