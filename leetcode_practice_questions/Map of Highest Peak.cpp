#include<iostream> 
#include<vector> 
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size();
        int cols = isWater[0].size();

        // Directions to move
        int directions[5] = {0, 1, 0, -1, 0};

        //Initialize result matrix with -1
        vector<vector<int>> heights(rows, vector<int>(cols, -1));
        queue<int> toProcess;

        // First, put all water cells into the queue with height 0
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (isWater[i][j] == 1) {
                    heights[i][j] = 0;
                    toProcess.push((i << 10) | j);
                }
            }
        }

        int currentHeight = 0;

        // Now, run BFS layer by layer
        while (!toProcess.empty()) {
            int count = toProcess.size();

            for (int k = 0; k < count; ++k) {
                int pos = toProcess.front();
                toProcess.pop();

                int r = pos >> 10;// row
                int c = pos & ((1 << 10) - 1);// col

                // Explore neighbors in all four directions
                for (int d = 0; d < 4; ++d) {
                    int nr = r + directions[d];
                    int nc = c + directions[d + 1];

                    // Skip cells
                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                        continue;

                    if (heights[nr][nc] == -1) {
                        heights[nr][nc] = currentHeight + 1;
                        toProcess.push((nr << 10) | nc);
                    }
                }
            }

            //Increase height after processing layer
            ++currentHeight;
        }

        return heights;
    }
};
