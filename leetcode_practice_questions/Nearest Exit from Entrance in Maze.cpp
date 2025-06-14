#include<iostream> 
#include<vector> 
#include<queue>
#include<unordered_set>
using namespace std;

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();

        // A grid to track visited cells
        vector<vector<bool>> canVisit(rows, vector<bool>(cols, true));

        queue<pair<int, int>> q;
        int steps = 0;

        // Start BFS from entrance
        int startX = entrance[0];
        int startY = entrance[1];

        q.push({startX, startY});
        canVisit[startX][startY] = false;  //Mark visited not to come back

        // Directions
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            int nodesAtCurrentStep = q.size();
            steps++;  // We are moving one step further away from entrance

            
            for (int i = 0; i < nodesAtCurrentStep; i++) {
                auto [x, y] = q.front();
                q.pop();

                // Check all 4 adjacent cells
                for (int dir = 0; dir < 4; dir++) {
                    int newX = x + dx[dir];
                    int newY = y + dy[dir];

                    // Make sure new position is inside maze boundaries
                    if (newX >= 0 && newX < rows && newY >= 0 && newY < cols &&
                        maze[newX][newY] == '.' && canVisit[newX][newY]) {

                        // If this cell is on the border, it's an exit — return steps taken so far
                        if (newX == 0 || newX == rows - 1 || newY == 0 || newY == cols - 1) {
                            return steps;
                        }

                        // Otherwise, mark it visited and add to queue for next exploration
                        canVisit[newX][newY] = false;
                        q.push({newX, newY});
                    }
                }
            }
        }

        return -1;
    }
};
