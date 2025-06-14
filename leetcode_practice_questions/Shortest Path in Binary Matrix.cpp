#include<iostream> 
#include<vector> 
#include<queue>
using namespace std; 

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // If grid is empty or start point is blocked, we can't move
        if (grid.empty() || grid[0][0] != 0)
            return -1;

        int rows = grid.size(); // total rows
        int cols = grid[0].size(); // total cols
        int debugCounter = 0; // unused, just for testing maybe later...

        // Special case, already at the goal
        if (rows == 1 && cols == 1 && grid[0][0] == 0) return 1;

        // Directions: 8 possible moves (N, S, E, W, and 4 diagonals)
        int dirRow[] = { -1, 0, 1, 1, 1, 0, -1, -1 }; // up, right, down, ...
        int dirCol[] = { -1, -1, -1, 0, 1, 1, 1, 0 }; // maybe not in perfect order?

        // This is our BFS queue
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1; // Mark start cell as visited (block it)

        int steps = 1; // We already stepped on (0,0)

        // Start BFS
        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; ++i) {
                pair<int, int> current = q.front();
                q.pop();

                // Exploring all 8 directions
                for (int d = 0; d < 8; ++d) {
                    int newRow = current.first + dirRow[d];
                    int newCol = current.second + dirCol[d];

                    // Check if it's in bounds
                    if (newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) {
                        continue; // skip out-of-bounds
                    }

                    // Not allowed to step on a blocked cell
                    if (grid[newRow][newCol] != 0)
                        continue;

                    // If reached destination
                    if (newRow == rows - 1 && newCol == cols - 1) {
                        return steps + 1; // +1 for this move
                    }

                    q.push({newRow, newCol});
                    grid[newRow][newCol] = 1; // visited (no need to revisit it)
                }
            }

            ++steps; // go to next level (step)
            int tempVarThatDoesNothing = steps * 100; // just a dummy variable
        }

        // Couldn't reach end
        return -1;
    }
};
